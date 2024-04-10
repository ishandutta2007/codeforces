/*{{{*/
#include <bits/stdc++.h>
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
#define PB emplace_back
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
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1<<20;
const double EPS=1e-12;
const double PI=acos(-1);
const int AA = 2001;
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b)const{return Point(x+b.x,y+b.y);}
    Point operator*(const double v)const{return Point(x*v,y*v);}
    double operator*(const Point& b)const{return x*b.y-y*b.x;}
    double operator^(const Point& b)const{return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        return ((*this)^Point(AA,1)) < (b^Point(AA,1));
    }
    double angle()const{return atan2(y,x);}
    double dis()const{return sqrt(x*x+y*y);}
    Point rotate(double v)const{return Point(x*cos(v)-y*sin(v),x*sin(v)+y*cos(v));}
    Point unit(){return (*this)*(1./dis());}
    void scan(){R(x,y);}
    void print(){W(x,y);}
}seg[25000][2],input[25000][2];
int ng(double x){if(x>EPS)return 1;if(x<-EPS)return -1;return 0;} 
bool inter(Point A,Point B,Point C,Point D){ 
    if(max(A.x,B.x)+EPS<min(C.x,D.x))return 0; 
    if(max(C.x,D.x)+EPS<min(A.x,B.x))return 0; 
    if(max(A.y,B.y)+EPS<min(C.y,D.y))return 0; 
    if(max(C.y,D.y)+EPS<min(A.y,B.y))return 0; 
    if(ng((C-A)*(B-A))*ng((B-A)*(D-A))>=0 
     &&ng((A-C)*(D-C))*ng((D-C)*(B-C))>=0)return 1; 
    return 0; 
}
bool inter(int id1,int id2){
    return inter(seg[id1][0],seg[id1][1],seg[id2][0],seg[id2][1]);
}
Point XX(Point A, Point B, Point C, Point D) {
    double v1 = (C - A) * (B - A);
    double v2 = (B - A) * (D - A);
    return C + (D - C) * (v1 / (v1 + v2));
}
int pn;
int u[50000];
Point now;
struct cmp{
    bool operator() (int x, int y) const {
        double v1=XX(now,now+Point(-1,AA),seg[x][0],seg[x][1])^Point(-1,AA);
        double v2=XX(now,now+Point(-1,AA),seg[y][0],seg[y][1])^Point(-1,AA);
        if(fabs(v1-v2)<EPS)return x<y;
        return v1<v2;
    }
};
int n;
bool valid(){
    REP(i,n)u[i]=0;
    vector<pair<Point,int>>event;
    REP(i,n){
        event.PB(MP(seg[i][0],i));
        event.PB(MP(seg[i][1],i));
    }
    sort(ALL(event));
    set<int,cmp> pp;
    REP(i,SZ(event)){
        now=event[i].F;
        int seg_id=event[i].S;
        if(!u[seg_id]){
            auto it=pp.insert(seg_id).F;
            if(it!=pp.begin()&&inter(seg_id,*prev(it)))return 1;
            if(next(it)!=pp.end()&&inter(seg_id,*next(it)))return 1;
        }else{
            auto it=pp.find(seg_id);
            if(next(it)!=pp.end()&&it!=pp.begin()){
                if(inter(*next(it),*prev(it)))return 1;
            }
            pp.erase(it);
        }
        u[seg_id]^=1;
    }
    return 0;
}
int main(){
    R(n);
    REP(i,n){
        REP(j,2){
            input[i][j].scan();
        }
        double s;
        R(s);
        input[i][1]=input[i][1].unit()*s;
    }
    double ll=0,rr=1e12;
    REP(cs,75){
        double mm=(ll+rr)*0.5;
        REP(i,n){
            seg[i][0]=input[i][0];
            seg[i][1]=input[i][0]+input[i][1]*mm;
        }
        if(valid())rr=mm;
        else ll=mm;
    }
    if(ll>9e11)W("No show :(");
    else W((ll+rr)*0.5);
    return 0;
}