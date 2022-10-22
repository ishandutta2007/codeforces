//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int t,n,m,k,a[3501],ans,now;
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>n>>m>>k;
		for(int i=1;i<=n;++i)
		{
			cin>>a[i];
		}
		k=min(m-1,k);
		m-=k+1;
		ans=0;
		for(int i=0;i<=k;++i)
		{
			now=INF;
			for(int j=0;j<=m;++j)
			{
				now=min(now,max(a[i+j+1],a[n-(k-i)-(m-j)]));
			}
			ans=max(now,ans);
		}
		cout<<ans<<endl;
	}
	return 0;
}