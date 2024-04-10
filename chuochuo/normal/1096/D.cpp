#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
ll dp[MAXN][4];
//0: no
//1: h
//2: ha
//3: har
char str[MAXN];
void relax(ll &a,ll b) {a=min(a,b);}
int main()
{
    scanf("%lld",&n);
    scanf("%s",str+1);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=0;i<=n;i++) dp[i][0]=dp[i][1]=dp[i][2]=dp[i][3]=INF;
    dp[0][0]=0;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<4;j++)
        {
            if(dp[i][j]==INF) continue;
            relax(dp[i+1][j],dp[i][j]+a[i+1]);
            if(j==0)
            {
                if(str[i+1]=='h') relax(dp[i+1][j+1],dp[i][j]);
                else relax(dp[i+1][j],dp[i][j]);
            }
            else if(j==1)
            {
                if(str[i+1]=='a') relax(dp[i+1][j+1],dp[i][j]);
                else relax(dp[i+1][j],dp[i][j]);
            }
            else if(j==2)
            {
                if(str[i+1]=='r') relax(dp[i+1][j+1],dp[i][j]);
                else relax(dp[i+1][j],dp[i][j]);
            }
            else
            {
                if(str[i+1]!='d') relax(dp[i+1][j],dp[i][j]);
            }
        }
    }
    printf("%lld\n",min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3])));
    return 0;
}