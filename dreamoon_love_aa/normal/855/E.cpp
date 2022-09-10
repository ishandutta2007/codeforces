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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL dp[61][10][1024];
void pre(){
    dp[0][0][0]=1;
    REP(i,60){
        REP(j,10){
            REP(k,1024){
                REP(v,10){
                    dp[i+1][max(j,v)][k^(1<<v)]+=dp[i][j][k];
                }
            }
        }
    }
    REP(i,61){
        REP(j,9)REP(k,1024)dp[i][j+1][k]+=dp[i][j][k];
    }
}
LL solve(LL n,int b){
    if(n<=b)return 0;
    int d[62],dn=0;
    while(n){
        d[dn++]=n%b;
        n/=b;
    }
    LL res=0;
    REPP(head,1,d[dn-1])res+=dp[dn-1][b-1][1<<head];
    int now_xor=1<<d[dn-1];
    for(int i=dn-2;i>=0;i--){
        REPP(head,1,b){
            res+=dp[i][b-1][1<<head];
        }
        REP(j,d[i]){
            res+=dp[i][b-1][now_xor^(1<<j)];
        }
        now_xor^=1<<d[i];
    }
    if(!now_xor)res++;
    return res;
}
int main(){
    pre();
    DRI(Q);
    while(Q--){
        int b;
        LL l,r;
        scanf("%d%I64d%I64d",&b,&l,&r);
        l--;
        printf("%I64d\n",solve(r,b)-solve(l,b));
    }
    return 0;
}