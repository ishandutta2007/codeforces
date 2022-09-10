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
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
const long double EPS=1e-9;
long double mx,my,f[2][3];
int n;
struct Point{
    long double x,y;
    Point(long double _x=0,long double _y=0):x(_x),y(_y){}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(long double v){return Point(x*v,y*v);}
    long double operator*(const Point& b){return x*b.y-y*b.x;}
    void scan(){
        double xx,yy;
        scanf("%lf%lf",&xx,&yy);
        x=xx;
        y=yy;
    }
    long double dis(){
        return x*x+y*y;
    }
    long double get(Point ha[]){
        long double an=0;
        REP(i,n){
            an+=(ha[i]-(*this)).dis();
        }
        return an;
    }
}p[100010],yo[100010];
long double area(Point A,Point B,Point C){
    return fabs((B-A)*(C-A));
}
int main(){
    RI(n);
    mx=my=0;
    REP(i,n){
        double x,y;
        scanf("%lf%lf",&x,&y);
        yo[i]=Point(x,y);
        mx+=x;
        my+=y;
        f[0][2]+=1;
        f[0][1]-=2*x;
        f[0][0]+=x*x;
        f[1][2]+=1;
        f[1][1]-=2*y;
        f[1][0]+=y*y;
    }
    Point pm(mx,my);
    pm=Point(pm.x/n,pm.y/n);
    DRI(m);
    REP(i,m)p[i].scan();
    p[m]=p[0];
    long double area1=0,area2=0;
    REP(i,m){
        area1+=area(pm,p[i],p[i+1]);
        area2+=p[i]*p[i+1];
    }
    area2=fabs(area2);
    if(fabs(area2-area1)<EPS||fabs(area2-area1)/max(area2,area1)<1e-9){
        long double an=pm.get(yo);
        printf("%.15f\n",(double)an);
    }
    else{
        double mmm=1e100;
        Point win;
        REP(i,m){
            long double ll=0,rr=10000;
            REP(k,100){
                long double mm1=ll*0.51+rr*0.49;
                long double mm2=ll*0.49+rr*0.51;
                Point p1=p[i]+(p[i+1]-p[i])*(mm1*1e-4);
                Point p2=p[i]+(p[i+1]-p[i])*(mm2*1e-4);
                long double v1=(p1-pm).dis();
                long double v2=(p2-pm).dis();
                if(v1<v2)rr=mm2;
                else ll=mm1;
            }
            Point now=p[i]+(p[i+1]-p[i])*((ll+rr)*5e-5);
            if((now-pm).dis()<mmm){
                mmm=(now-pm).dis();
                win=now;
            }
        }
        printf("%.15f\n",(double)win.get(yo));
    }
    return 0;
}