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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const double EPS=1e-12;
const double PI=acos(-1);
struct Point{
    LL x,y;
    Point(LL _x=0,LL _y=0){x=_x;y=_y;}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(const LL v){return Point(x*v,y*v);}
    LL operator*(const Point& b){return x*b.y-y*b.x;}
    LL operator^(const Point& b){return x*b.x+y*b.y;}
    bool operator<(const Point& b)const{
        return x<b.x||(x==b.x&&y<b.y);
    }
    double angle(){return atan2(y,x);}
    double dis(){return sqrt(x*x+y*y);}
    void scan(){cin>>x>>y;}
    void print(){cout<<x<<" "<<y<<endl;}
}p[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        p[i].x=i;
        cin>>p[i].y;
    }
    bool pal=1;
    REPP(i,1,n){
        if((p[i]-p[i-1])*(p[i]-p[0])){
            pal=0;
            break;
        }
    }
    if(pal)return 0*puts("No");
    pal=1;
    REPP(i,2,n){
        if((p[i]-p[i-1])*(p[i]-p[1])){
            pal=0;
            break;
        }
    }
    if(pal)return 0*puts("Yes");
    REPP(i,1,n){
        int st2=-1;
        bool suc=1;
        REPP(j,1,n){
            if(i==j)continue;
            if((p[j]-p[i])*(p[j]-p[0])){
                if(st2==-1)st2=j;
                else{
                    if((p[i]-p[0])*(p[j]-p[st2])){
                        suc=0;
                        break;
                    }
                }
            }
        }
        if(suc)return 0*puts("Yes");
    }
    return 0*puts("No");
}