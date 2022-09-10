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
const int MOD = 1e9+7;
const int SIZE = 3e5+10;
vector<int>e[SIZE],ev[SIZE];
int jump[20][SIZE],lv[SIZE],n;
LL dis[SIZE];
void init(int x,int lt){
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            dis[y]=dis[x]+ev[x][i];
            lv[y]=lv[x]+1;
            init(y,x);
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
    for(int i=19;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
void build(){
    init(1,1);
    REPP(i,1,20){
        REPP(x,1,n+1)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
int num[SIZE],sum[SIZE],sum2[SIZE],all_sum[SIZE],all_sum2[SIZE];
void add(int &x,LL v){
    x=(x+v)%MOD;
}
void dfs0(int x,int lt){
    num[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs0(y,x);
        num[x]+=num[y];
        sum[x]=(sum[x]+sum[y]+(LL)num[y]*ev[x][i])%MOD;
        sum2[x]=(sum2[x]+sum2[y]+(LL)sum[y]*2*ev[x][i]+(LL)ev[x][i]*ev[x][i]%MOD*num[y])%MOD;
    }
}
void dfs1(int x,int lt,LL v1,LL v2){
    v1%=MOD;
    v2%=MOD;
    if(v1<0)v1+=MOD;
    if(v2<0)v2+=MOD;
    all_sum[x]=sum[x];
    all_sum2[x]=sum2[x];
    add(all_sum[x],v1);
    add(all_sum2[x],v2);
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs1(y,x,
                v1+(LL)(n-num[y])*ev[x][i]%MOD+sum[x]-sum[y]-(LL)num[y]*ev[x][i]%MOD,
                all_sum2[x]-sum2[y]-sum[y]*2LL*ev[x][i]%MOD-(LL)ev[x][i]*ev[x][i]%MOD*num[y]+(LL)(n-num[y])*ev[x][i]%MOD*ev[x][i]%MOD+2LL*ev[x][i]*(v1+sum[x]-sum[y]-(LL)num[y]*ev[x][i]%MOD)%MOD);
    }
}
int main(){
    RI(n);
    REPP(i,1,n){
        DRIII(x,y,v);
        e[x].PB(y);
        ev[x].PB(v);
        e[y].PB(x);
        ev[y].PB(v);
    }
    build();
    dfs0(1,1);
    dfs1(1,1,0,0);
    DRI(Q);
    while(Q--){
        DRII(u,v);
        int me=lca(u,v);
        int an=0;
        LL dd=dis[u]+dis[v]-2*dis[me];
        dd%=MOD;
        if(me!=v){
            an=-all_sum2[u]%MOD;
            add(an,(sum2[v]+dd*dd%MOD*num[v]%MOD+dd*2LL*sum[v]%MOD)*2);
        }
        else{
            an=all_sum2[u];
            add(an,(all_sum2[v]-sum2[v]+dd*dd%MOD*(n-num[v])%MOD+dd*2LL*(all_sum[v]-sum[v])%MOD)*-2);
        }
        if(an<0)an+=MOD;
        printf("%d\n",an);
    }
    return 0;
}