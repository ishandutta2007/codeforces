// Problem: CF1101D GCD Counting
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1101D
// Memory Limit: 250 MB
// Time Limit: 4500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[200003];
map<int,int> mp[200003];
vector<int> e[200003];
#define pb push_back
int ans;
void dfs(int x,int fa)
{
	map<int,int> fi,se;
	for(int i:e[x]) if(i!=fa)
	{
		dfs(i,x);
		for(auto j:mp[x]) 
			if(fi[j.first]<mp[i][j.first]) 
				se[j.first]=fi[j.first],fi[j.first]=mp[i][j.first];
			else if(se[j.first]<mp[i][j.first])
				se[j.first]=mp[i][j.first];
	}
	for(auto j:mp[x]) ans=max(ans,fi[j.first]+se[j.first]+1),mp[x][j.first]+=fi[j.first];
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) 
	{
		a[i]=read();
		for(int j=2; j*j<=a[i]; ++j) if(!(a[i]%j)) 
		{
			mp[i][j]=1;
			while(!(a[i]%j)) a[i]/=j;
		}
		if(a[i]>1) mp[i][a[i]]=1;
	}
	for(int i=1,u,v; i<n; ++i) u=read(),v=read(),e[u].pb(v),e[v].pb(u);
	dfs(1,1);
	printf("%d\n",ans);
	return 0;
}