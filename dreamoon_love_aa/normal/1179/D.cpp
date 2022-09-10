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
const int SIZE = 1e6+10;
const LL INF = 1e18;
LL an;
LL n;
LL dp[SIZE],son[SIZE];
VI e[SIZE];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
LL sqr(LL x){return x*x;}
LL C2(LL x){
    return x*(x-1)/2;
}
const double EPS=1e-9;
const double PI=acos(-1);
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b)const{return Point(x+b.x,y+b.y);}
    Point operator*(const double v){return Point(x*v,y*v);}
    double operator*(const Point& b){return x*b.y-y*b.x;}
    bool operator<(const Point& b)const{
        if(fabs(x-b.x)<EPS){
            if(fabs(y-b.y)<EPS)return 0;
            return y<b.y;
        }
        return x<b.x;
    }
};
Point XX(Point A,Point B,Point C,Point D){
    double v1=(C-A)*(B-A);
    double v2=(B-A)*(D-A);
    return C+(D-C)*(v1/(v1+v2));
}
struct data{
    Point lp; // the intersection wit last line
    LL slope; // slope
    LL h;     // the heigth of intersectio of this line with y-axis
    int id;   // 0: used for query, others: used for lines
    data(Point _lp=Point(),LL _slope=0,LL _h=0,int _id=0):lp(_lp),slope(_slope),h(_h),id(_id){}
    bool operator<(const data& b)const{
        if(id&&b.id){
            return slope>b.slope;
        }
        return lp.x<b.lp.x;
    }
};
struct ConvexLines{
    set<data>lines;
    double leftmost_x;
    int size(){
        return SZ(lines);
    }
    // the leftmost query of x is larger than v
    void init(double v){
        leftmost_x=v;
        lines.clear();
    }
    bool good(LL my_slope,LL my_h,set<data>::iterator it){
        if(it==lines.end())return 0;
        if(it->slope==my_slope)
            return my_h + EPS < it->h;
        return my_slope * it->lp.x + my_h < it->lp.y + EPS;
    }
    // add a line passing (0,my_h) with slope:my_slope
    void add_line(LL my_slope,LL my_h,int id){
        if(SZ(lines)==0){
            lines.insert(data(Point(leftmost_x,my_h+leftmost_x*my_slope),my_slope,my_h,id));
            return;
        }
        auto it=lines.lower_bound(data(0.,my_slope,0,id));
        if(it!=lines.end()&&!good(my_slope,my_h,it))
            return;
        if(it!=lines.end()&&it->slope==my_slope){
            lines.erase(it);
            it=lines.lower_bound(data(0.,my_slope,0,id));
        }
        auto it2=it;
        for(;it2!=lines.end()&&good(my_slope,my_h,next(it2));it2++);
        for(;it!=lines.begin()&&good(my_slope,my_h,prev(it));it--);
        Point my_lp;
        if(it==lines.begin()){
            my_lp=Point(leftmost_x,my_h+leftmost_x*my_slope);
        }
        else{
            it--;
            my_lp=XX(Point(0,my_h),Point(1,my_h+my_slope),it->lp,it->lp+Point(1,it->slope));
            it++;
        }
        lines.erase(it,it2);
        tie(it,ignore)=lines.insert(data(my_lp,my_slope,my_h,id));
        it++;
        if(it!=lines.end()){
            my_lp=XX(Point(0,my_h),Point(1,my_h+my_slope),it->lp,it->lp+Point(1,it->slope));
            data you=*it;
            you.lp=my_lp;
            lines.erase(it);
            lines.insert(you);
        }
    }
    // get line id for position x
    int get_line_id(double x){
        auto it=lines.lower_bound(data(Point(x)));
        it--;
        return it->id;
    }
};
void dfs(int x,int lt){
    son[x]=1;
    dp[x]=INF;
    for(int y:e[x]){
        if(y==lt)continue;
        dfs(y,x);
        son[x]+=son[y];
    }
    VPLL AA;
    for(int y:e[x]){
        if(y==lt)continue;
        dp[x]=min(dp[x],dp[y]+C2(son[x]-son[y]));
        AA.PB({son[y],y});
        mii(an,dp[y]+C2(n-son[y]));
    }
    if(SZ(AA)==0){
        dp[x]=0;
        return;
    }
    sort(ALL(AA));
    ConvexLines hull;
    hull.init(0);
    REP(i,SZ(AA)){
        int y=AA[i].S;
        if(i){
            int id=hull.get_line_id(AA[i].F);
            mii(an,C2(n-son[y]-son[id])+dp[id]+dp[y]);
        }
        LL v=-son[y]*(2LL*n-1)+sqr(son[y]);
        hull.add_line(2*son[y],v,y);
    }
}
int main(){
    an=1e18;
    R(n);
    REPP(i,1,n){
        int x,y;
        R(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1,1);
    W(n*(n-1LL)-an);
    return 0;
}