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
const int INF = 1e9+7;
const int SIZE = 510;
int a[SIZE][SIZE];
int main(){
    DRII(n,m);
    REPP(i,1,n+1)REPP(j,1,m+1)a[i][j]=INF;
    DRII(k,q);
    REP(i,q){
        DRIII(x,y,t);
        a[x][y]=t;
    }
    int mi=INF;
    {
        int i=0;
        for(;;i++){
            if((1<<i+1)>=k){
                REPP(r,k,n+1)REPP(c,k,m+1){
                    mi=min(mi,max(max(a[r][c],a[r-k+(1<<i)][c]),max(a[r][c-k+(1<<i)],a[r-k+(1<<i)][c-k+(1<<i)])));
                }
                break;
            }
            for(int r=n;r>=(1<<i+1);r--)for(int c=m;c>=(1<<i+1);c--){
                a[r][c]=max(a[r][c],a[r-(1<<i)][c]);
                a[r][c]=max(a[r][c],a[r][c-(1<<i)]);
                a[r][c]=max(a[r][c],a[r-(1<<i)][c-(1<<i)]);
            }
        }
    }
    if(mi==INF)puts("-1");
    else printf("%d\n",mi);
    return 0;
}