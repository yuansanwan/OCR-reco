/**********************************************
完成：by jingwei
文件名称：myImageBinary.h
文件说明：图像二值化类的定义
作者：
完成日期：2015-03-30
**********************************************
*/
#ifndef  MYIMAGEBINARY_H_
#define MYIMAGEBINARY_H_
#include<opencv2\opencv.hpp>
class CMyImageBinary{
public:
	
public:

	CMyImageBinary();
	~CMyImageBinary();
	//图像预处理
	//评估函数计算函数的清晰度
	double EvaluateAndPreprogress(const cv::Mat img,cv::Mat &gray);
	//选择阈值进行二值化
	void SelectBestThreshold(cv::Mat & imgSrc, cv::Mat & imgBinary, cv::vector<cv::vector<cv::Point> > &contours, double image_Fuzzy_Score,int & blockSize, int & constValue);
	//找连通域，画外接矩形
	int FindImageContours(cv::Mat & img, cv::vector<cv::Rect> & arrayBoundingRect,cv::vector<cv::vector<cv::Point> > &contours, int rowColLimit=15, int cmin=10, int heigthWidthThreshold=6,int flag=0);
	//二值图像评估
	int EvaluteBinaryImage(cv::vector<cv::Rect> &arrayRect, const int rows, const int cols);
	//寻找bounding的主体框的高度
	void CountTextRectHeight(cv::vector<cv::Rect> &countRect, int &textHeight,const int rows);
	//找到数组最大的两个数及索引
	void Find2Largest(cv::vector<int> &arrayRow, int length, int &plargest, int &psecond_largest);
	//多阈值方法
	void TryMoreThreshold(cv::Mat & src, cv::Mat & binary, cv::vector<cv::vector<cv::Point> > & contours, int lValue, int hValue, int interal,int scale,int &thr);
};
#endif
