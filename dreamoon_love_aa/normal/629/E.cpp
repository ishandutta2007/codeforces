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
int N;
vector<pair<int,int> >e[SIZE];
LL dp[SIZE][2],num[SIZE];
void dfs1(int x,int lt){
    num[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs1(y,x);
        num[x]+=num[y];
        dp[x][0]+=dp[y][0]+num[y];
    }
}
void dfs2(int x,int lt,LL v){
    dp[x][1]=dp[x][0]+v;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        if(y==lt)continue;
        dfs2(y,x,v+(dp[x][0]-dp[y][0]-num[y])+(N-num[y]));
    }
}
void add(int x,int y,int v){
    e[x].PB(MP(y,v));
    e[y].PB(MP(x,v));
}
// 1-based
int jump[20][SIZE],lv[SIZE];
void __init(int x,int lt){
    jump[0][x]=lt;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
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
    for(int i=19;i>=0;i--)
        if(jump[i][x]!=jump[i][y]){x=jump[i][x];y=jump[i][y];}
    return jump[0][x];
}
void build(int root){
    __init(root,root);
    REPP(i,1,20){
        REPP(x,1,N+1)
            jump[i][x]=jump[i-1][jump[i-1][x]];
    }
}
int main(){
    DRII(n,m);
    N=n;
    REPP(i,1,n){
        DRII(x,y);
        add(x,y,1);
    }
    build(1);
    dfs1(1,1);
    dfs2(1,1,0);
    while(m--){
        DRII(x,y);
        if(lv[x]>lv[y])swap(x,y);
        int z=lca(x,y);
        if(z!=x){
            printf("%.12f\n",lv[x]+lv[y]-lv[z]*2+(dp[x][0]*1./num[x])+dp[y][0]*1./num[y]+1);
        }
        else{
            int u=adv(y,lv[y]-lv[x]-1);
            printf("%.12f\n",lv[y]-lv[x]+(dp[y][0]*1./num[y])+(dp[x][1]-dp[u][0]-num[u])*1./(N-num[u])+1);
        }
    }
    return 0;
}