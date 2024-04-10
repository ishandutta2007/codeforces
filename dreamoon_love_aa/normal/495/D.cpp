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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
char s[SIZE],t[SIZE];
int same[SIZE];
bool suc[SIZE];
LL dp[SIZE],dp2[SIZE];
int main(){
    RS(s);
    int n=LEN(s);
    RS(t);
    int m=LEN(t);
    strcat(t,s);
    int ll=0,rr=0;
    REPP(i,1,n+m){
        int st=0;
        if(i<rr){
            st=min(same[i-ll],rr-i);
        }
        while(i+st<n+m&&t[st]==t[i+st])st++;
        same[i]=st;
        if(i+st>rr)ll=i,rr=i+st;
        if(i>=m&&same[i]>=m)suc[i-1]=1;
    }
    ll=SIZE;
    REP(i,n){
        if(i)dp[i]=dp[i-1];
        else dp[0]=1;
        if(suc[i])ll=i-m;
        if(ll<=i){
            if(ll<0)dp[i]=(dp[i]+1)%MOD;
            else dp[i]=(dp[i]+dp2[ll]+1)%MOD;
        }
        if(i)dp2[i]=(dp[i]+dp2[i-1])%MOD;
        else dp2[i]=dp[i];
    }
    dp[n-1]--;
    if(dp[n-1]<0)dp[n-1]+=MOD;
    cout<<dp[n-1]<<endl;
    return 0;
}