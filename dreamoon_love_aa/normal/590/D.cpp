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
const int SIZE = 75*152;
int dp[77][SIZE],q[155];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y||x==-1)x=y;
}
int main(){
    DRIII(n,K,s);
    REP(i,n)RI(q[i]);
    MS1(dp);
    s=min(s,SIZE-1);
    if(K*2<=n){
        dp[0][0]=0;
        int bb=1;
        REP(i,n){
            int nb=0;
            for(int j=min(i,K-1);j>=0;j--)REP(k,bb){
                if(dp[j][k]!=-1){
                    mii(dp[j+1][k+i-j],dp[j][k]+q[i]);
                    nb=max(nb,k+i-j);
                }
            }
            bb=nb+1;
        }
        int an=-1;
        REP(i,s+1)
            if(dp[K][i]!=-1)mii(an,dp[K][i]);
        printf("%d\n",an);
    }
    else{
        reverse(q,q+n);
        K=n-K;
        int sum=0;
        REP(i,n)sum+=q[i];
        if(!K)return 0*printf("%d\n",sum);
        dp[0][0]=0;
        int bb=1;
        REP(i,n){
            int nb=0;
            for(int j=min(i,K-1);j>=0;j--)REP(k,bb){
                if(dp[j][k]!=-1){
                    maa(dp[j+1][k+i-j],dp[j][k]+q[i]);
                    nb=max(nb,k+i-j);
                }
            }
            bb=nb+1;
        }
        int an=-1;
        REP(i,s+1){
            if(dp[K][i]!=-1)maa(an,dp[K][i]);
        }
        printf("%d\n",sum-an);
    }
    return 0;
}