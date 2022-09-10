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
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
template<class T, class... U> void DEBUG(const T &head, const U &... tail) { 
#ifdef HOME
    _W('#'); _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...);
#endif
}
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
const double EPS = 1e-12;
const double PI = acos(-1);
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b)const{return Point(x+b.x,y+b.y);}
    Point operator*(const double v)const{return Point(x*v,y*v);}
    double operator*(const Point& b)const{return x*b.y-y*b.x;}
    double operator^(const Point& b)const{return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        if(fabs(x-b.x)<EPS){
            if(fabs(y-b.y)<EPS)return 0;
            return y<b.y;
        }
        return x<b.x;
    }
    double angle()const{return atan2(y,x);}
    double dis()const{return sqrt(x*x+y*y);}
    Point rotate(double v)const{return Point(x*cos(v)-y*sin(v),x*sin(v)+y*cos(v));}
    Point unit(){return (*this)*(1./dis());}
    void scan(){R(x,y);}
    void print(){W(x,y);}
};
set<Point>point_set;
inline int fi (double a){
    if (a > EPS) return 1;
    else if (a >= -EPS) return 0;
    else return -1;
}
typedef pair<double, double> interval;
inline interval redi (interval a){
    if (fi(a.first) == -1) return MP(a.first + 2*PI, a.second + 2*PI);
    else return a;
}
struct circle{
    double x, y, r;
    circle (void) {}
    circle (double x0, double y0, double r0) : x(x0), y(y0), r(r0) {}
};
inline int judge (const circle& a, const circle& b){
    double dx = b.x - a.x, dy = b.y - a.y;
    double d = sqrt(dx * dx + dy * dy);
    if (fi(a.r + b.r - d) < 0) return 1;
    else if (fi(a.r + d - b.r) < 0) return 2;
    else if (fi(b.r + d - a.r) < 0) return 3;
    else return 0;
}
inline interval intersect (const circle& a, const circle& b){
    double dx = b.x - a.x, dy = b.y - a.y;
    double d = dx * dx + dy * dy;
    double ag = atan2(dy, dx);
    double tg = acos((a.r * a.r + d - b.r * b.r) / (2 * a.r * sqrt(d)));
    return redi(MP(ag - tg, ag + tg));
}
circle list[SIZE];
const int ending = -10010;
struct rec{
    double ang;
    int pwr;
    rec (void) {}
    rec (double a0, int p0) : ang(a0), pwr(p0){}
    bool operator < (const rec& a) const{
        if (fi(ang - a.ang)) return fi(ang - a.ang) == -1;
        else return pwr > a.pwr;
    }
} key[4*SIZE];
inline double cal (const circle& c, double a0, double a1){
    double da = a1 - a0;
    if (fi(da) == 0) return 0;
    double px0 = c.x + c.r * cos(a0);
    double py0 = c.y + c.r * sin(a0); 
    double px1 = c.x + c.r * cos(a1);
    double py1 = c.y + c.r * sin(a1);
    double s = c.r * c.r * (da - sin(da)) + (px0 * py1 - px1 * py0);
    return s;
}
int stat (int cnt,int n){
    int res=0;
    vector<double>gg;
    for (int i = 0; i < n; i++){
        if (i == cnt) continue;
        if (judge(list[cnt], list[i]) == 0){
            interval tt = intersect(list[cnt], list[i]);
            gg.PB(tt.F);
            if(fi(tt.S-2*PI)>=0)gg.PB(tt.S-2*PI);
            else gg.PB(tt.S);
        }
    }
    if(SZ(gg)==0)return -1;
    sort(ALL(gg));
    for(int i=0,j;i<SZ(gg);i=j){
        res++;
        for(j=i+1;j<SZ(gg)&&!fi(gg[j]-gg[i]);j++);
        point_set.insert(Point(list[cnt].x,list[cnt].y)+Point(cos(gg[i]),sin(gg[i]))*list[cnt].r);
    }
    return res;
}
int count(int n){
    int res=0;
    int single=0;
    REP(i,n){
        int v=stat(i,n);
        if(v==-1)single++;
        else res+=v;
    }
    if(single==n)return n+1;
    res+=2-SZ(point_set)+single;
    return res;
}
int main (){
    int n; R(n);
    int num=0;
    REP(i,n){
        int x,y,r;
        R(x,y,r);
        if(r)list[num++] = circle(x,y,r);
    }
    W(count(num));
    return 0;
}