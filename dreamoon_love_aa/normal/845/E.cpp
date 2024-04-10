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
int x[SIZE],y[SIZE],n,m,k;
void update(int x,int& mi,int& ma){
    mi=min(mi,x);
    ma=max(ma,x);
}
bool valid(int d){
    VI xx;
    xx.PB(1);
    xx.PB(n);
    REP(i,k){
        xx.PB(x[i]+d+1);
        xx.PB(x[i]-d-1);
    }
    int mi_x=1e9,ma_x=0;
    REP(i,SZ(xx)){
        if(xx[i]<1||xx[i]>n)continue;
        VPII pp;
        REP(j,k){
            if(x[j]-d<=xx[i]&&x[j]+d>=xx[i])
                pp.PB(MP(y[j]-d,y[j]+d));
        }
        sort(ALL(pp));
        if(SZ(pp)==0||pp[0].F>1){
            update(xx[i],mi_x,ma_x);
        }
        else{
            int now=0;
            bool fail=0;
            REP(i,SZ(pp)){
                if(pp[i].F>now+1){
                    fail=1;
                    break;
                }
                now=max(now,pp[i].S);
            }
            if(now<m)fail=1;
            if(fail){
                update(xx[i],mi_x,ma_x);
            }
        }
    }
    //printf("%d:[%d,%d]\n",d,mi_x,ma_x);
    if(ma_x-mi_x+1>1+2*d)return 0;
    
    VI yy;
    yy.PB(1);
    yy.PB(m);
    REP(i,k)yy.PB(y[i]+d+1),yy.PB(y[i]-d-1);
    int mi_y=1e9,ma_y=0;
    REP(i,SZ(yy)){
        if(yy[i]<1||yy[i]>m)continue;
        VPII pp;
        REP(j,k){
            if(y[j]-d<=yy[i]&&y[j]+d>=yy[i])
                pp.PB(MP(x[j]-d,x[j]+d));
        }
        sort(ALL(pp));
        if(SZ(pp)==0||pp[0].F>1){
            update(yy[i],mi_y,ma_y);
        }
        else{
            int now=0;
            bool fail=0;
            REP(i,SZ(pp)){
                if(pp[i].F>now+1){
                    fail=1;
                    break;
                }
                now=max(now,pp[i].S);
            }
            if(now<n)fail=1;
            if(fail){
                update(yy[i],mi_y,ma_y);
            }
        }
    }
    if(ma_y-mi_y+1>1+2*d)return 0;

    return 1;
}
int main(){
    RIII(n,m,k);
    REP(i,k)RII(x[i],y[i]);
    int ll=0,rr=1e9;
    while(ll<rr){
        int mm=(ll+rr)/2;
        if(valid(mm)){
            rr=mm;
        }
        else ll=mm+1;
    }
    printf("%d\n",ll);
    return 0;
}