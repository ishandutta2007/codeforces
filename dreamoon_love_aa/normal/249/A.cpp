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
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X))
#define MS1(X) memset((X), -1, sizeof((X))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
struct Point{
    long double x,y;
    Point(long double _x=0,long double _y=0){x=_x;y=_y;}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(const long double v){return Point(x*v,y*v);}
    long double operator*(const Point& b){return x*b.y-y*b.x;}
    long double operator^(const Point& b){return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{return x<b.x||(x==b.x&&y<b.y);}
    long double dis(){return sqrt(x*x+y*y);}
};
int main(){
    int i,j,k,n;
    DRIII(y1,y2,yw);
    DRIII(xb,yb,r);
    y1=(yw-r)*2-y1;
    y2=(yw-r)*2-y2;
    long double mm;
    mm=y1-r-1e-9;
    Point A(-xb,y2-yb);
    Point B(-xb,mm-yb);
    long double res=xb-1.*(yw-r-yb)*xb/(mm-yb);
    if(fabs(A*B)/B.dis()+1e-8<r||mm<yw-r)puts("-1");
    else{
        
        printf("%.15lf\n",(double)res);
    }
    return 0;
}