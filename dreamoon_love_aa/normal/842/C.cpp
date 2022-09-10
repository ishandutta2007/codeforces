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
int my_gcd(int x,int y){
    if(!x||!y)return x+y;
    return __gcd(x,y);
}
VI e[SIZE];
int a[SIZE];
int an[SIZE];
set<PII>H[SIZE];
void dfs(int x,int lt,int v,int r){
    if(r<0)return;
    if(H[x].count(MP(v,r)))return;
    H[x].insert(MP(v,r));
    an[x]=max(an[x],v);
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x,v,r-1);
        dfs(y,x,my_gcd(v,a[y]),r);
    }
}
int main(){
    DRI(n);
    REPP(i,1,n+1)RI(a[i]);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1,1,a[1],1);
    dfs(1,1,0,0);
    an[1]=a[1];
    REPP(i,1,n+1)printf("%d%c",an[i]," \n"[i==n]);
    return 0;
}