#include <bits/stdc++.h>

using namespace std;

const long long mod=1000000007;
const int N=1000005;
vector<int> v[N];
vector<int> c(N,0);
vector<vector<long long>> dp(N,vector<long long>(2,0));

long long fpow(long long b,long long e)
{
    long long res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

long long inv(long long a)
{
    return fpow(a,mod-2);
}

void solve(int a)
{
    dp[a][0]=1;
    for(int to:v[a]) solve(to);
    for(int to:v[a]) dp[a][0]=(dp[a][0]*(dp[to][0]+dp[to][1]))%mod;
    if(c[a]==0)
    {
        for(int to:v[a])
        {
            long long now=dp[a][0];
            now=(now*inv(dp[to][0]+dp[to][1]))%mod;
            now=(now*dp[to][1])%mod;
            dp[a][1]=(dp[a][1]+now)%mod;
        }
    }
    else
    {
        dp[a][1]=dp[a][0];
        dp[a][0]=0;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        p++;
        v[p].push_back(i);
    }
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    solve(1);
    printf("%I64d\n",dp[1][1]);
    return 0;
}