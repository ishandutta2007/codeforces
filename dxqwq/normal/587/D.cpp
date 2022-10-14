// Problem: CF587D Duff in Mafia
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF587D
// Memory Limit: 250 MB
// Time Limit: 6000 ms
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
inline int Read(){
    char ch=getchar();
    int res=0;
    while(ch!='\n')
    {
	   if(isdigit(ch)) res=ch-48;
	   ch=getchar();
    }
    return res;
}
int vis[2000003],dfn[2000003],low[2000003],cur;
int id[2000003],now;
stack<int> s;
vector<int> e[2000003];
void dfs(int x)
{
    vis[x]=1,dfn[x]=low[x]=++cur,s.push(x);
	for(int y:e[x])
	{
		if(vis[y]==0) dfs(y),low[x]=min(low[x],low[y]);
		else if(vis[y]==1) low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]) 
	{
		++now;
		while(vis[x]==1) vis[s.top()]=2,id[s.top()]=now,s.pop();
	}
	return ;
}
#define addedge(x,y) e[x].push_back(y)
int u[100003],v[100003],col[100003],val[100003];
int n=read(),m=read(),N=m*2;
vector<int> sol,g[100003];
bool check(int X)
{
	cur=0,now=0;
	memset(vis,0,sizeof(vis)),
	memset(dfn,0,sizeof(dfn)),
	memset(low,0,sizeof(low));
    for(int i=1; i<=m; i++) if(val[i]>X) addedge(i,i+m);
	for(int i=1; i<=N; i++) if(!vis[i]) dfs(i);
    for(int i=1; i<=m; i++) if(val[i]>X) e[i].pop_back();
	for(int i=1; i<=m; i++) if(id[i]==id[i+m]) return 0;
	vector<int> tmp;
	for(int i=1; i<=m; i++) if(id[i]<id[i+m]) tmp.push_back(i);
	sol=tmp;
	return 1;
}
bool cmp(int x,int y)
{
	return col[x]<col[y];
}
signed main()
{
    for(int i=1; i<=m; ++i) 
    	u[i]=read(),v[i]=read(),col[i]=read(),val[i]=read(),
    	g[u[i]].push_back(i),g[v[i]].push_back(i);
    for(int i=1; i<=n; ++i)
	{
		sort(g[i].begin(),g[i].end(),cmp);
		int A=++N,B=++N,C,D,lst=-1;
		for(int j:g[i])
			C=++N,D=++N,
			addedge(j,C),
			addedge(j,B),
			addedge(D,j+m),
			addedge(A,j+m),
			addedge(A,C),
			addedge(D,B),
			A=C,B=D;
		for(int j:g[i])
			(col[j]!=lst)&&(lst=col[j],A=++N,B=++N),
			C=++N,D=++N,
			addedge(j+m,C),
			addedge(j+m,B),
			addedge(D,j),
			addedge(A,j),
			addedge(A,C),
			addedge(D,B),
			A=C,B=D;
	}
    int l=0,r=1000000000,ans=-1;
    while(l<=r)
    {
    	int mid=(l+r)>>1;
    	if(check(mid)) ans=mid,r=mid-1;
    	else l=mid+1;
    }
    if(ans==-1) puts("No"),exit(0);
    puts("Yes");
    printf("%d %d\n",ans,(int)sol.size());
    for(int i:sol) printf("%d ",i);
	return 0;
}