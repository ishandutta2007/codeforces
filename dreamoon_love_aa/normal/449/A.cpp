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
#define F first
#define S second
typedef long long LL;
using namespace std;
int main(){
    DRII(n,m);
    DRI(k);
    if(k>n-1+m-1)puts("-1");
    else{
        LL an=1;
        int now=1;
        while(now<=n){
            int v=n/now;
            int nxt=n/v;
            if(nxt-1<=k)an=max(an,(LL)v*(m/(k-(nxt-1)+1)));
            now=nxt+1;
        }
        now=1;
        while(now<=m){
            int v=m/now;
            int nxt=m/v;
            if(nxt-1<=k)an=max(an,(LL)v*(n/(k-(nxt-1)+1)));
            now=nxt+1;
        }
        cout<<an<<endl;
    }
    return 0;
}