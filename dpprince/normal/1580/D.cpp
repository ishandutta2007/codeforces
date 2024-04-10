// By: Little09
// Problem: D. Subsequence
// Contest: Codeforces - Codeforces Round #745 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1580/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1000000000000000000;
const int N=4005;
int n,m; 
ll a[N],dp[N][N];

inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int st[N],ls[N],rs[N],rt=1;
ll lw[N],rw[N],size[N];
void build()
{
	int top=0,tot=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<a[rt]) rt=i;
		tot=top;
		while (tot&&a[st[tot]]>a[i]) tot--;
		if (tot) rs[st[tot]]=i,rw[st[tot]]=a[i]-a[st[tot]];
		if (tot<top) ls[i]=st[tot+1],lw[i]=a[st[tot+1]]-a[i];
		st[++tot]=i;
		top=tot;
	}
}
void dfs(int u)
{
	size[u]=1;
	if (ls[u])
	{
		dfs(ls[u]);
		for (int i=size[u];i>=0;i--)
		{
			for (ll j=size[ls[u]];j>=0;j--)
			{
				dp[u][i+j]=max(dp[u][i+j],dp[u][i]+dp[ls[u]][j]+j*(m-j)*lw[u]);
			}
		}
		size[u]+=size[ls[u]];
	}
	if (rs[u])
	{
		dfs(rs[u]);
		for (int i=size[u];i>=0;i--)
		{
			for (ll j=size[rs[u]];j>=0;j--)
			{
				dp[u][i+j]=max(dp[u][i+j],dp[u][i]+dp[rs[u]][j]+j*(m-j)*rw[u]);
			}
		}
		size[u]+=size[rs[u]];
	}
}
int main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build();
	dfs(rt);
	cout << dp[rt][m];
	return 0;
}