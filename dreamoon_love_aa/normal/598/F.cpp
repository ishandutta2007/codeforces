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
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<20;
const LD EPS=1e-12;
const LD PI=acos(-1);
struct Point{
    LD x, y;
    Point(LD x = 0, LD y = 0) : x(x), y(y) { }
    Point operator - (const Point& b) const { return Point(x-b.x,y-b.y); }
    Point operator + (const Point& b) const { return Point(x+b.x,y+b.y); }
    Point operator * (const LD v) const { return Point(x*v,y*v); }
    LD operator * (const Point& b) const { return x * b.y - y * b.x; }
    LD operator ^ (const Point& b) const { return x * b.x + y * b.y; }
    bool operator < (const Point& b) const {
        if(fabs(x - b.x) < EPS) {
            if(fabs(y - b.y) < EPS) { return 0; }
            return y < b.y;
        }
        return x < b.x;
    }
    LD angle() const { return atan2(y,x); }
    LD dis() const {return sqrt(x * x + y * y); }
    Point rotate(LD v) const { return Point(x * cos(v) - y * sin(v), x * sin(v) + y * cos(v)); }
    Point unit(){ return (*this) * (1. / dis()); }
    void scan(){ scanf("%Lf%Lf", &x, &y); }
    void print(){ printf("%.12Lf %.12Lf\n", x, y); }
}p[SIZE],line[2];
int n,m;
int tt,in_line[SIZE];
int ng(LD x){ if(x > 0) { return 1; } if(x < 0) { return -1; } return 0; } 
bool inter(Point A, Point B, Point C, Point D) {
    if(max(A.x, B.x) < min(C.x, D.x)) { return 0; }
    if(max(C.x, D.x) < min(A.x, B.x)) { return 0; }
    if(max(A.y, B.y) < min(C.y, D.y)) { return 0; }
    if(max(C.y, D.y) < min(A.y, B.y)) { return 0; }
    return ng((C - A) * (B - A)) * ng((B - A) * (D - A)) >= 0 
    && ng((A - C) * (D - C)) * ng((D - C) * (B - C)) >= 0;
}
Point XX(Point A, Point B, Point C, Point D) {
    LD v1 = (C - A) * (B - A);
    LD v2 = (B - A) * (D - A);
    return C + (D - C) * (v1 / (v1 + v2));
}
bool neibour(int x, int y) {
    if(x==1&&y==n)return 1;
    if(x==n&&y==1)return 1;
    return abs(x-y)==1;
}
void solve_one_line() {
    Point u=(line[1]-line[0]).unit();
    tt++;
    vector<pair<LD,int>>AA;
    FOR(i,1,n){
        if(fabs((line[1]-line[0])*(p[i]-line[0]))<1e-14){
            in_line[i]=tt;
            AA.PB(MP((p[i]^u),i));
        }
    }
    in_line[0]=in_line[n];
    in_line[n+1]=in_line[1];
    FOR(i,1,n){
        if(in_line[i-1]!=tt&&in_line[i]!=tt){
            Point x=XX(line[0],line[1],p[i-1],p[i]);
            if(((x-p[i-1])^(x-p[i]))<0){
                AA.PB(MP((x^u),-1));
            }
        }
    }
    LD an=0;
    sort(ALL(AA));
    bool inside=0;
    for(int i=0,j;i<SZ(AA);i=j){
        if(AA[i].S==-1){
            if(!inside)an-=AA[i].F;
            else an+=AA[i].F;
            inside^=1;
            j=i+1;
        }else{
            int pid=AA[i].S;
            for(j=i+1;j<SZ(AA)&&AA[j].S!=-1&&neibour(AA[j].S,AA[j-1].S);j++);
            int qid=AA[j-1].S;
            if(j==i+1){
                if(ng((line[1]-line[0])*(p[pid+1]-line[0]))!=ng((line[1]-line[0])*(p[pid-1]-line[0]))){
                    if(!inside)an-=AA[i].F;
                    else an+=AA[i].F;
                    inside^=1;
                }
            }else{
                VI temp;
                for(int k=-1;k<=1;k+=2){
                    if(in_line[pid+k]!=tt){
                        temp.PB(pid+k);
                    }
                    if(in_line[qid+k]!=tt){
                        temp.PB(qid+k);
                    }
                }
                if(ng((line[1]-line[0])*(p[temp[1]]-line[0]))!=ng((line[1]-line[0])*(p[temp[0]]-line[0]))){
                    if(!inside)an-=AA[i].F;
                    else an+=AA[j-1].F;
                    inside^=1;
                } else{
                    if(!inside){
                        an+=AA[j-1].F-AA[i].F;
                    }
                }
            }
        }
    }
    printf("%.12Lf\n",an); 
}
void solve() {
    p[n]=p[0];
    p[n+1]=p[1];
    REP(i,m){
        REP(j,2)line[j].scan();
        solve_one_line();
    }
}
void input() {
    R(n,m);
    REP(i,n)p[i].scan();
}
int main(){
    input();
    solve();
    return 0;
}