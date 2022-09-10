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
const double EPS=1e-12;
const double PI=acos(-1);
int n;
LL AA;
struct Point{
    LL x,y;
    int id;
    Point(LL x=0,LL y=0,int id=-1):x(x),y(y),id(id){}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b)const{return Point(x+b.x,y+b.y);}
    Point operator*(const LL v)const{return Point(x*v,y*v);}
    LL operator*(const Point& b)const{return x*b.y-y*b.x;}
    LL operator^(const Point& b)const{return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        return y>b.y||(y==b.y&&x<b.x);
    }
    double angle()const{return atan2(y,x);}
    double dis()const{return sqrt(x*x+y*y);}
    void scan(){R(x,y);}
    void print(){W(x,y);}
}p[2000],p2[2000];
struct Line{
    LL a,b,c;
    int id1,id2;
    Line(){}
    Line(int _id1, int _id2):id1(_id1),id2(_id2){
        Point v=p[id2]-p[id1];
        a=v.y,b=-v.x,c=2*AA+p[id1].x*v.y-p[id1].y*v.x;
        if(MP(a,b)<MP(0LL,0LL)){
            a=-a;b=-b;c=-c;
        }
    }
    LL get(const Point& x){
        return a*x.x+b*x.y-c;
    }
    bool operator<(const Line& line2)const{
        return  Point(a,b)*Point(line2.a,line2.b)<0;
    }
}line[4000000];
int ln,pos[2000];
bool haha(int id1,int id2,Line& lin){
    if(lin.get(p[id1])<=lin.get(p[id2])){
        int x=pos[id1];
        int y=pos[id2];
        swap(p2[x],p2[y]);
        pos[id1]=y;
        pos[id2]=x;
        return 1;
    }
    return 0;
}
struct CHANGE{
    int id1,id2; //id1 > id2 -> id1 < id2
    CHANGE(){}
    CHANGE(int id1,int id2):id1(id1),id2(id2){}
    bool operator<(const CHANGE& b)const{
        Point v1=p[id1]-p[id2];
        Point v2=p[b.id1]-p[b.id2];
        return v1*v2<0;
    }
}over[2000000];
int over_n;
int main(){
    R(n,AA);
    REP(i,n){
        p[i].scan();
        p2[i]=p[i];
        p2[i].id=i;
    }
    REP(i,n)REP(j,n){
        if(i==j)continue;
        line[ln++]=Line(i,j);
    }
    sort(line,line+ln);
    sort(p2,p2+n);
    REP(i,n){
        pos[p2[i].id]=i;
    }
    REP(i,n){
        REPP(j,i+1,n){
            if(p[i]<p[j]){
                  over[over_n++]=CHANGE(i,j);
            }
            else{
                  over[over_n++]=CHANGE(j,i);
            }
        }
    }
    sort(over,over+over_n);
    int over_it=0;
    REP(i,ln){
        while(over_it<over_n&&haha(over[over_it].id1,over[over_it].id2,line[i]))over_it++;
        int ll=0,rr=n-1;
        while(ll<=rr){
            int mm=(ll+rr)/2;
            LL v=line[i].get(p2[mm]);
            if(v==0){
                W("Yes");
                p[line[i].id1].print();
                p[line[i].id2].print();
                p2[mm].print();
                return 0;
            }
            else if(v<0){
                rr=mm-1;
            }
            else{
                ll=mm+1;
            }
        }
    }
    W("No");
    return 0;
}