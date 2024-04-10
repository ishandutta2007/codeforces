#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
struct Point{
    double x,y;
    Point(double _x=0,double _y=0){x=_x;y=_y;}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(const double v){return Point(x*v,y*v);}
    double operator*(const Point& b){return x*b.y-y*b.x;}
    double operator^(const Point& b){return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{return x<b.x||(x==b.x&&y<b.y);}
    double dis(){return sqrt(x*x+y*y);}
    void scan(){scanf("%lf%lf",&x,&y);}
}A,B,C;
int main(){
    int i,j,k,n;
    A.scan();
    B.scan();
    C.scan();
    if(fabs((B-A)*(C-B))<1e-6)puts("TOWARDS");
    else if((B-A)*(C-B)<0)puts("RIGHT");
    else puts("LEFT");
    return 0;
}