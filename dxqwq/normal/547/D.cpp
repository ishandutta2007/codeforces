// Problem: CF527E Data Center Drama
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF527E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
#define pb(x) push_back(make_pair(x,id))
vector<pair<int,int>> e[500003];
int d[500003],id;
bool vis[1000003];
char ans[1000003];
const int N=200000,M=400000;
void dfs(int x)
{
	while(!e[x].empty()&&vis[e[x].back().second]) e[x].pop_back();
	if(!e[x].empty()&&!vis[e[x].back().second]) 
	{
		if(x<=N) ans[e[x].back().second]='r';
		else ans[e[x].back().second]='b';
		vis[e[x].back().second]=1,dfs(e[x].back().first);
	}
	return ;
}
signed main()
{
	int n=read(),Q=n;
	for(int x,y; n--;)
		x=read(),y=N+read(),++d[x],++d[y],++id,
		e[x].pb(y),e[y].pb(x);
	for(int i=1,x,y; i<=M; ++i) if(d[i]&1)
		x=i,y=M+1,++id,e[x].pb(y),e[y].pb(x);
	for(int i=1; i<=N; ++i) dfs(i);
	for(int i=1; i<=Q; ++i) printf("%c",ans[i]);
	return 0;
}