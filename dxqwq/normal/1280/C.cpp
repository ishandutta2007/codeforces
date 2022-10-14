// Problem: C. Jeremy Bearimy
// Contest: Codeforces - Codeforces Round #607 (Div. 1)
// URL: https://codeforces.com/contest/1280/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define pii pair<int,int>
#define mp make_pair
vector<pii > e[1000003];
int n;
int sz[1000003];
int dfs1(int x,int fa)
{
	sz[x]=1;
	int res=0;
	for(auto pp:e[x])
	{
		int i=pp.first;
		int v=pp.second;
		if(i==fa) continue;
		res+=dfs1(i,x);
		sz[x]+=sz[i];
		if(sz[i]%2==0) continue;
		res+=v;
		
	}
	return res;
}
int dfs2(int x,int fa)
{
	sz[x]=1;
	int res=0;
	for(auto pp:e[x])
	{
		int i=pp.first;
		int v=pp.second;
		if(i==fa) continue;
		res+=dfs2(i,x);
		res+=v*min(sz[i],n-sz[i]);
		sz[x]+=sz[i];
	}
	return res;
}
signed main()
{
	for(int T=read();T--;)
	{
		n=read()*2;
		for(int i=1; i<=n; ++i)
		e[i].clear();
		for(int i=1; i<n; ++i)
		{
			int u=read(),v=read(),w=read();
			e[u].push_back(mp(v,w));
			e[v].push_back(mp(u,w));
		}
		printf("%lld %lld\n",dfs1(1,1),dfs2(1,1));
	}
	return 0;
}