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
const int SIZE = 1e6+10;
int deg[SIZE],s[SIZE];
int main(){
    DRI(n);
    queue<int>qq;
    REP(i,n){
        RII(deg[i],s[i]);
        if(deg[i]==1)qq.push(i);
    }
    VPII res;
    while(SZ(qq)){
        int x=qq.front();qq.pop();
        if(deg[x]!=1)continue;
        res.PB(MP(x,s[x]));
        deg[s[x]]--;
        s[s[x]]^=x;
        if(deg[s[x]]==1)qq.push(s[x]);
    }
    printf("%d\n",SZ(res));
    REP(i,SZ(res))printf("%d %d\n",res[i].F,res[i].S);
    return 0;
}