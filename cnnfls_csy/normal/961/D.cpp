#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,vis[100005];
long long px[100005],py[100005];
bool check(int x,int y)
{
	long long t1,t2;
	int i,j;
	memset(vis,0,sizeof(vis));
	if (px[x]!=px[y])
	{
		t1=px[x]-px[y];
		t2=py[x]-py[y];
		long long t=__gcd(t1,t2);
		t1/=t;
		t2/=t;
		for (i=1;i<=n;i++)
		{
			if (i==x||i==y)
			{
				vis[i]=1;
				continue;
			}
			if ((px[i]-px[x])%t1==0)
			{
				if ((px[i]-px[x])/t1*t2==(py[i]-py[x]))
				{
					vis[i]=1;
				}
			}
		}
	}
	else
	{
		for (i=1;i<=n;i++)
		{
			if (px[i]==px[x]) vis[i]=1;
		}
	}
	for (x=1;x<=n;x++) if (!vis[x]) break;
	for (y=x+1;y<=n;y++) if (!vis[y]) break;
	if (x>n||y>n) return 1;
	if (px[x]!=px[y])
	{
		t1=px[x]-px[y];
		t2=py[x]-py[y];
		long long t=__gcd(t1,t2);
		t1/=t;
		t2/=t;
		for (i=1;i<=n;i++)
		{
			if (i==x||i==y)
			{
				vis[i]=1;
				continue;
			}
			if ((px[i]-px[x])%t1==0)
			{
				if ((px[i]-px[x])/t1*t2==(py[i]-py[x]))
				{
					vis[i]=1;
				}
			}
		}
	}
	else
	{
		for (i=1;i<=n;i++)
		{
			if (px[i]==px[x]) vis[i]=1;
		}
	}
	for (i=1;i<=n;i++) if (!vis[i]) return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>px[i]>>py[i];
	}
	if (n<=4)
	{
		cout<<"YES";
		return 0;
	}
	for (i=1;i<=3;i++)
	{
		for (j=1;j<=3;j++)
		{
			if (i!=j&&check(i,j))
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}