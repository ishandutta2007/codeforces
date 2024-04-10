//This code was made by Chinese_zjc_
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[2001],ans=INF;
struct num{
	int v,p;
}b[2001];
bool flag,dp[2002][2002];
bool can(int l,int r,int x)
{
	int i=1,j=n,mid;
	flag=true;
	while(flag&&i<j)
	{
		mid=(i+j)>>1;
		flag=false;
		if(b[mid].v==a[x])
		{
			if(b[i].v!=a[x])mid=i;
			if(b[j].v!=a[x])mid=j;
		}
		if(b[mid].v<a[x])
		{
			i=mid+1;
			flag=true;
		}
		if(b[mid].v>a[x])
		{
			j=mid-1;
			flag=true;
		}
	}
	for(int k=i;k<=j;++k)
	{
		if(b[k].p<l)
		{
			return false;
		}
		if(b[k].p>r)
		{
			return false;
		}
	}
	return true;
}
bool cmp(const num &A,const num &B)
{
	return A.v==B.v?A.p<B.p:A.v<B.v;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		b[i].p=i;
		b[i].v=a[i];
	}
	sort(b+1,b+1+n,cmp);
	dp[1][n]=true;
	for(int i=1;i<=n;++i)
	{
		for(int j=n;j>=i-1;--j)
		{
			dp[i][j]=dp[i][j]||(dp[i-1][j]&&can(i-1,j,i-1))||(dp[i][j+1]&&can(i,j+1,j+1));
			if(dp[i][j]&&j-i+1<ans)
			{
				ans=j-i+1;
			}
		}
	}
	cout<<ans;
	return 0;
}