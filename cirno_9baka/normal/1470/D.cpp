#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,k,u,v,head[N],Next[N*2],adj[N*2],vis[N],q[N],l,r,i,j,t;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;++i)
		{
			vis[i]=-1;
			head[i]=0;
		}
		k=0;
		for(i=1;i<=m;++i)
		{
			scanf("%d %d",&u,&v);
			Push(u,v);
			Push(v,u);
		}
		q[l=r=1]=1;
		while(l<=r)
		{
			if(vis[q[l]]!=0)
			{
				vis[q[l]]=1;
				for(j=head[q[l]];j;j=Next[j])
					if(vis[adj[j]]==-1||vis[adj[j]]==2)
					{
						vis[adj[j]]=0;
						for(k=head[adj[j]];k;k=Next[k])
							if(vis[adj[k]]==-1)
							{
								vis[adj[k]]=2;
								q[++r]=adj[k];
							}
					}
			}
			++l;
		}
		r=0;
		for(j=1;j<=n;++j)
		{
			if(vis[j]==1)
				q[++r]=j;
			if(vis[j]==-1)
				break;
		}
		if(j>n)
		{
			puts("YES");
			printf("%d\n",r);
			for(i=1;i<=r;++i)
				printf("%d ",q[i]);
			printf("\n");
		}
		else
			puts("NO");
	}
}