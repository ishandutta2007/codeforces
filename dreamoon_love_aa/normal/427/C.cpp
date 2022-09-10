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
int cost[SIZE];
PII mi[SIZE];
struct SCC{
    int n,used[SIZE],order[SIZE],gg[SIZE];
    vector<int>e[SIZE],ae[SIZE],ge[SIZE],emp;
    int id,gn;
    void init(int _n){
        n=_n;
        memset(used,0,sizeof(int)*n);
        REP(i,n){
            e[i]=ae[i]=ge[i]=emp;
        }
    }
    void add_edge(int x,int y){
        e[x].PB(y);
        ae[y].PB(x);
    }
    void dfs1(int x){
        if(used[x]==1)return;
        used[x]=1;
        REP(i,SZ(e[x])){
            int y=e[x][i];
            dfs1(y);
        }
        order[--id]=x;
    }
    void dfs2(int x){
        if(used[x]==2)return;
        gg[x]=gn;
        used[x]=2;
        REP(i,SZ(ae[x])){
            int y=ae[x][i];
            if(used[y]==2){
                if(gg[y]!=gg[x])ge[gg[y]].PB(gg[x]);
            }
            else dfs2(y);
        }
    }
    void make_scc(){
        gn=0;
        id=n;
        REP(i,n)
            dfs1(i);
        REP(i,n){
            if(used[order[i]]!=2){
                dfs2(order[i]);
                gn++;
            }
        }
        REP(i,n)mi[i]=MP(MOD,0);
        LL an1=0;
        REP(i,n){
            if(mi[gg[i]].F>cost[i]){
                mi[gg[i]]=MP(cost[i],1);
            }
            else if(mi[gg[i]].F==cost[i])mi[gg[i]].S++;
        }
        LL an2=1;
        REP(i,n){
            if(mi[i].S){
                an1+=mi[i].F;
                an2=an2*mi[i].S%MOD;
            }
        }
        printf("%I64d %I64d\n",an1,an2);
    }
}scc;
int main(){
    DRI(n);
    scc.init(n);
    REP(i,n)RI(cost[i]);
    DRI(m);
    REP(i,m){
        DRII(x,y);
        x--;y--;
        scc.add_edge(x,y);
    }
    scc.make_scc();
    return 0;
}