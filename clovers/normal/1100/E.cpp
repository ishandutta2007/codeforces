#include<bits/stdc++.h>
using namespace std;
const int N=210000;

struct node{
	int from,to,cost,id;
}E[N];
vector<int> v;

int first[N],nxt[N],point[N],w[N],e=0,dfn[N];
void add_edge(int x,int y,int z,int num)
{
	e++;
	E[num].id=e;
	point[e]=y; w[e]=z;
	nxt[e]=first[x];
	first[x]=e;
}

bool cmp(node x,node y)
{
	if(x.cost==y.cost) return x.id<y.id;
	return x.cost<y.cost;
}

int vis[N],bl[N],n,m,judge,best,in[N];
void dfs(int u)
{
	vis[u]=2;
	for(int i=first[u];i!=-1;i=nxt[i])
	{
		if(bl[i]) continue;
		int p=point[i];
		if(vis[p]==2) 
		{
			judge=0;
			return;
		}
		if(!vis[p]) dfs(p); 
	}
	vis[u]=1;
	return;
}

bool check(int mid)
{
	judge=1; 
	memset(vis,0,sizeof(vis));
	memset(bl,0,sizeof(bl));
	for(int i=1;i<=mid;i++) bl[E[i].id]=1; 
	for(int i=1;i<=n;i++) 
	{
		if(!vis[i]) 
		{
			dfs(i);
		}
	}
	return judge;
}

int main()
{
	memset(first,-1,sizeof(first));
	memset(nxt,-1,sizeof(nxt));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&E[i].from,&E[i].to,&E[i].cost);
		add_edge(E[i].from,E[i].to,E[i].cost,i);
	}
	sort(E+1,E+m+1,cmp);
	int l=0,r=m,mid;best=-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid-1,best=mid;
		else l=mid+1;
	}
	queue<int> q;int tot=0;
	memset(in,0,sizeof(in));
	for(int i=best+1;i<=m;i++)
	{
		in[E[i].to]++;
	}
	for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
	memset(bl,0,sizeof(bl));
	for(int i=1;i<=best;i++) bl[E[i].id]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		dfn[now]=++tot;
		for(int i=first[now];i!=-1;i=nxt[i])
		{
			if(bl[i]) continue;
			int pos=point[i];
			in[pos]--;
			if(!in[pos]) q.push(pos); 
		}
	}
	for(int i=1;i<=best;i++) 
	{
		int x=E[i].from;
		int y=E[i].to;
		if(dfn[x]>dfn[y]) v.push_back(E[i].id);
	}
	printf("%d %d\n",E[best].cost,(int)v.size());
	for(int i=0;i<(int)v.size();i++) printf("%d ",v[i]);
	return 0;
}