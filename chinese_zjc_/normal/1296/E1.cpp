//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,ans[201];
string s;
bool d[201][201];
struct c{
	int v,p;
	bool operator < (const c tmp)const
	{
		return v==tmp.v?p<tmp.p:v<tmp.v;
	}
}c[201];
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>s;
	s=' '+s;
	for(int i=1;i<=n;++i)
	{
		c[i].v=s[i]-'a'+1;
		c[i].p=i;
		ans[i]=-1;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<n;++j)
		{
			if(c[j+1]<c[j])
			{
				d[c[j].p][c[j+1].p]=d[c[j+1].p][c[j].p]=true;
				swap(c[j],c[j+1]);
			}
		}
	}
	for(int t=1;t<=n;++t)
	{
		if(ans[t]==-1)
		{
			ans[t]=0;
		}
		for(int i=2;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(d[i][j]&&ans[j]!=-1)
				{
					ans[i]=!ans[j];
				}
			}
		}
	}
	for(int t=1;t<=n;++t)
	{
		for(int i=2;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				if(d[i][j]&&ans[j]!=-1)
				{
					ans[i]=!ans[j];
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(d[i][j]&&ans[i]==ans[j])
			{
				cout<<"NO";
				exit(0);
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;++i)
	{
		cout<<ans[i];
	}
	return 0;
}