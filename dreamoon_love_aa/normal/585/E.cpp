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
const int SIZE = 1e7+1;
int p[SIZE],num[SIZE],dp[SIZE];
vector<int>pp;
LL two[500001];
LL an;
void prime_init(){
    for(int i=2;i<SIZE;i++){
        if(!p[i]){
            pp.PB(i);
            for(int j=i;j<SIZE;j+=i){
                if(!p[j])p[j]=i;
            }
        }
    }
}
void ADD(LL &x,LL v){
    x=(x+v)%MOD;
}
LL tmp_v;
void dfs(VI& fac,int x,int v,int ty){
    if(x==SZ(fac)){
        tmp_v+=num[v]*ty;
        return;
    }
    dfs(fac,x+1,v,ty);
    dfs(fac,x+1,v*fac[x],-ty);
}
int main(){
    prime_init();
    two[0]=1;
    REPP(i,1,500001){
        two[i]=two[i-1]<<1;
        if(two[i]>=MOD)two[i]-=MOD;
    }
    DRI(n);
    REP(i,n){
        DRI(x);
        num[x]++;
    }
    num[1]=n;
    REPP(i,2,SIZE){
        for(int j=i+i;j<SIZE;j+=i)num[i]+=num[j];
    }
    for(int i=SIZE-1;i>1;i--){
        LL v=0;
        for(int j=i+i;j<SIZE;j+=i){
            v-=dp[j];
            if(v<0)v+=MOD;
        }
        v+=(two[num[i]]-1);
        if(v>=MOD)v-=MOD;
        dp[i]=v;
        if(!v)continue;
        int me=i;
        vector<int>fac;
        while(me!=1){
            if(!SZ(fac)||fac.back()!=p[me])fac.PB(p[me]);
            me/=p[me];
        }
        tmp_v=0;
        dfs(fac,0,1,1);
        tmp_v%=MOD;
        if(tmp_v<0)tmp_v+=MOD;
        ADD(an,v*tmp_v);
    }
    cout<<an<<endl;
    return 0;
}