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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+10;
// template end here
int n,m;
int a[SIZE],b[SIZE],c[SIZE],d[SIZE];
struct Point{
    LL x,y;
    int id;
    Point(LL _x=0,LL _y=0,int _id=0):x(_x),y(_y),id(_id){}
    Point operator-(const Point& b){return Point(x-b.x,y-b.y);}
    Point operator+(const Point& b){return Point(x+b.x,y+b.y);}
    Point operator*(LL v)const{return Point(x*v,y*v);}
    LL operator*(const Point& b)const{return x*b.y-y*b.x;}
    LL operator^(const Point& b){return x*b.x+y*b.y;}
    LL dis2()const{return x*x+y*y;}
    bool operator<(const Point& b)const{
        LL v=(*this)*b;
        if(!v){
            return this->dis2()<b.dis2();
        }
        return v>0;
    }
}p[SIZE],p2[SIZE];
int main(){
    RII(n,m);
    DRII(xx,yy);
    REP(i,n){
        RII(a[i],b[i]);
        p2[i]=Point(a[i],b[i]);
    }
    sort(p2,p2+n);
    REP(i,m){
        RII(c[i],d[i]);
        p[i+1]=Point(c[i],d[i]);
    }
    sort(p+1,p+m+1);
    int now=2;
    while(now<=m&&p[1]*p[now]==0){
        p[1]=p[now++];
    }
    int rr=2;
    while(now<=m){
        while(rr>2&&(p[rr-2]-p[rr-1])*(p[now]-p[rr-1])>=0)rr--;
        p[rr++]=p[now++];
    }
    int ma_y=0;
    int it=-1;
    for(int i=1;i<rr;i++){
        if(p[i].y>ma_y){
            ma_y=p[i].y;
            it=i;
        }
    }
    rr=it+2;
    p[it+1]=Point(0,ma_y);
    int ma_x=0;
    it=-1;
    for(int i=rr-1;i>=1;i--){
        if(p[i].x>ma_x){
            ma_x=p[i].x;
            it=i;
        }
    }
    p[it-1]=Point(ma_x,0);
    now=it-1;
    bool suc=0;
    REP(i,n){
        Point me=p2[i];
        while(me*p[now]<0)now++;
        if(me*p[now]==0){
            if(me.dis2()>=p[now].dis2()){
                suc=1;
                break;
            }
        }
        else{
            if((me-p[now])*(me-p[now-1])>=0){
                suc=1;
                break;
            }
        }
    }
    if(suc)puts("Max");
    else puts("Min");
    return 0;
}