#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int num=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch)) num=num*10+(ch&15),ch=getchar();
    return num;
}
int tot,head[200003],nxt[200003],to[200003];
inline void addedge(int x,int y){nxt[++tot]=head[x],head[x]=tot,to[tot]=y;}
int d[100003],f[100003][20],tmp[100003],dis[100003];
bool F[100003];
inline void dfs(int u,int fa)
{
    dis[u]=d[u]=d[fa]+1;
    for(int i=1; i<=17; i++) f[u][i]=f[f[u][i-1]][i-1];
    for(int i=head[u]; i; i=nxt[i])
    {
        int v=to[i];
        if(v==fa)continue;
        f[v][0]=u,dfs(v,u);
    }
}
inline void dfs1(int u,int fa)
{ 
    for(int i=head[u]; i; i=nxt[i])
    {
        int v=to[i];
        if(v==fa) continue;
        dfs1(v,u),tmp[u]=min(tmp[u],tmp[v]+1);
    }
    if(F[u]) tmp[u]=0;
    dis[u]=min(dis[u],tmp[u]);
    return ;
}
inline void dfs2(int u,int fa,int g)
{
	dis[u]=min(dis[u],g);
    for(int i=head[u]; i; i=nxt[i])
    {
        int v=to[i];
        if(v==fa) continue;
        dfs2(v,u,min(tmp[u],g)+1);
    }
}
inline int LCA(int x,int y)
{
    if(d[x]<d[y])swap(x,y);
    for(int i=17; i>=0; --i)
    {
        if(d[f[x][i]]>=d[y])x=f[x][i];
        if(x==y)return x;
    }
    for(int i=17; i>=0; --i) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
int v[330],siz;
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n-1;i++)
    {
        int x=read(),y=read();
        addedge(x,y),addedge(y,x);
    }
    d[1]=-1,F[1]=1,dfs(1,1);
    for(int i=1;i<=m;i++)
    {
		int op=read(),x=read();
		if(op==1) v[++siz]=x;
		else
		{
			int ans=dis[x];
			for(int j=1; j<=siz; ++j) ans=min(ans,d[v[j]]+d[x]-2*d[LCA(v[j],x)]);
			printf("%d\n",ans);
		}
		if(siz==320) 
		{
			for(int j=1; j<=siz; ++j) F[v[j]]=1;
			memset(tmp,0x3f,sizeof(tmp)),dfs1(1,1),dfs2(1,1,0x3f3f3f3f),siz=0;
		}
    }
    return 0;
}