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
const int SIZE = 4e5+10;
struct Point{
    LL x,y;
    int id;
    Point(int _x=0,int _y=0):x(_x),y(_y),id(-1){}
    LL operator*(const Point& b)const{return x*b.y-y*b.x;}
    LL dis2(){
        return x*x+y*y;
    }
    Point operator-(const Point& b)const{
        return Point(x-b.x,y-b.y);
    }
    bool operator<(const Point& b)const{return MP(x,y)<MP(b.x,b.y);}
    void scan(){
        int _x,_y;
        R(_x,_y);
        x=_x;y=_y;
    }
    PLL get_pair(){
        return MP(x,y);
    }
}pA[SIZE],pB[SIZE],AA[SIZE];
int AAn;
bool point_cmp(Point X,Point Y){
    LL v1=X.x*Y.y,v2=X.y*Y.x;
    if (v1==v2)return abs(X.x)+abs(X.y)<abs(Y.x)+abs(Y.y);
    return v1>v2;
}
long double an[SIZE];

vector<Point>convex_hull(Point _p[],int N){
    REPP(i,1,N){
        if(_p[i].get_pair()<_p[0].get_pair()){
            swap(_p[0],_p[i]);
        }
    } 
    Point O=_p[0];
    REP(i,N){_p[i].x-=O.x;_p[i].y-=O.y;}
    sort(_p+1,_p+N,point_cmp);
    vector<Point>ret;
    ret.PB(_p[0]);
    REPP(i,1,N){
        while(SZ(ret)>1&&(ret.back()-ret[SZ(ret)-2])*(_p[i]-ret[SZ(ret)-2])<=0)ret.pop_back();
        ret.PB(_p[i]);
    }
    REP(i,SZ(ret)){ret[i].x+=O.x;ret[i].y+=O.y;}
    return ret;
}
bool is_line(Point _p[], int N){
    REPP(i,2,N){
        if((_p[i]-_p[0])*(_p[1]-_p[0]))return 0;
    }
    return 1;
}
bool equal_angle(int id1,int id2){
    if((AA[id1+1]-AA[id1]).dis2()!=(AA[id2+1]-AA[id2]).dis2())return 0;
    if((AA[id1+2]-AA[id1+1]).dis2()!=(AA[id2+2]-AA[id2+1]).dis2())return 0;
    if((AA[id1+2]-AA[id1+1])*(AA[id1]-AA[id1+1])!=(AA[id2+2]-AA[id2+1])*(AA[id2]-AA[id2+1]))return 0;
    return 1;
}
int same[SIZE];
int main(){
    int n,m; R(n,m);
    REP(i,n)pA[i].scan();
    REP(i,m)pB[i].scan();
    bool line[2]={is_line(pA,n),is_line(pB,m)};
    if(line[0]&&line[1]){
        sort(pA,pA+n);
        sort(pB,pB+m);
        W((pA[n-1]-pA[0]).dis2()==(pB[m-1]-pB[0]).dis2()?"YES":"NO");
    }
    else if(line[0]||line[1]){
        W("NO");
    }
    else{
        auto poly2=convex_hull(pB,m);
        auto poly1=convex_hull(pA,n);
        if(SZ(poly1)!=SZ(poly2)){
            W("NO");
            return 0;
        }
        REP(i,SZ(poly1)){
            AA[AAn++]=poly1[i];
        }
        REP(i,2){
            AA[AAn++]=poly1[i];
        }
        REP(i,SZ(poly2)){
            AA[AAn++]=poly2[i];
        }
        REP(i,SZ(poly2)){
            AA[AAn++]=poly2[i];
        }
        REP(i,2){
            AA[AAn++]=poly2[i];
        }
        int ll=0,rr=0;
        for(int i=1;i<=AAn-3;i++){
            int it=0;
            if(i<rr)it=max(rr-i,same[i-ll]);
            while(i+it<=AAn-3&&equal_angle(it,i+it))it++;
            same[i]=it;
            if(same[i]==SZ(poly1)&&i>=SZ(poly1)+2){
                W("YES");
                return 0;
            }
            if(i+it>rr){
                ll=i;
                rr=i+it;
            }
        }
        W("NO");
    }
    return 0;
}