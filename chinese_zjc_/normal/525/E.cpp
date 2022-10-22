//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
map <int,int> Hash[26];
int n,k,s,ans,a[30],P[30],lim;
inline int p(int now)
{
	if(now>20)
	{
		return INF;
	}
	else
	{
		return P[now];
	}
}
inline void dfs1(int now,int used,int v)
{
	if(used>k||v>s)
	{
		return;
	}
	if(now>lim)
	{
		++Hash[used][v];
		return;
	}
	dfs1(now+1,used,v);
	dfs1(now+1,used,v+a[now]);
	dfs1(now+1,used+1,v+p(a[now]));
}
inline void dfs2(int now,int used,int v)
{
	if(used>k||v>s)
	{
		return;
	}
	if(now>n)
	{
		for(int i=k-used;i>=0;--i)
		{
			ans+=Hash[i][s-v];
		}
		return;
	}
	dfs2(now+1,used,v);
	dfs2(now+1,used,v+a[now]);
	dfs2(now+1,used+1,v+p(a[now]));
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n>>k>>s;
	P[0]=1;
	for(int i=1;i<=20;++i)
	{
		P[i]=P[i-1]*i;
	}
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	lim=(n+1)/2;
	dfs1(1,0,0);
	dfs2(lim+1,0,0);
	cout<<ans<<endl;
	return 0;
}