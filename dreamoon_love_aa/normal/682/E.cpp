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
#define F x
#define S y
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const double EPS=1e-12;
const double PI=acos(-1);
struct Point{
    LL x,y;
    Point(LL _x=0,LL _y=0){x=_x;y=_y;}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b)const{return Point(x+b.x,y+b.y);}
    Point operator*(const LL v){return Point(x*v,y*v);}
    LL operator*(const Point& b)const{return x*b.y-y*b.x;}
    LL operator^(const Point& b)const{return x*b.x+y*b.y;}
    bool operator==(const Point& b)const{return x==b.x&&y==b.y;}
    bool operator<(const Point& b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }
    double angle(){return atan2(y,x);}
    double dis(){return sqrt(x*x+y*y);}
    void print(){cout<<x<<" "<<y<<endl;}
};
bool compare(const Point& X,const Point &Y){
    LL me=X*Y;
    if(!me){
        return abs(X.F)+abs(X.S)<abs(Y.F)+abs(Y.S);
    }
    return me>0;
}
Point tmp,stk[SIZE];
int sn;
LL solve(vector<Point>&p){
    if(SZ(p)<3){
        sn=0;
        REP(i,SZ(p))stk[sn++]=p[i];
        return 0;
    }
    REPP(i,1,SZ(p)){
        if(p[i]<p[0])swap(p[0],p[i]);
    }
    REPP(i,1,SZ(p)){
        p[i].F-=p[0].F;
        p[i].S-=p[0].S;
    }
    sort(p.begin()+1,p.end(),compare);
    tmp=p[0];
    p[0]=Point(0,0);
    sn=0;
    stk[sn++]=p[0];stk[sn++]=p[1];
    REPP(i,2,SZ(p)){
        while(sn>=2&&(stk[sn-1]-stk[sn-2])*(p[i]-stk[sn-1])<=0){
            sn--;
        }
        stk[sn++]=p[i];
    }
    LL res=0;
    REPP(i,2,sn)res+=stk[i-1]*stk[i];
    REP(i,sn)p[i]=stk[i]+tmp;
    p.resize(sn);
    return res;
}
LL area(const Point& X,const Point& Y,const Point& Z){
    return abs((X-Y)*(X-Z));
}
int main(){
    DRI(n);
    char s[24];
    RS(s);
    vector<Point>p;
    REP(i,n){
        DRII(x,y);
        p.PB(Point(x,y));
    }
    solve(p);
    int m=SZ(p);
    REP(i,m)p.PB(p[i]);
    LL ma=-1,id[3];
    REP(v1,m){
        int v3=v1+1;
        REPP(i,2,m){
            int v2=v1+i;
            while(v3+1<v2&&area(p[v1],p[v2],p[v3])<area(p[v1],p[v2],p[v3+1]))v3++;
            LL me=area(p[v1],p[v2],p[v3]);
            if(ma<me){
                ma=me;
                id[0]=v1,id[1]=v2,id[2]=v3;
            }
        }
    }
    REP(i,3){
        (p[id[i]]+p[id[(i+1)%3]]-p[id[(i+2)%3]]).print();
    }
    return 0;
}