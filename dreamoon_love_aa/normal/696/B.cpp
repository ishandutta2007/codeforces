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
VI e[SIZE];
int an[SIZE],num[SIZE];
void dfs(int x){
    num[x]=1;
    REP(i,SZ(e[x])){
        dfs(e[x][i]);
        num[x]+=num[e[x][i]];
    }
}
void dfs2(int x,int from){
    if(x==1)an[x]=2;
    else{
        an[x]=an[from]+2+num[from]-1-num[x];
    }
    REP(i,SZ(e[x]))dfs2(e[x][i],x);
}
int main(){
    DRI(n);
    REPP(i,2,n+1){
        DRI(x);
        e[x].PB(i);
    }
    dfs(1);
    dfs2(1,1);
    REPP(i,1,n+1)printf("%.1f ",an[i]*0.5);
    return 0;
}