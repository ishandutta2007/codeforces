#include<bits/stdc++.h>
using namespace std;
int n,u,v,i,head[1005],Next[2005],adj[2005],k,a[1005],siz[1005],dep[1005],t;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
bool cmp(int a,int b)
{
	return dep[a]>dep[b];
}
int dis,d;
void Ans()
{
	int i;
	printf("? %d",k);
	for(i=1;i<=k;++i)
		printf(" %d",&a[i]);
	printf("\n");
	fflush(stdout);
	scanf("%d %d",&d,&dis);
}
void Au(vector<int> g)
{
	int i;
	printf("? %d",g.size());
	for(i=0;i<g.size();++i)
		printf(" %d",g[i]);
	printf("\n");
	fflush(stdout);
	scanf("%d %d",&d,&dis);
}
void dfs(int i,int fa)
{
	int j;
	siz[i]=1;
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
		{
			dep[adj[j]]=dep[i]+1;
			dfs(adj[j],i);
			siz[i]+=siz[adj[j]];
		}
}
vector<int> g,dd[1005];
int md;
void Getv(int i,int fa,int d)
{
	int j;
	dd[d].push_back(i);
	md=max(md,d);
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
			Getv(adj[j],i,d+1);
}
void dfs2(int i,int fa,int d,int dd)
{
	int j;
	if(d==dd)
		g.push_back(i);
	for(j=head[i];j;j=Next[j])
		if(adj[j]!=fa)
			dfs2(adj[j],i,d+1,dd);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(head,0,sizeof(head));
		k=0;
		scanf("%d",&n);
		for(i=1;i<n;++i)
		{
			scanf("%d %d",&u,&v);
			Push(u,v);
			Push(v,u);
		}
		g.clear();
		for(i=1;i<=n;++i)
			g.push_back(i);
		Au(g);
		int tmp=dis;
		int rt=d;
		dep[rt]=1;
		dfs(rt,0);
		int mxx=0;
		for(i=head[rt];i;i=Next[i])
			if(siz[adj[i]]>siz[mxx])
				mxx=adj[i];
		for(i=1;i<=1000;++i)
			dd[i].clear();
		dd[1].push_back(rt);
		md=1;
		for(i=head[rt];i;i=Next[i])
			if(adj[i]!=mxx)
				Getv(adj[i],rt,2);
		int l=1,r=md+1;
		int ld=0;
		while(l<r)
		{
			int mid=l+r>>1;
			Au(dd[mid]);
			if(dis==tmp)
			{
				l=mid+1;
				ld=d;
			}
			else
				r=mid;
		}
		g.clear();
		dfs2(ld,0,0,tmp);
		Au(g);
		printf("! %d %d\n",ld,d);
		fflush(stdout);
		char c[15];
		scanf("%s",c);
	}
}