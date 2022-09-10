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
int d[SIZE],h[SIZE],mi[SIZE];
int main(){
    DRII(n,m);
    REP(i,m){
        RII(d[i],h[i]);
        mi[i]=h[i];
    }
    int now=1e9;
    REP(i,m){
        if(i)now+=abs(d[i]-d[i-1]);
        now=mi[i]=min(h[i],now);
    }
    now=1e9;
    for(int i=m-1;i>=0;i--){
        if(i!=m-1)now+=abs(d[i]-d[i+1]);
        now=min(h[i],now);
        mi[i]=min(mi[i],now);
    }
    int an=0;
    REP(i,m){
        if(mi[i]<h[i]){
            puts("IMPOSSIBLE");
            return 0;
        }
        if(i)an=max(an,(h[i]+h[i-1]+d[i]-d[i-1])/2);
    }
    an=max(an,h[0]+d[0]-1);
    an=max(an,h[m-1]+n-d[m-1]);
    printf("%d\n",an);
    return 0;
}