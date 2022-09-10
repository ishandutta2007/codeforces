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
const int SIZE = 3001;
VI e[SIZE];
VPII qq[SIZE][SIZE];
int an[400000];
int it[SIZE];
int path[SIZE],in_path[SIZE];
int used[SIZE],tt;
void fil(int x){
    //printf("[%d]\n",x);
    used[x]=tt;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y]!=tt)fil(y);
    }
}
int ST;
void dfs(int pn,int x){
    path[pn]=x;
    REP(i,SZ(qq[ST][x])){
        if(qq[ST][x][i].F-1<=pn)an[qq[ST][x][i].S]=path[qq[ST][x][i].F-1];
    }
    in_path[x]=pn;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y]==tt)continue;
        if(in_path[y]!=-1){
            REPP(j,in_path[y],pn+1)fil(path[j]);
        }
        else{
            dfs(pn+1,y);
        }
    }
    used[x]=tt;
    in_path[x]=-1;
}
void solve(int st){
    ST=st;
    MS1(in_path);
    MS0(it);
    tt++;
    dfs(0,st);
}
int main(){
    DRIII(n,m,q);
    REP(i,m){
        DRII(x,y);
        e[x].PB(y);
    }
    REPP(i,1,n+1)sort(ALL(e[i]));
    MS1(an);
    REP(i,q){
        DRIII(s,t,k);
        qq[s][t].PB(MP(k,i));
    }
    REPP(i,1,n+1)solve(i);
    REP(i,q)printf("%d\n",an[i]);
    return 0;
}