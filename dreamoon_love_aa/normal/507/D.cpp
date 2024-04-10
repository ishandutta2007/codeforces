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
int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL dp[1001][100],tmp[1001];
void add(LL &x,LL v){
    x=(x+v)%MOD;
}
int main(){
    DRIII(N,K,M);
    LL ten=1;
    MOD=M;
    dp[0][0]=1;
    REP(i,N){
        for(int j=(i<N-1)?0:1;j<10;j++){
            REP(k,K){
                add(dp[i+1][(k+ten*j)%K],dp[i][k]);
            }
        }
        tmp[i+1]=dp[i+1][0]-1;
        if(i+1==N)tmp[i+1]++;
        dp[i+1][0]=1;
        ten=ten*10%K;
    }
    LL mul=1,an=0;
    for(int i=N;i>0;i--){
        add(an,tmp[i]*mul);
        if(i==N)mul=mul*9%MOD;
        else mul=mul*10%MOD;
    }
    if(an<0)an+=MOD;
    cout<<an<<endl;
    return 0;
}