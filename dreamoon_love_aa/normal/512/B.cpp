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
const int MAX = 1e9+7;
const int SIZE = 1e6+10;
int c[SIZE],l[SIZE],n;
VPII d;
set<int>dp;
void dfs(int x){
    if(dp.count(x))return ;
    dp.insert(x);
    REP(i,n){
        int gg=__gcd(l[i],x);
        if(gg!=x)dfs(gg);
    }
}
int main(){
    RI(n);
    REP(i,n)RI(l[i]);
    REP(i,n)RI(c[i]);
    REP(i,n)dfs(l[i]);
    for(set<int>::iterator it=dp.begin();it!=dp.end();it++)d.PB(MP(*it,MAX));
    if(d[0].F==1){
        for(int i=SZ(d)-1;i>=0;i--){
            REP(j,n){
                if(l[j]==d[i].F)d[i].S=min(d[i].S,c[j]);
            }
            REP(j,n){
                int gg=__gcd(d[i].F,l[j]);
                int it=lower_bound(ALL(d),MP(gg,-1))-d.begin();
                d[it].S=min(d[it].S,c[j]+d[i].S);
            }

        }
        printf("%d\n",d[0].S);
    }
    else printf("-1\n");
    return 0;
}