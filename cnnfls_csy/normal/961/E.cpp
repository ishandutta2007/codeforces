#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
long long n,m,i,j,x,ans,num[200005],vis[200005];
vector<long long> er[200005];
struct seg
{
	long long arr[200005];
	void add(long long x,long long y)
	{
		long long i;
		for (i=x;i<=n;i+=(i&-i))
		{
			arr[i]+=y;
		}
	}
	long long query(long long x)
	{
		long long i,ans=0;
		for (i=x;i;i-=(i&(-i)))
		{
			ans+=arr[i];
		}
		return ans;
	}
}sum;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for (i=1;i<=n;i++)
	{
		sum.add(i,1);
		cin>>x;
		num[i]=x;
		if (x<=n)
		{
			er[x].push_back(i);
		}
	}
	for (i=1;i<=n;i++)
	{
		if (!vis[i]) sum.add(i,-1);
		ans+=min(num[i],sum.query(min(num[i],n)));
		for (j=0;j<er[i].size();j++)
		{
			if (er[i][j]>i)
			{
				sum.add(er[i][j],-1);
				vis[er[i][j]]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}