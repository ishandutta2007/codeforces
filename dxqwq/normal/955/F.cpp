// Problem: A. Heaps
// Contest: Codeforces - zmf flip
// URL: https://codeforces.com/gym/374646/problem/A
// Memory Limit: 512 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> e[300003];
ll ans=0;
int mx[300003],d[300003];
unsigned char f[300003][550],g[300003][550];
int t[550][100];
const int B=549;
void dfs(int x,int fa)
{
	int s=0;
	for(int y:e[x]) if(y!=fa) dfs(y,x);
	for(int y:e[x]) if(y!=fa) 
	{
		d[x]=max(d[x],d[y]+1),
		mx[x]=max(mx[x],mx[y]),++s;
		for(int i=2; i<=B; ++i) ++t[i][f[y][i]];
		for(int i=2; i<=B; ++i)
			(g[x][i]<g[y][i])&&(g[x][i]=g[y][i]);
	}
	for(int i=2,z=30,o=i; i<=B; ++i,z=30,o=i) if(s>=i)
	{
		while(o>t[i][z]) o-=t[i][z--];
		f[x][i]=z+1,(g[x][i]<f[x][i])&&(g[x][i]=f[x][i]);
	}
	mx[x]=max(mx[x],s);
	for(int y:e[x]) if(y!=fa) 
		for(int i=2; i<=B; ++i) --t[i][f[y][i]];
	return ;
}
signed main()
{
	int n=read();
	for(int i=1,u,v; i<n; ++i)
		u=read(),v=read(),e[u].push_back(v),e[v].push_back(u);
	dfs(1,1);
	for(int i=1; i<=n; ++i) ans+=d[i];
	for(int i=1; i<=n; ++i)
		for(int j=2; j<=B; ++j)
			ans+=g[i][j];
	for(int i=1; i<=n; ++i) ans+=max(0,mx[i]-B);
	printf("%lld\n",ans+1ll*n*n);
	return 0;
}