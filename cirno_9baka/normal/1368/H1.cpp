#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const long long M=998244353;
const long long iv2=499122177;
int n,m,dp[N][2],i,QQ;
char a[N],b[N],c[N],d[N];
int cal()
{
	memset(dp,0,sizeof(dp));
	for(i=1;i<=n;++i)
	{
		if(a[i]=='R')
			++dp[1][0];
		else
			++dp[1][1];
	}
	for(i=1;i<=m;++i)
	{
		if(i!=1)
		{
			dp[i][0]=min(dp[i-1][1]+n,dp[i-1][0]);
			dp[i][1]=min(dp[i-1][0]+n,dp[i-1][1]);
		}
		if(c[i]=='R')
			++dp[i][0];
		else
			++dp[i][1];
		if(d[i]=='R')
			++dp[i][0];
		else
			++dp[i][1];
	}
	for(i=1;i<=n;++i)
	{
		if(b[i]=='R')
			++dp[m][0];
		else
			++dp[m][1];
	}
	return min(dp[m][0],dp[m][1]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&QQ);
	scanf("%s",a+1);
	scanf("%s",b+1);
	scanf("%s",c+1);
	scanf("%s",d+1);
	int s1=cal();
	swap(n,m);
	swap(a,c);
	swap(b,d);
	cout<<min(s1,cal());
}