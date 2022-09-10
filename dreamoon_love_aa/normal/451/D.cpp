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
char s[1111111];
int dp[1111111][2];
int main(){
    RS(s+1);
    int n=LEN(s+1);
    if(n==1){
        puts("0 1");
    }
    else
    {
        dp[1][s[1]-'a']=1;
        dp[2][s[2]-'a']=1;
        REPP(i,3,n+1){
            REP(j,2)dp[i][j]=dp[i-2][j];
            dp[i][s[i]-'a']++;
        }
        LL an1=0,an2=n;
        REPP(i,1,n+1){
            if(i%2==n%2){
                an2+=dp[n][s[i]-'a']-dp[i][s[i]-'a'];
                an1+=dp[n-1][s[i]-'a']-dp[i-1][s[i]-'a'];
            }
            else{
                an1+=dp[n][s[i]-'a']-dp[i-1][s[i]-'a'];
                an2+=dp[n-1][s[i]-'a']-dp[i][s[i]-'a'];
            }
        }
        printf("%I64d %I64d\n",an1,an2);
    }
    return 0;
}