// Problem: D. Nested Rubber Bands
// Contest: Codeforces - Codeforces Round #633 (Div. 1)
// URL: https://codeforces.com/contest/1338/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> e[1000003];
int f[1000003],g[1000003],ans=0;
void dfs(int x,int fa)
{
	int c=e[x].size();
	for(int i:e[x]) if(i!=fa)
	{
		dfs(i,x);
		ans=max(ans,f[x]+g[i]+1);
		ans=max(ans,g[x]+max(f[i],g[i])+c-2);
		f[x]=max(f[x],g[i]);
		g[x]=max(g[x],max(f[i],g[i]));
	}
	++f[x],g[x]+=c-1-(fa!=0);
	ans=max(ans,g[x]),ans=max(ans,f[x]);
	return ;
}
signed main()
{
    int n=read();
    for(int i=1; i<n; ++i) 
    {
    	int u=read(),v=read();
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    dfs(1,0);
    printf("%d\n",ans);
	return 0;
}