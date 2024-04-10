#include<bits/stdc++.h>
using namespace std;
const int N=100005,E=2000005;
#define id(i,j) (i-1)*m+j
int dis[N],head[N],Next[E],adj[E],cap[E],tot=1,S,T;
int que[N],now[N];
void addedge(int u,int v,int w)
{
	Next[++tot]=head[u],head[u]=tot,adj[tot]=v,cap[tot]=w;
	Next[++tot]=head[v],head[v]=tot,adj[tot]=u,cap[tot]=0;
}
bool BFS()
{
	int i,l,r;
	memset(dis,-1,sizeof(dis));
	que[l=r=1]=S;
	dis[S]=0;
	while(l<=r)
	{
		for(i=head[que[l]];i;i=Next[i])
			if(dis[adj[i]]==-1&&cap[i])
			{
				dis[adj[i]]=dis[que[l]]+1;
				que[++r]=adj[i];
			}
		++l;
	}
	return (dis[T]!=-1);
}
int fl;
bool DFS(int i,int f)
{
	if(i==T)
	{
		fl=f;
		return true;
	}
	int j;
	for(j=now[i];j;now[i]=j=Next[j])
		if(dis[adj[j]]==dis[i]+1&&cap[j]&&DFS(adj[j],min(cap[j],f)))
		{
			cap[j]-=fl;
			cap[j^1]+=fl;
			return true;
		}
	return false;
}
long long Dinic()
{
	long long ans=0;
	while(BFS())
	{
		memcpy(now,head,sizeof(head));
		while(DFS(S,19260817))
			ans+=fl;
	}
	return ans;
}
int n,m,a[100005],w[100005],i,j,k;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char ansc[100005];
int ans[100005];
void Rush()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			scanf("%d",&a[id(i,j)]);
	memset(w,0,sizeof(w));
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		{
			for(k=0;k<4;++k)
			{
				int x=i+dx[k],y=j+dy[k];
				if(x>=1&&x<=n&&y>=1&&y<=m)
					if(a[id(x,y)]<a[id(i,j)])
						break;
			}
			if(k==4)
				w[id(i,j)]=1;
		}
	S=n*m+2,T=n*m+3;
	tot=1;
	memset(head,0,sizeof(head));
	int s1=0,s2=0,at=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if((i^j)&1)
			{
				if(w[id(i,j)])
				{
					++s1;
					++at;
					addedge(S,id(i,j),1);
				}
				else
					addedge(0,id(i,j),1);
				for(k=0;k<4;++k)
				{
					int x=i+dx[k],y=j+dy[k];
					if(x>=1&&x<=n&&y>=1&&y<=m)
					{
						if(a[id(x,y)]==a[id(i,j)]&&w[id(x,y)]==1)
							addedge(id(i,j),id(x,y),1);
						if(a[id(x,y)]==a[id(i,j)]&&w[id(x,y)]==0)
							addedge(id(i,j),id(x,y),1);
					}
				}
			}
			else
			{
				if(w[id(i,j)])
				{
					addedge(id(i,j),T,1);
					++s2;
					++at;
				}
				else
					addedge(id(i,j),n*m+1,1);
				for(k=0;k<4;++k)
				{
					int x=i+dx[k],y=j+dy[k];
					if(x>=1&&x<=n&&y>=1&&y<=m)
						if(a[id(x,y)]==a[id(i,j)]&&w[id(x,y)]==0)
							addedge(id(x,y),id(i,j),1);
				}
			}
	addedge(0,T,s1);
	addedge(S,n*m+1,s2);
	addedge(n*m+1,0,19260817);
	int mt=Dinic();
	if(at!=mt)
	{
		puts("NO");
		return;
	}
	puts("YES");
	memset(ans,0,sizeof(ans));
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if((i^j)&1)
				for(k=head[id(i,j)];k;k=Next[k])
					if(cap[k]==0&&adj[k]>=1&&adj[k]<=n*m)
					{
						int x=(adj[k]+m-1)/m,y=(adj[k]-1)%m+1;
						if(x==i+1)
						{
							ansc[id(i,j)]='D';
							ansc[id(x,y)]='U';
						}
						if(x==i-1)
						{
							ansc[id(i,j)]='U';
							ansc[id(x,y)]='D';
						}
						if(y==j+1)
						{
							ansc[id(i,j)]='R';
							ansc[id(x,y)]='L';
						}
						if(y==j-1)
						{
							ansc[id(i,j)]='L';
							ansc[id(x,y)]='R';
						}
						ans[id(i,j)]=a[id(i,j)]-1;
						ans[id(x,y)]=1;
					}
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			if(!ans[id(i,j)])
				for(k=0;k<4;++k)
				{
					int x=i+dx[k],y=j+dy[k];
					if(x>=1&&x<=n&&y>=1&&y<=m)
						if(a[id(x,y)]<a[id(i,j)])
						{
							if(k==0)
								ansc[id(i,j)]='D';
							if(k==1)
								ansc[id(i,j)]='U';
							if(k==2)
								ansc[id(i,j)]='R';
							if(k==3)
								ansc[id(i,j)]='L';
							ans[id(i,j)]=a[id(i,j)]-a[id(x,y)];
							break;
						}
				}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
			printf("%d ",ans[id(i,j)]);
		printf("\n");
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
			printf("%c ",ansc[id(i,j)]);
		printf("\n");
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		Rush();
}