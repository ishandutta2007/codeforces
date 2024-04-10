#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const double EPS=1e-12;
const double PI=acos(-1);
struct Point{
    double x,y;
    Point(double _x=0,double _y=0){x=_x;y=_y;}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(const double v){return Point(x*v,y*v);}
    double operator*(const Point& b){return x*b.y-y*b.x;}
    double operator^(const Point& b){return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        if(fabs(x-b.x)<EPS){
            if(fabs(y-b.y)<EPS)return 0;
            return y<b.y;
        }
        return x<b.x;
    }
    double angle(){return atan2(y,x);}
    double dis(){return sqrt(x*x+y*y);}
    void scan(){scanf("%lf%lf",&x,&y);}
    void print(){printf("%.9f %.9f\n",x,y);}
};
int main(){
    DRII(x1,y1);
    DRII(x2,y2);
    DRII(Vmax,t);
    DRII(Vx,Vy);
    DRII(Ux,Uy);
    Point target=Point(x2-x1,y2-y1);
    Point U(Ux,Uy);
    Point V(Vx,Vy);
    double ll=0,rr=1e18;
    REP(k,10000){
        double mm=(ll+rr)*0.5;
        double t1=min(mm,(double)t);
        double t2=max(0.,mm-t);
        Point need=target-(V*t1)-(U*t2);
        if(need.dis()<=Vmax*mm)rr=mm;
        else ll=mm;
    }
    printf("%.18f\n",(ll+rr)*0.5);
    return 0;
}