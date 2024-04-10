#include<cstdio>
using namespace std;
const int N=3e5+10;
struct edge{
	int next,to;
}e[N<<1];
int first[N],len,t[5],dfn[N],ans[N],n,cnt;
struct my_union{
	int fa[N];
	void init()
	{
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int getfa(int a){return a==fa[a]?a:(fa[a]=getfa(fa[a]));}
	bool merge(int x,int y)
	{
		x=getfa(x),y=getfa(y);
		if(x==y) return 0;
		fa[y]=x; return 1;
	}
}a[3];
void add(int a,int b)
{
	e[++len]=edge{first[a],b};
	first[a]=len;
}
void dfs(int x,bool c,int fa)
{
	dfn[x]=++cnt;
	for(int i=first[x],y;i;i=e[i].next)
	{
		if((y=e[i].to)==fa) continue;
		if(!dfn[y]) ans[(i+1)>>1]=c,a[c].merge(x,y),dfs(y,!c,x);
		else if(dfn[y]<dfn[x]) t[++len]=(i+1)>>1;
	}
}
int m,x,y,p,T;
void get_edge(int id)
{
	x=e[id*2-1].to,y=e[id*2].to;
}
bool chk()
{
	for(int i=1;i<=n;i++) a[2].fa[i]=a[0].fa[i];
	for(int i=1;i<=len;i++)
	{
		get_edge(t[i]);
		if(ans[t[i]]==0)
			if(!a[2].merge(x,y)) return 0;
	}
	for(int i=1;i<=n;i++) a[2].fa[i]=a[1].fa[i];
	for(int i=1;i<=len;i++)
	{
		get_edge(t[i]);
		if(ans[t[i]]==1)
			if(!a[2].merge(x,y)) return 0;
	}
	return 1;
}
void dfs(int x)
{
	if(p) return;
	if(x>len)
	{
		if(chk()) p=1;
		return;
	}
	ans[t[x]]=0;
	dfs(x+1);
	if(p) return;
	ans[t[x]]=1;
	dfs(x+1);
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		len=0,a[0].init(),a[1].init();
		for(int i=1;i<=m;i++)
			scanf("%d%d",&x,&y),add(x,y),add(y,x);
		len=p=0;
		dfs(1,0,0);
		dfs(1);
		for(int i=1;i<=m;i++) printf("%d",ans[i]);
		printf("\n");
		for(int i=1;i<=n;i++) first[i]=dfn[i]=0;
	}
}