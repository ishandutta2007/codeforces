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
const int SIZE = 1e6+10;
// template end here
vector<int>e[SIZE];
vector<int>ev[SIZE];
// 1-based
int jump[18][SIZE],lv[SIZE];
int N;
void __init(int x,int lt){
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            lv[y]=lv[x]+1;
            __init(y,x);
        }
    }
}
int adv(int x,int v){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1)x=jump[i][x];
    }
    return x;
}
int lca(int x,int y){
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y]);
    else y=adv(y,lv[y]-lv[x]);
    if(x==y)return x;
    for(int i=17;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
void build(int root){
    __init(root,root);
    REPP(i,1,18){
        REPP(x,1,N+1)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
int dp[SIZE][2];
int cnt[SIZE];
void ADD(LL& x,LL v){
    x=(x+v)%MOD;
}
void dfs_final(int x,int lt){
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs_final(y,x);
        if(ev[x][i]){
            cnt[dp[y][2-ev[x][i]]]++;
        }
        dp[x][0]+=dp[y][0];
        dp[x][1]+=dp[y][1];
    }
}
int main(){
    RI(N);
    REPP(i,1,N){
        DRIII(x,y,ty);
        e[x].PB(y);
        if(!ty)ev[x].PB(0);
        else ev[x].PB(2);
        e[y].PB(x);
        if(!ty)ev[y].PB(0);
        else ev[y].PB(1);
    }
    build(1);
    DRI(M);
    int lt=1;
    REP(i,M){
        DRI(x);
        int z=lca(lt,x);
        dp[lt][0]++;
        dp[z][0]--;
        dp[x][1]++;
        dp[z][1]--;
        lt=x;
    }
    dfs_final(1,1);
    LL ans=0;
    LL now=1;
    REPP(i,1,SIZE){
        //if(cnt[i])printf("%d:%d\n",i,cnt[i]);
        ADD(ans,now*cnt[i]);
        now=(2*now+1)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}