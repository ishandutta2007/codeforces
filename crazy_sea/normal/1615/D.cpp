#include<cstdio>
#define N 200010
using namespace std;
struct edge{
	int next,to,s;
}e[N<<1];
int first[N],len,vis[N],cnt,p;
int calc(int a)
{
	int s=0;
	for(int i=0;i<30;i++)
		if(a&(1<<i)) s^=1;
	return s;
}
void add(int a,int b,int c)
{
	e[++len]=(edge){first[a],b,c};
	first[a]=len;
}
namespace G
{
	edge e[N<<1];
	int first[N],len;
	void add(int a,int b,int c)
	{
		e[++len]=(edge){first[a],b,c};
		first[a]=len;
	}
	void Add(int a,int b,int c)
	{add(a,b,c),add(b,a,c);}
	void dfs(int x,int val)
	{
		if(p) return;
		vis[x]=val;
		for(int i=first[x],y;i;i=e[i].next)
			if(vis[y=e[i].to]==-1) dfs(y,val^e[i].s);
			else if((val^e[i].s)!=vis[y]) p=1;
	}
	void solve()
	{
		for(int i=1;i<=cnt;i++)
			vis[i]=-1;
		for(int i=1;i<=cnt;i++)
			if(vis[i]==-1) dfs(i,0);
		for(int i=1;i<=cnt;i++)
			first[i]=0;
		len=0;
	}
}
int id[N],v[N],fa[N];
void dfs(int x,int k,int val)
{
	id[x]=k;
	v[x]=val;
	for(int i=first[x],y;i;i=e[i].next)
	{
		if((y=e[i].to)==fa[x]) continue;
		fa[y]=x;
		if(e[i].s==-1) dfs(y,++cnt,0);
		else dfs(y,k,val^e[i].s);
	}
}
int getans(int a,int b)
{
	return vis[id[a]]^vis[id[b]]^v[a]^v[b];
}
int n,x[N],y[N],w[N],z,m,a,b,c,T;
void work()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
		if(w[i]==-1) z=-1;
		else z=calc(w[i]);
		add(x[i],y[i],z);
		add(y[i],x[i],z);
	}
	dfs(1,cnt=1,0);
	for(int i=1;i<=n;i++) first[i]=0;
	len=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		G::Add(id[a],id[b],c^v[a]^v[b]);
	}
	G::solve();
	if(p){puts("NO");return;}
	puts("YES");
	for(int i=1;i<n;i++)
		if(w[i]>=0) printf("%d %d %d\n",x[i],y[i],w[i]);
		else printf("%d %d %d\n",x[i],y[i],getans(x[i],y[i]));
}
int main()
{
	scanf("%d",&T);
	while(T--) p=0,work();
}