#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
set<int> s[200003];
vector<int>v[200003];
int cur=1;
int to[400003],nxt[400003],head[200003];
int dfn[400003],c,cc;
bool f[200003];
void dfs(int x)
{
	dfn[++c]=x,f[x]=1;
	for(int i=head[x]; i; i=nxt[i]) if(!f[to[i]]) dfs(to[i]),dfn[++c]=x;
}
signed main()
{
	int n=read(),m=read(),k=read();
	for(int i=1,x,y; i<=m; i++) x=read(),y=read(),to[++cc]=y,nxt[cc]=head[x],head[x]=cc,to[++cc]=x,nxt[cc]=head[y],head[y]=cc;
	dfs(1);
	int X=n<<1,t=(2*n-1)/k+1;
	for(int i=1; i<=c; i++)
	{
			if(v[cur].empty()||dfn[i]!=v[cur].back())v[cur].push_back(dfn[i]);
			if((int)v[cur].size()==t) ++cur;
	}
	for(int i=1; i<=k; i++) if(v[i].empty()) v[i].push_back(1);
	for(int i=1; i<=k; i++) 
	{
		printf("%d ",v[i].size());
		for(int j:v[i]) printf("%d ",j);
		puts("");
	}
    return 0;
}