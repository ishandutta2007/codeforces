//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[3005],dp[2][3005],ans=INF;
struct L{
	int v,p;
	bool operator < (const L &TMP)const
	{
		return v==TMP.v?p<TMP.p:v<TMP.v;
	}
}s[3005];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		a[i]-=i;
		s[i]=(L){a[i],i};
	}
	sort(s+1,s+1+n);
	for(int i=1;i<=n;++i)
	{
		int now=INF;
		for(int j=1;j<=n;++j)
		{
			now=min(now,dp[(i&1)^1][j]);
			dp[i&1][j]=now+abs(a[i]-s[j].v);
		}
	}
	for(int i=1;i<=n;++i)
	{
		ans=min(dp[n&1][i],ans);
	}
	cout<<ans<<endl;
	return 0;
}