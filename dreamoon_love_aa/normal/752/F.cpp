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
int N,K;
VI e[SIZE];
int v[SIZE],center,st;
bool used[SIZE];
VI id;
int dfs(int x){
    used[x]=1;
    int num=v[x];
    if(v[x])id.PB(x);
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y])continue;
        num+=dfs(y);
    }
    if(num>=K&&!st){
        center=x;
        st=SZ(id);
    }
    return num;
}
int main(){
    RII(N,K);
    REPP(i,1,N){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    REP(i,2*K){
        DRI(x);
        v[x]=1;
    }
    dfs(1);
    printf("1\n%d\n",center);
    REP(i,K){
        printf("%d %d %d\n",id[(st+i)%(2*K)],id[(st+i+K)%(2*K)],center);
    }
    return 0;
}