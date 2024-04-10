#include<bits/stdc++.h>
using namespace std;
int n,m,i,s,j,u,v,head[200005],Next[400005],adj[400005],k,siz[200005],mxx,l,nx[200005],a[200005],p;
long long ans,mx;
bool flag=true;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int f,int d)
{
	int j;
	if(mx<d)
	{
		mx=d;
		mxx=i;
	}
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f)
			dfs(adj[j],i,d+1);
}
void dfs2(int i,int f)
{
	int j;
	if(i==mxx)
	{
		nx[i]=-1;
		flag=false;
		return;
	}
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f&&flag)
		{
			nx[i]=adj[j];
			dfs2(adj[j],i);
		}
	if(flag)
		nx[i]=0;
}
void dfs3(int i,int f,int d)
{
	int j;
	if(nx[i]==0)
		ans+=d;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f&&adj[j]!=nx[i])
			if(nx[i]!=0)
				dfs3(adj[j],i,max(1ll*d,mx-d)+1);
			else
				dfs3(adj[j],i,d+1);
	if(nx[i]!=0&&nx[i]!=-1)
		dfs3(nx[i],i,d+1);
}
void dfs4(int i,int f,int tot)
{
	int j;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f)
			dfs4(adj[j],i,tot);
	printf("%d %d %d\n",tot,i,i);
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
	mx=-1;
	dfs(1,0,0);
	l=mxx;
	mx=-1;
	dfs(mxx,0,0);
	dfs2(l,0);
	dfs3(l,i,0);
	cout<<ans+mx*(mx+1)/2<<endl;
	for(i=l;i!=-1;i=nx[i])
		a[++p]=i;
	for(i=1;i<=p;i++)
		for(j=head[a[i]];j!=0;j=Next[j])
			if(adj[j]!=a[i-1]&&adj[j]!=a[i+1])
				if(i<=(mx+1)/2)
					dfs4(adj[j],a[i],mxx);
				else
					dfs4(adj[j],a[i],l);
	for(i=p;i>1;i--)
		printf("%d %d %d\n",l,a[i],a[i]);
}