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
int a[SIZE],b[SIZE],bn,cnt[SIZE];
LL dp[SIZE];
void ADD(LL &x,LL v){
    x=(x+v)%MOD;
}
int main(){
    DRI(N);
    LL L;
    cin>>L;
    DRI(K);
    REP(i,N){RI(a[i]);b[i]=a[i];}
    sort(b,b+N);
    bn=unique(b,b+N)-b;
    REP(i,N){
        a[i]=lower_bound(b,b+bn,a[i])-b+1;
        cnt[a[i]]++;
    }
    REPP(i,1,bn+1)dp[i]=1;
    LL an=0;
    REP(k,K){
        REP(j,N){
            if(k*N+j<L){
                if(j<L%N){
                    ADD(an,dp[a[j]]*((L/N+1-k)%MOD));
                }
                else{
                    ADD(an,dp[a[j]]*((L/N-k)%MOD));
                }
            }
        }
        for(int j=bn;j>0;j--){
            dp[j]=dp[j]*cnt[j]%MOD;
        }
        REPP(j,1,bn+1)dp[j]=(dp[j]+dp[j-1])%MOD;
    }
    cout<<an;
    return 0;
}