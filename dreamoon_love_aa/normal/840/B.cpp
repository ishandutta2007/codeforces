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
const int SIZE = 1e6+10;
VPII e[SIZE];
VI ans;
bool u[SIZE];
int d[SIZE];
int dfs(int x){
    if(u[x])return 0;
    u[x]=1;
    int v=0;
    if(d[x]==1)v=1;
    REP(i,SZ(e[x])){
        int y=e[x][i].F;
        int ret=dfs(y);
        if(ret)ans.PB(e[x][i].S);
        v^=ret;
    }
    //printf("[%d,%d]\n",x,v);
    return v;
}
int main(){
    DRII(n,m);
    int cnt[3]={};
    REP(i,n){
        RI(d[i]);
        if(d[i]!=-1)cnt[d[i]]++;
        else cnt[2]++;
    }
    if(cnt[1]%2==1){
        if(cnt[2]==0)
            return 0*puts("-1");
        REP(i,n){
            if(d[i]==-1){
                d[i]=1;
                break;
            }
        }
    }
    REP(i,m){
        DRII(x,y);x--;y--;
        e[x].PB(MP(y,i+1));
        e[y].PB(MP(x,i+1));
    }
    dfs(0);
    printf("%d\n",SZ(ans));
    sort(ALL(ans));
    REP(i,SZ(ans))printf("%d\n",ans[i]);
    return 0;
}