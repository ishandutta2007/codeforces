#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
using namespace std;
const int SIZE = 1e5+5;
vector<int>e[SIZE];
int lv,cnt[SIZE],ma_lv;
long long dp[SIZE],dp2[SIZE];
void dfs(int x,int last){
    if(x!=1){
        cnt[lv]++;
        ma_lv=max(ma_lv,lv);
    }
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==last)continue;
        lv++;
        dfs(y,x);
        lv--;

    }
}
int main(){
    DRIII(m,k,p);
    REPP(i,1,m){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1,0);
    for(int i=ma_lv;i>0;i--){
        dp[i]=dp[i+1]+cnt[i];
        dp2[i]=dp2[i+1]+(long long)cnt[i]*(ma_lv-i);
    }
    int an=0;
    for(int i=ma_lv;i>0;i--){
        int ll=1,rr=i;
        while(ll<rr){
            int mm=(ll+rr)>>1;
            if(dp2[mm]-dp2[i]-(dp[mm]-dp[i])*(ma_lv-i)<=p)rr=mm;
            else ll=mm+1;
        }
        an=max(an,(int)(dp[ll]-dp[i+1]));
        if(ll>1){
            long long mul=i-ll+1;
            long long tmp=dp2[ll]-dp2[i]-(dp[ll]-dp[i])*(ma_lv-i);
            an=max(an,(int)((dp[ll]-dp[i+1])+(p-tmp)/mul));
        }
    }
    printf("%d\n",min(an,k));
    return 0;
}