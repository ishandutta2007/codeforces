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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 250;
const int MOD = 1e9 + 7;
int n;
struct Point
{
    LL x,y;
    Point(LL _x=0,LL _y=0):x(_x),y(_y){}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    LL operator^(const Point& b)const{return x*b.x+y*b.y;}
    LL operator*(const Point& b)const{return x*b.y-y*b.x;}
    void read(){scanf("%I64d%I64d",&x,&y);}
}p[SIZE+SIZE];
int ng(LL x){
    if(x>0)return 1;
    if(x<0)return -1;
    return 0;
}
bool XX(Point &A,Point& B,Point& C,Point& D){
    //strictly
    return ng((C-A)*(B-A))*ng((B-A)*(D-A))>0
        && ng((A-D)*(C-D))*ng((C-D)*(B-D))>0;
}
LL AREA;
void init(){
    REP(i,n)AREA+=p[i+1]*p[i];
    if(AREA<0)AREA=-AREA;
}
bool valid[SIZE][SIZE];
bool valid_edge(int x,int y){
    // x < y
    LL r1=p[x]*p[y],r2=p[y]*p[x];
    REPP(i,x,y){
        r1+=p[i+1]*p[i];
    }
    REPP(i,y,x+n){
        r2+=p[i+1]*p[i];
    }
    //printf("[%d,%d] : %lld %lld   %lld\n",x,y,r1,r2,AREA);
    if(abs(r1)>=AREA||abs(r2)>=AREA)return false;
    REP(i,n){
        if(i==x||i==y)continue;
        if(!((p[i]-p[x])*(p[y]-p[x]))){
            if(((p[i]-p[x])^(p[i]-p[y]))<=0)return false;
        }
    }
    REP(i,n){
        if(XX(p[x],p[y],p[i],p[i+1]))return false;
    }
    return true;
}
LL dp[SIZE][SIZE];
int main(){
    RI(n);
    REP(i,n){
        p[i].read();
        p[i+n]=p[i];
    }
    init();
    REP(i,n-1)valid[i][i+1]=valid[i+1][i]=true;
    valid[0][n-1]=valid[n-1][0]=true;
    REP(i,n)REPP(j,i+2,n){
        if(abs(i-j)!=n-1)valid[i][j]=valid[j][i]=valid_edge(i,j);
    }
    REP(i,n)dp[i][1]=1;
    REPP(dd,2,n){
        REP(i,n){
            int ll=i,rr=(i+dd)%n;
            if(!valid[ll][rr])continue;
            for(int k=1;k<dd;k++){
                if(!valid[ll][(ll+k)%n]||!valid[rr][(ll+k)%n]){
                    continue;
                }
                dp[i][dd]=(dp[i][dd]+dp[i][k]*dp[(i+k)%n][dd-k])%MOD;
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}