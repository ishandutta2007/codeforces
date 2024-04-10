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
const int INF = 1e9+7;
const int SIZE = 1e6+10;
int a[SIZE],b[SIZE],p[SIZE];
int main(){
    DRIII(n,l,r);
    REPP(i,1,n+1)RI(a[i]);
    VPII pp;
    REPP(i,1,n+1){
        RI(p[i]);
        pp.PB(MP(p[i],i));
    }
    sort(ALL(pp));
    int now=-INF;
    REP(i,SZ(pp)){
        b[pp[i].S]=max(l,now+a[pp[i].S]+1);
        if(b[pp[i].S]>r)return 0*puts("-1");
        now=b[pp[i].S]-a[pp[i].S];
    }
    REPP(i,1,n+1)printf("%d%c",b[i]," \n"[i==n]);
    return 0;
}