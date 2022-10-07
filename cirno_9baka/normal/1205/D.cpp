#include<bits/stdc++.h>
using namespace std;
int n,head[10005],Next[20005],adj[20005],i,k,u,v,siz[10005],mn=1<<30,mnn,s,j;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	int j;
	siz[i]=1;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			dfs(adj[j],i);
			siz[i]+=siz[adj[j]];
		}
}
struct str{
	int s,x;
}p[10005];
bool cmp(str a,str b)
{
	return a.s<b.s;
}
void dfsa(int i,int fa,int d)
{
	int j;
	u++;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			printf("%d %d %d\n",i,adj[j],u-d);
			dfsa(adj[j],i,u);
		}
}
void dfsb(int i,int fa,int d)
{
	int j;
	v+=u;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=fa)
		{
			printf("%d %d %d\n",i,adj[j],v-d);
			dfsb(adj[j],i,v);
		}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	for(i=1;i<=n;i++)
	{
		dfs(i,0);
		s=0;
		for(j=head[i];j!=0;j=Next[j])
			s=max(s,siz[adj[j]]);
		if(mn>s)
		{
			mn=s;
			mnn=i;
		}
	}
	dfs(mnn,0);
	k=0;
	for(j=head[mnn];j!=0;j=Next[j])
		p[++k]=(str){siz[adj[j]],adj[j]};
	sort(p+1,p+1+k,cmp);
	u=v=0;
	s=0;
	for(i=1;i<=k;i++)
		if(s<n/3)
		{
			s+=p[i].s;
			if(u==0)
				u++;
			printf("%d %d %d\n",mnn,p[i].x,u);
			dfsa(p[i].x,mnn,u);
		}
		else
		{
			if(v==0)
				v+=u;
			printf("%d %d %d\n",mnn,p[i].x,v);
			dfsb(p[i].x,mnn,v);
		}
}