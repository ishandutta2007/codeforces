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
LL dp[510][510],dp2[510][510];
int a[510];
void add(LL &x,LL v){
    x=(x+v)%MOD;
}
int main(){
    DRI(n);
    REP(i,n)
        RI(a[i]);
    REP(i,n)dp[i][i]=dp2[i][i]=1;
    REPP(i,1,n){
        for(int j=0;j+i<n;j++){
            int ll=j;
            int rr=j+i;
            dp[ll][rr]=dp2[ll+1][rr];
            REPP(k,ll,rr){
                if(a[ll]<a[k+1])add(dp2[ll][rr],dp[ll][k]*dp2[k+1][rr]);
            }
            add(dp2[ll][rr],dp[ll][rr]);
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}