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
LL dp[SIZE][2];
int c[SIZE];
string s[SIZE][2];
int main(){
    DRI(n);
    REP(i,n)RI(c[i+1]);
    REPP(i,1,n+1){
        cin>>s[i][0];
        s[i][1]=s[i][0];
        for(int j=0;SZ(s[i][1])-j-1>j;j++)swap(s[i][1][j],s[i][1][SZ(s[i][1])-j-1]);
    }
    dp[1][0]=0;
    dp[1][1]=c[1];
    REPP(i,2,n+1){
        dp[i][0]=dp[i][1]=1e18;
        if(s[i-1][0]<=s[i][0])dp[i][0]=min(dp[i][0],dp[i-1][0]);
        if(s[i-1][1]<=s[i][0])dp[i][0]=min(dp[i][0],dp[i-1][1]);
        if(s[i-1][0]<=s[i][1])dp[i][1]=min(dp[i][1],dp[i-1][0]+c[i]);
        if(s[i-1][1]<=s[i][1])dp[i][1]=min(dp[i][1],dp[i-1][1]+c[i]);
    }
    LL an=min(dp[n][0],dp[n][1]);
    if(an>1e17)puts("-1");
    else cout<<an<<endl;
    return 0;
}