#include<bits/stdc++.h>
using namespace std;
int n,i,head[100005],Next[200005],adj[200005],leng[200005],u,v,w,d[1005],fa[100005],k,num[100005],faf[100005],root,lf[100005],ot,num2[100005];
void Push(int u,int v,int w)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
	leng[k]=w;
}
int ansx[1000005],ansy[1000005],ans[1000005],tot;
void decrease(int x,int y,int dec)
{
	ansx[++tot]=x;
	ansy[tot]=y;
	ans[tot]=dec;
}
void dfs(int i,int f)
{
	int j,k;
	fa[i]=f;
	for(j=head[i];j!=0;j=Next[j])
		if(adj[j]!=f)
		{
			faf[adj[j]]=leng[j];
			dfs(adj[j],i);
			num2[i]=num[i];
			num[i]=num[adj[j]];
			if(num2[adj[j]]==0)
				decrease(root,num[adj[j]],faf[adj[j]]);
			else
			{
				decrease(root,num[adj[j]],faf[adj[j]]/2);
				decrease(root,num2[adj[j]],faf[adj[j]]/2);
				decrease(num[adj[j]],num2[adj[j]],-faf[adj[j]]/2);
			}
			for(k=i;k!=0;k=fa[k])
				faf[k]-=faf[adj[j]];
		}
	if(d[i]==1)
		num[i]=i;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		d[u]++;
		d[v]++;
		Push(u,v,w);
		Push(v,u,w);
	}
	for(i=1;i<=n;i++)
		if(d[i]==2)
		{
			printf("NO");
			return 0;
		}
	for(i=1;i<=n;i++)
		if(d[i]==1)
			root=i;
	dfs(root,0);
	printf("YES\n%d\n",tot);
	for(i=1;i<=tot;i++)
		printf("%d %d %d\n",ansx[i],ansy[i],ans[i]);
}