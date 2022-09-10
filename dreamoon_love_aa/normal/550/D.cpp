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
// template end here
VPII e;
int main(){
    DRI(K);
    if(K==1){
        puts("YES\n2 1\n1 2\n");
    }
    else if(K%2==0)puts("NO");
    else{
        puts("YES");
        int n=(K+2)*2;
        printf("%d %d\n",n,n*K/2);
        REPP(i,1,K+2){
            if(i<=K-1){
                e.PB(MP(i,n/2));
                e.PB(MP(i+n/2,n));
            }
            REPP(j,i+1,K+2){
                if(i%2==1&&i+1==j&&i<=K-1)continue;
                e.PB(MP(i,j));
                e.PB(MP(i+n/2,j+n/2));
            }
        }
        e.PB(MP(K+2,(K+2)*2));
        REP(i,SZ(e))printf("%d %d\n",e[i].F,e[i].S);
    }
    return 0;
}