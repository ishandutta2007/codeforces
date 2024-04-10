/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e4+10;
const double EPS=1e-12;
const double PI=acos(-1);
struct PointD{
    double x,y;
    PointD(double x=0,double y=0):x(x),y(y){}
    PointD operator-(const PointD& b)const{return PointD(x-b.x,y-b.y);}
    PointD operator+(const PointD& b)const{return PointD(x+b.x,y+b.y);}
    PointD operator*(const double v)const{return PointD(x*v,y*v);}
    double operator*(const PointD& b)const{return x*b.y-y*b.x;}
    double operator^(const PointD& b)const{return x*b.x+y*b.y;}
    bool operator<(const PointD& b)const{
        if(fabs(x-b.x)<EPS){
            if(fabs(y-b.y)<EPS)return 0;
            return y<b.y;
        }
        return x<b.x;
    }
    double angle()const{return atan2(y,x);}
    double dis()const{return sqrt(x*x+y*y);}
    PointD rotate(double v)const{return PointD(x*cos(v)-y*sin(v),x*sin(v)+y*cos(v));}
    PointD unit(){return (*this)*(1./dis());}
    void scan(){R(x,y);}
    void print(){W(x,y);}
}lineD[SIZE][2];
PointD XX(PointD A,PointD B,PointD C,PointD D){
    double v1=(C-A)*(B-A);
    double v2=(B-A)*(D-A);
    return C+(D-C)*(v1/(v1+v2));
}

struct Point{
    LL x,y;
    Point(LL x=0,LL y=0):x(x),y(y){}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b)const{return Point(x+b.x,y+b.y);}
    Point operator*(const LL v)const{return Point(x*v,y*v);}
    LL operator*(const Point& b)const{return x*b.y-y*b.x;}
    LL operator^(const Point& b)const{return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }
    double angle()const{return atan2(y,x);}
    double dis()const{return sqrt(x*x+y*y);}
    void scan(){R(x,y);}
    void print(){W(x,y);}
}line[SIZE][2];
VPII gg;
const int INF = 1000000;
int main(){
    int n; R(n);
    int an=0;
    REP(i,n){
        REP(j,2){
            line[i][j].scan();
            lineD[i][j]=PointD(line[i][j].x,line[i][j].y);
        }
        Point v=line[i][1]-line[i][0];
        if(!v.x)an+=abs(v.y)+1;
        else if(!v.y)an+=abs(v.x)+1;
        else{
            an+=__gcd(abs(v.x),abs(v.y))+1;
        }
    }
    REP(i,n)REP(j,i){
        if((line[i][1]-line[i][0])*(line[j][1]-line[j][0])==0)continue;
        PointD x=XX(lineD[i][0],lineD[i][1],lineD[j][0],lineD[j][1]);
        Point y=Point(floor(x.x+0.5),floor(x.y+0.5));
        if(abs(y.x)>INF||abs(y.y)>INF)continue;
        if((line[i][0]-y)*(line[i][1]-line[i][0])==0
         &&(line[j][0]-y)*(line[j][1]-line[j][0])==0
         &&((line[i][0]-y)^(line[i][1]-y))<=0
         &&((line[j][0]-y)^(line[j][1]-y))<=0){
            gg.PB({y.x,y.y});
        }
    }
    sort(ALL(gg));
    for(int i=0,j;i<SZ(gg);i=j){
        for(j=i+1;j<SZ(gg)&&gg[j]==gg[i];j++);
        int num=2;
        while(num*(num-1)/2<j-i)num++;
        an-=num-1;
    }
    W(an);
    return 0;
}