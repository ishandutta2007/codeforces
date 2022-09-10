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

const double EPS=1e-12;
const double PI=acos(-1);
struct Point{
    LL x,y;
    int id;
    Point(LL _x=0,LL _y=0,int _id=0){x=_x;y=_y;id=_id;}
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
        p[i].scan();
        p[i].id=i+1;
    }
    int x=0,y=1,z;
    for(z=2;;z++){
        if((p[x]-p[y])*(p[z]-p[y]))break;
    }
    REP(i,n){
        if(i==x||i==y||i==z)continue;
        if(abs((p[i]-p[x])*(p[i]-p[y]))
        + abs((p[i]-p[x])*(p[i]-p[z]))
        + abs((p[i]-p[z])*(p[i]-p[y]))
        == abs((p[z]-p[x])*(p[z]-p[y]))){
            if((p[i]-p[x])*(p[i]-p[y]))z=i;
            else if((p[i]-p[x])*(p[i]-p[z]))y=i;
            else x=i;
        }
    }
    printf("%d %d %d\n",p[x].id,p[y].id,p[z].id);
    return 0;
}