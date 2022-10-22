//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int gcd,a,m,t,p[1000],cnt,x,ans;
void dfs(int now,int i)
{
	ans+=(m+a-1)/now-(a-1)/now;
	for(++i;i<=cnt;++i)
	{
		dfs(now*p[i]*(-1),i);
	}
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>t;
	while(t)
	{
		--t;
		cin>>a>>m;
		gcd=__gcd(a,m);
		a/=gcd;
		m/=gcd;
		cnt=0;
		x=m;
		ans=0;
		for(int i=2;i*i<=x;++i)
		{
			if(x%i==0)
			{
				p[++cnt]=i;
				while(x%i==0)
				{
					x/=i;
				}
			}
		}
		if(x>1)
		{
			p[++cnt]=x;
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}