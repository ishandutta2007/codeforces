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
const int SIZE = 2e5+10;
// template end here
VPII res;
vector<int> res2,e[SIZE];
int N,L,R;
int bfs[SIZE],sons[SIZE];
int used[SIZE],tt,tt2,father[SIZE];
int CC,PTR;
void dfs(int x,int lt,int o){
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x,o);
    }
    if(lt!=o&&x!=o){
        if(PTR!=x){
            res.PB(MP(CC,PTR));
            res2.PB(x);
            PTR=x;
        }
        res.PB(MP(x,lt));
        res2.PB(o);
    }
}
void go(int x,int lt){
    CC=x;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        PTR=y;
        dfs(y,x,y);
        if(PTR!=y){
            res.PB(MP(CC,PTR));
            res2.PB(y);
        }
    }
}
void build(int st){
    bfs[0]=st;
    tt2--;
    used[st]=tt2;
    int i=0,j=1;
    for(;i<j;i++){
        int x=bfs[i];
        sons[x]=1;
        REP(k,SZ(e[x])){
            int y=e[x][k];
            if(used[y]==tt||used[y]==tt2)continue;
            father[y]=x;
            used[y]=tt2;
            bfs[j++]=y;
        }
    }
    int num=j;
    for(i=j-1;i>=0;i--){
        int x=bfs[i];
        if(sons[x]*2>=num){
            if(sons[x]*2>num){;
                go(x,x);
                return;
            }
            else{
                int z=father[x];
                go(x,z);
                go(z,x);
                return;
            }
        }
        sons[father[x]]+=sons[x];
    }
}
void init(){
    tt++;
    build(1);
}
int main(){
    RI(N);
    REPP(i,1,N){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    init();
    printf("%d\n",SZ(res));
    REP(i,SZ(res))printf("%d %d %d\n",res[i].F,res[i].S,res2[i]);
    return 0;
}