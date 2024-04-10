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
const int SIZE = 5e5+10;
// 1-based
int N,M;
VI e[SIZE];
VI path[SIZE];
int jump[20][SIZE],lv[SIZE];
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
    for(int i=18;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
void build_LCA(int root){
    __init(root,root);
    REPP(i,1,19){
        REPP(x,1,N+1)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
int U[SIZE],V[SIZE],C[SIZE];
int ll[SIZE],rr[SIZE],node_n;
void dfs0(int x){
    ll[x]=rr[x]=++node_n;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        dfs0(y);
        rr[x]=rr[y];
    }
}

LL BIT[SIZE];
void ins(int x,LL v){
    for(;x;x-=x&-x)BIT[x]+=v;
}
LL qq(int x){
    if(!x)return 0;
    LL res=0;
    for(;x<SIZE;x+=x&-x)res+=BIT[x];
    return res;
}
void ins_node(int x,LL v){
    ins(ll[x]-1,-v);
    ins(rr[x],v);
}
LL dp[SIZE];
void dfs(int x){
    REP(i,SZ(e[x])){
        int y=e[x][i];
        dfs(y);
        dp[x]+=dp[y];
    }
    LL sum=dp[x];
    ins_node(x,sum);
    REP(i,SZ(path[x])){
        int id=path[x][i];
        int u=U[id];
        int v=V[id];
        int c=C[id];
        LL ret=qq(ll[u])+qq(ll[v])-sum+c;
        dp[x]=max(dp[x],ret);
    }
    ins_node(x,-dp[x]);
}
int main(){
    RII(N,M);
    REPP(i,2,N+1){
        DRI(x);
        e[x].PB(i);
    }
    build_LCA(1);
    dfs0(1);
    REP(i,M){
        RIII(U[i],V[i],C[i]);
        int z=lca(U[i],V[i]);
        path[z].PB(i);
    }
    dfs(1);
    printf("%d\n",dp[1]);
    return 0;
}