#include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    char s[200010];
    int f[200010];
    ll dp[200010];
    int main()
    {
    	int n,k;scanf("%d%d",&n,&k);
    	scanf("%s",s+1);f[n+1]=2*n+k;
    	for(int i=n;i>=1;i--) f[i]=s[i]=='1'?i:f[i+1];
    	for(int i=1;i<=n;i++)
    	{
    		dp[i]=dp[i-1]+i;
    		int q=f[max(1,i-k)];
    		if(q<=i+k)
    		{
    			dp[i]=min(dp[i],dp[max(1,q-k)-1]+q);
    		}
    	} 
    	printf("%lld\n",dp[n]);
    }