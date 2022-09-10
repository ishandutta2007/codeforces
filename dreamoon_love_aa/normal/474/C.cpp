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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const double EPS=1e-12;
const double PI=acos(-1);
struct Point{
    LL x,y;
    Point(LL _x=0,LL _y=0){x=_x;y=_y;}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(const LL v){return Point(x*v,y*v);}
    LL operator*(const Point& b){return x*b.y-y*b.x;}
    LL operator^(const Point& b){return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }
    Point rotate(){return Point(-y,x);}
    double angle(){return atan2(y,x);}
    double dis(){return sqrt(x*x+y*y);}
    void scan(){cin>>x>>y;}
    void print(){cout<<x<<" "<<y<<endl;}
}O[4],p[4][4];
LL sqr(LL x){return x*x;}
bool valid(Point X,Point Y,Point Z,Point W){
    Point pp[4]={X,Y,Z,W};
    int xx=0,yy=0;
    REP(i,4){
        pp[i].x<<=2;
        pp[i].y<<=2;
        xx+=pp[i].x;
        yy+=pp[i].y;
    }
    xx>>=2;
    yy>>=2;
    REP(i,4){
        pp[i]=pp[i]-Point(xx,yy);
    }
    bool suc=true;
    LL dis=sqr(pp[0].x)+sqr(pp[0].y);
    if(!dis)suc=false;
    REP(i,4){
        if(dis!=sqr(pp[i].x)+sqr(pp[i].y))suc=false;
        REP(j,4){
            if((j^i)%2==0){
                if((pp[i]*pp[j]))suc=false;
            }
            else{
                if((pp[i]^pp[j]))suc=false;
            }
        }
    }
    return suc;
}
int main(){
    CASET{
        REP(i,4){
            p[i][0].scan();
            O[i].scan();
            REPP(j,1,4){
                p[i][j]=(p[i][j-1]-O[i]).rotate()+O[i];
            }
        }
        int an=1000;
        REP(i,4)REP(j,4)REP(k,4)REP(r,4){
            if(valid(p[0][i],p[1][j],p[3][r],p[2][k])
             ||valid(p[0][i],p[1][j],p[2][k],p[3][r])
             ||valid(p[0][i],p[2][k],p[1][j],p[3][r])
             ||valid(p[0][i],p[2][k],p[3][r],p[1][j])
             ||valid(p[0][i],p[3][r],p[1][j],p[2][k])
             ||valid(p[0][i],p[3][r],p[2][k],p[1][j]))an=min(an,i+j+k+r);
        }
        if(an==1000)puts("-1");
        else printf("%d\n",an);
    }
    return 0;
}