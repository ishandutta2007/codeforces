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
const int INF = 2147483647;
int a[SIZE];

int BIT[SIZE];
void ins(int x,int v){
    for(;x<SIZE;x+=x&-x)BIT[x]+=v;
}
int qq(int x){
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
const double EPS=1e-12;
const double PI=acos(-1);
struct Point{
    double x,y;
    Point(double _x=0,double _y=0){x=_x;y=_y;}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(const double v){return Point(x*v,y*v);}
    double operator*(const Point& b){return x*b.y-y*b.x;}
    double operator^(const Point& b){return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        if(fabs(x-b.x)<EPS){
            if(fabs(y-b.y)<EPS)return 0;
            return y<b.y;
        }
        return x<b.x;
    }
    Point rotate(double v){return Point(x*cos(v)-y*sin(v),x*sin(v)+y*cos(v));}
    double angle(){return atan2(y,x);}
    double dis(){return sqrt(x*x+y*y);}
    void scan(){scanf("%lf%lf",&x,&y);}
    void print(){printf("%.9f %.9f\n",x,y);}
};
struct SegTree{
    Point vv[SIZE<<2];
    int len[SIZE];
    int n;
    void build(int L,int R,int id){
        if(L==R){
            vv[id]=Point(len[L],0);
            return;
        }
        int mm=(L+R)>>1;
        build(L,mm,id<<1);
        build(mm+1,R,(id<<1)|1);
        vv[id]=vv[id*2]+(vv[id*2+1].rotate((qq(mm+1)-qq(L))/180.*PI));
    }
    void init(int _n){
        n=_n;
        REP(i,n){
            len[i+1]=1;
        }
        build(1,n,1);
    }
    int me,v;
    void _edit(int L,int R,int id){
        if(L==R){
            vv[id]=Point(len[L],0);
            return;
        }
        int mm=(L+R)>>1;
        if(me<=mm)_edit(L,mm,id<<1);
        else _edit(mm+1,R,(id<<1)|1);
        vv[id]=vv[id*2]+(vv[id*2+1].rotate((qq(mm+1)-qq(L))/180.*PI));
    }
    void edit(int _x){
        me=_x;
        _edit(1,n,1);
    }
}seg;

int main(){
    DRII(n,m);
    seg.init(n);
    while(m--){
        DRIII(x,y,z);
        if(x==1){
            seg.len[y]+=z;
        }
        else{
            ins(y,-z);
        }
        seg.edit(y);
        if(y!=1)seg.edit(y-1);
        seg.vv[1].rotate(qq(1)/180.*PI).print();
    }
    return 0;
}