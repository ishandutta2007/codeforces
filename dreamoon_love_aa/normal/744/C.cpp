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
int ty[16],r[16],b[16],n;
int dp[1<<16][121];
int get_bit(int x,int v){return (x>>v)&1;}
int f(int x,int rr,int bb,int use){
    if(use<0)return -2*MOD;
    if(dp[x][use]!=-MOD)return dp[x][use];
    if(x==0)return -2*MOD;
    int res=-2*MOD;
    REP(i,n){
        if(get_bit(x,i)){
            int me_r=rr,me_b=bb;
            if(ty[i])me_b--;
            else me_r--;
            res=max(res,f(x^(1<<i),me_r,me_b,use-min(me_r,r[i]))+min(me_b,b[i]));
        }
    }
    return dp[x][use]=res;
}
int main(){
    RI(n);
    REP(i,1<<16)REP(j,121)dp[i][j]=-MOD;
    dp[0][0]=0;
    REP(i,16){
        char c[4];
        RS(c);
        if(c[0]=='R')ty[i]=0;
        else ty[i]=1;
        RII(r[i],b[i]);
    }
    int cnt[2]={};
    int sum[2]={};
    REP(i,n){
        cnt[ty[i]]++;
        sum[0]+=r[i];
        sum[1]+=b[i];
    }
    int an=MOD;
    REP(i,121){
        int ret=f((1<<n)-1,cnt[0],cnt[1],i);
        if(ret>=0){
            an=min(an,max(sum[0]-i,sum[1]-ret));
        }
    }
    printf("%d\n",an+n);
    return 0;
}