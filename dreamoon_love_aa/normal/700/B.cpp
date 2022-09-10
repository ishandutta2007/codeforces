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
bool u[SIZE];
int r;
VI e[SIZE];
LL an;
int dfs(int x,int lt){
    int now=u[x];
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        now+=dfs(y,x);
    }
    while(now*2>r)now-=2,r-=2;
    an+=now;
    return now;
}
int main(){
    DRII(n,k);
    REP(i,k*2){DRI(x);u[x]=1;}
    r=k*2;
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1,1);
    cout<<an;
    return 0;
}