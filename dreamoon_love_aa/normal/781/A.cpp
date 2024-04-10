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
int an[SIZE];
int used[SIZE],tt;
void dfs(int x,int lt){
    tt++;
    used[an[x]]=used[an[lt]]=tt;
    int now=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        while(used[now]==tt)now++;
        an[y]=now++;
    }
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs(y,x);
    }
}
int main(){
    DRI(n);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    int root=0;
    REPP(i,1,n+1){
        if(SZ(e[i])>SZ(e[root])){
            root=i;
        }
    }
    printf("%d\n",SZ(e[root])+1);
    an[root]=1;
    dfs(root,root);
    REPP(i,1,n+1)printf("%d ",an[i]);
    return 0;
}