#include<cstdio>
using namespace std;
const int N=2e5+10;
struct edge{
	int next,to;
}e[N<<1];
int dfn[N],siz[N],fa[N],first[N],len,cnt;
int sum,g[N],h[N],p[N];
int dep[N],lca[N][22];
bool chk(int x,int y)
{
	return dfn[x]<dfn[y]&&dfn[y]<dfn[x]+siz[x];
}
void add(int a,int b)
{
	e[++len]=(edge){first[a],b};
	first[a]=len;
}
void dfs(int x)
{
	dfn[x]=++cnt,siz[x]=1;
	lca[x][0]=fa[x];
	for(int i=1;i<=20;i++) lca[x][i]=lca[lca[x][i-1]][i-1];
	for(int i=first[x],y;i;i=e[i].next)
		if((y=e[i].to)!=fa[x]) fa[y]=x,dep[y]=dep[x]+1,dfs(y),siz[x]+=siz[y];
}
void dfs2(int x,int a)
{
	g[x]+=a;
	for(int i=first[x],y;i;i=e[i].next)
		if((y=e[i].to)!=fa[x]) g[y]+=g[x],dfs2(y,h[x]);
}
int n,m,u[N],v[N],x,y;
int getfa(int a){return a==fa[a]?a:(fa[a]=getfa(fa[a]));}
int jump(int x,int a)
{
	for(int i=20;i>=0;i--)
		if(dep[lca[x][i]]>dep[a]) x=lca[x][i];
	return x;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		x=getfa(u[i]),y=getfa(v[i]);
		if(x==y) continue;
		p[i]=1;
		add(u[i],v[i]);
		add(v[i],u[i]);
		fa[x]=y;
	}
	for(int i=1;i<=n;i++) fa[i]=0;
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		if(!p[i])
		{
			x=u[i],y=v[i];
			if(chk(x,y))
			{
				g[1]++,g[y]++,g[jump(y,x)]--;
			}
			else if(chk(y,x))
			{
				g[1]++,g[x]++,g[jump(x,y)]--;
			}
			else g[x]++,g[y]++;
			sum++;
		}
	}
	dfs2(1,0);
	for(int i=1;i<=n;i++) printf("%d",g[i]==sum);
}