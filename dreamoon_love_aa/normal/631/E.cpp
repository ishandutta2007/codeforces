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
int a[SIZE];
LL ma;
const long double EPS=1e-12;
const long double PI=acos(-1);
struct Point{
    long double x,y;
    Point(long double _x=0,long double _y=0){x=_x;y=_y;}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(const long double v){return Point(x*v,y*v);}
    long double operator*(const Point& b){return x*b.y-y*b.x;}
    long double operator^(const Point& b){return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        if(fabs(x-b.x)<EPS){
            if(fabs(y-b.y)<EPS)return 0;
            return y<b.y;
        }
        return x<b.x;
    }
    long double angle(){return atan2(y,x);}
    long double dis(){return sqrt(x*x+y*y);}
    Point rotate(long double v){return Point(x*cos(v)-y*sin(v),x*sin(v)+y*cos(v));}
    Point unit(){return (*this)*(1./dis());}
}stk[SIZE][2];
int from[SIZE];
int sn;
LL dp[SIZE];
Point XX(Point A,Point B,Point C,Point D){
    long double v1=(C-A)*(B-A);
    long double v2=(B-A)*(D-A);
    return C+(D-C)*(v1/(v1+v2));
}
LL get(int x,int y){
    return dp[y]-dp[x-1];
}
int main(){
    DRI(n);
    LL sum=0;
    LL base=0;
    REPP(i,1,n+1){RI(a[i]);sum+=a[i];base+=a[i]*(LL)i;dp[i]=a[i]+dp[i-1];}
    LL now=sum;
    sn=0;
    REPP(i,1,n){
        Point seg[2]={Point(0,now),Point(1,now+(n+1-i))};
        now-=a[i];
        while(sn>1){
            Point p1=XX(stk[sn-1][0],stk[sn-1][1],stk[sn-2][0],stk[sn-2][1]);
            Point p2=XX(stk[sn-1][0],stk[sn-1][1],seg[0],seg[1]);
            if(p2.x>=p1.x)sn--;
            else break;
        }
        stk[sn][0]=seg[0];
        stk[sn][1]=seg[1];
        from[sn]=i;
        sn++;
        int ll=0,rr=sn-1;
        while(ll<rr){
            int m1=(ll+rr)>>1;
            int m2=m1+1;
            LL v1=get(from[m1],i)-a[i+1]*(LL)(i+1-from[m1]);
            LL v2=get(from[m2],i)-a[i+1]*(LL)(i+1-from[m2]);
            if(v1<v2)ll=m2;
            else rr=m1;
        }
        ma=max(ma,get(from[ll],i)-a[i+1]*(LL)(i+1-from[ll]));
    }

    sn=0;
    now=0;
    for(int i=n;i>1;i--){
        Point seg[2]={Point(0,now),Point(1,now+i)};
        now+=a[i];
        while(sn>1){
            Point p1=XX(stk[sn-1][0],stk[sn-1][1],stk[sn-2][0],stk[sn-2][1]);
            Point p2=XX(stk[sn-1][0],stk[sn-1][1],seg[0],seg[1]);
            if(p2.x>=p1.x)sn--;
            else break;
        }
        stk[sn][0]=seg[0];
        stk[sn][1]=seg[1];
        from[sn]=i;
        sn++;
        int ll=0,rr=sn-1;
        while(ll<rr){
            int m1=(ll+rr)>>1;
            int m2=m1+1;
            LL v1=-get(i,from[m1])+a[i-1]*(LL)(from[m1]-i+1);
            LL v2=-get(i,from[m2])+a[i-1]*(LL)(from[m2]-i+1);
            if(v1<v2)ll=m2;
            else rr=m1;
        }
        ma=max(ma,-get(i,from[ll])+a[i-1]*(LL)(from[ll]-i+1));
    }
    cout<<base+ma;
    return 0;
}