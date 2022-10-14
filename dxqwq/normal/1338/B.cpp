#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int Max=0;
bool vis[214514],f1=0,f2=0;
int head[214514],to[214514],nxt[214514];
int leaf[100003],leafcnt;
int tot[100003];
int fa[100003],dep[100003];
void dfs2(int x,int depth)
{
	vis[x]=1,dep[x]=depth;
	for(int i=head[x]; i; i=nxt[i])
	{
		if(vis[to[i]]) continue;
		dfs2(to[i],depth^1);
	}
	return ;
}
void dfs1(int x,int fat)
{
	vis[x]=1,fa[x]=fat;
	for(int i=head[x]; i; i=nxt[i])
	{
		if(vis[to[i]]) continue;
		dfs1(to[i],x);
	}
	return ;
}
bool cmp(int x,int y)
{
	return fa[x]<fa[y];
}
int main()
{
    int n=read(),cnt=0;
    if(n==2)
    {
    	puts("1 1");
    	return 0;
	}
    for(int i=1; i<n; i++)
    {
        int u=read(),v=read();
        nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v,++tot[u];
        nxt[++cnt]=head[v],head[v]=cnt,to[cnt]=u,++tot[v];
}
	for(int i=1; i<=n; i++) if(tot[i]==1) leaf[++leafcnt]=i;
	dfs2(1,1);
	for(int i=1; i<=n; i++) vis[i]=0;
	int ans=n-1;
	dfs1(1,0);
	if(leaf[1]==1) fa[1]=to[head[1]];
	sort(leaf+1,leaf+leafcnt+1,cmp);
	bool is1=1;
	for(int i=1; i<=leafcnt; i++) if(dep[leaf[i]]!=dep[leaf[1]]) 
	{
		printf("3 "),is1=0;
		break;
	}
	for(int i=1; i<leafcnt; i++) if(fa[leaf[i]]==fa[leaf[i+1]]) --ans;
	if(is1) printf("1 ");
    printf("%d",ans);
    return 0;
}