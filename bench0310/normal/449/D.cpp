#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int>> dp((1<<20),vector<int>(21,0));
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        dp[a][0]++;
    }
    const ll mod=1000000007;
    vector<ll> p(n+1,1);
    for(int i=1;i<=n;i++) p[i]=(p[i-1]*2)%mod;
    for(int i=(1<<20)-1;i>=0;i--)
    {
        for(int j=1;j<=20;j++)
        {
            dp[i][j]=dp[i][j-1];
            if((i&(1<<(j-1)))==0) dp[i][j]+=dp[i+(1<<(j-1))][j];
        }
    }
    ll res=0;
    for(int i=0;i<(1<<20);i++)
    {
        int c=__builtin_popcount(i);
        if(c&1) res=(res-p[dp[i][20]]+mod)%mod;
        else res=(res+p[dp[i][20]])%mod;
    }
    printf("%I64d\n",res);
    return 0;
}