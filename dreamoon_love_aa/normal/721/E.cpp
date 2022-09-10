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
const int SIZE = 1e5+10;
int l[SIZE],r[SIZE];
int ma[SIZE];
PII dp[SIZE];
int p,t;
int cal(int idx,int st){
    int ll=-1,rr=idx-1;
    while(ll<rr){
        int mm=(ll+rr+1)/2;
        if(l[mm]+p<=st-t)ll=mm;
        else rr=mm-1;
    }
    if(ll<0)return 0;
    int ret=0;
    if(st-t>=l[ll]&&st-t<=r[ll]){
        if(st-t<dp[ll].F)ret=dp[ll].S-1;
        else ret=dp[ll].S+(st-t-dp[ll].F)/p;
        if(ll)ret=max(ret,ma[ll-1]);
    }
    if(st-t>=r[ll])ret=max(ret,ma[ll]);
    return ret;
}
int main(){
    DRII(L,n);
    if(!n)return 0*puts("0");
    RII(p,t);
    REP(i,n)RII(l[i],r[i]);
    dp[0]=MP(l[0],0);
    ma[0]=(r[0]-l[0])/p;
    REPP(i,1,n){
        int base=cal(i,l[i]);
        int ll=1,rr=min(r[i]-l[i]+1,p);
        while(ll<rr){
            int mm=(ll+rr)/2;
            if(cal(i,l[i]+mm)==base)ll=mm+1;
            else rr=mm;
        }
        if(ll==min(p,r[i]-l[i]+1))ll=0;
        dp[i]=MP(l[i]+ll,cal(i,l[i]+ll));
        ma[i]=max(ma[i-1],dp[i].S+(r[i]-dp[i].F)/p);
    }
    printf("%d\n",ma[n-1]);
    return 0;
}