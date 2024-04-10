// Problem: D. Timofey and a flat tree
// Contest: Codeforces Round #395 (Div. 1)
// URL: https://codeforces.com/contest/763/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
mt19937 Rnd(114514);
int rnd()
{
	int A=Rnd()<<31;
	int B=Rnd();
	return A^B;
}
const int p=1945555039024054273ll;
int n=read();
vector<int> e[1000003];
int sz[1000003],f[1000003],h[1000003],st[1000003];
int cur=0;
map<int,int> mp,mmp;
void ins(int x){cur+=(mmp[x]++)==0;cur-=mmp[x]==0;return;}
void del(int x){cur+=(mmp[x]--)==0;cur-=mmp[x]==0;return;}
void dfs1(int u,int fa=0) 
{
	f[u]=0;
	for(int v:e[u]) if(v!=fa) 
		dfs1(v,u),f[u]=(f[u]+h[v])%p;
	if(mp.count(f[u])) h[u]=mp[f[u]];
	else h[u]=mp[f[u]]=rnd()%p;
	ins(h[u]);
}

void dfs2(int u,int up=0,int fa=0) 
{
	st[u]=cur;
	int sum=up;
	for(int v:e[u]) if(v!=fa) sum=(sum+h[v])%p;
	for(int v:e[u]) if(v!=fa) 
	{
		int val=(sum+p-h[v])%p;
		if(mp.count(val)) val=mp[val];
		else val=mp[val]=rnd()%p;
		del(h[v]),ins(val);
		dfs2(v,val,u);
		ins(h[v]),del(val);
	}
}
signed main()
{
	for(int i=1; i<n; ++i)
	{
		int u=read(),v=read();
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs1(1),del(h[1]),dfs2(1);
	int ans=1;
	st[1]=cur;
	for(int i=2; i<=n; ++i) 
	if(st[i]>st[ans]) ans=i;
	printf("%lld\n",ans);
	return 0;
}