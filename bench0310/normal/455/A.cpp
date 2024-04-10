#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int N=100000;
    vector<long long> v(N+1,0);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        v[t]++;
    }
    vector<long long> dp(N+1,0);
    for(int i=1;i<=N;i++) dp[i]=max(dp[i-1],(i>1?dp[i-2]:0)+v[i]*i);
    printf("%I64d\n",dp[N]);
    return 0;
}