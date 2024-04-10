#include<cstdio>
#define N 200010
using namespace std;
struct edge{
	int next,to;
}e[N*2];
int first[N],len;
void add(int a,int b)
{
	len++;
	e[len].next=first[a];
	first[a]=len;
	e[len].to=b;
}
int size[N],vis[N],fa[N],son[N],s[N];
void dfs1(int x)
{
	vis[x]=size[x]=1;
	for(int i=first[x];i;i=e[i].next)
	{
		if(!vis[e[i].to])
		{
			dfs1(e[i].to);
			fa[e[i].to]=x;
			size[x]+=size[e[i].to];
			if(size[e[i].to]>size[son[x]]) son[x]=e[i].to;
		}
	}
}
int t[N],c[N],n;
long long sum,mx,ans[N];
void addsum(int x,int p)
{
	if(p)
	{
		t[c[x]]++;
		if(t[c[x]]>mx) mx=t[c[x]],sum=c[x];
		else if(t[c[x]]==mx) sum+=c[x];
	}
	else t[c[x]]--;
}
void dfs3(int x,int t)
{
	addsum(x,t);
	for(int i=first[x];i;i=e[i].next)
	{
		if(!s[e[i].to]&&e[i].to!=fa[x])
		{
			dfs3(e[i].to,t);
		}
	}
}
void dfs2(int x,bool keep)
{
	for(int i=first[x];i;i=e[i].next)
		if(e[i].to!=fa[x]&&e[i].to!=son[x]) dfs2(e[i].to,0);
	if(son[x])
	{
		dfs2(son[x],1);
	}
	s[son[x]]=1;
	dfs3(x,1);
	ans[x]=sum;
	s[son[x]]=0;
	if(!keep) dfs3(x,0),mx=sum=0;
}
int a,b;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs1(1);
	dfs2(1,0);
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
}