#pragma GCC optimize(2) 
#include<cstdio>
#define N 610
#define ll long long
using namespace std;
void getmin(ll &a,ll b)
{ if(a>b) a=b; }
int n,m,x,y,z,vis[N];
const ll inf=0x3f3f3f3f3f3f3f3f;
ll f[N][N],dis[N],s;
void work(int x)
{
	for(int i=0;i<n;i++) dis[i]=f[x][i],vis[i]=0;
	y=x;
	for(int i=1;i<n;i++)
	{
		x=n;
		for(int j=0;j<n;j++)
			if(!vis[j]&&dis[x]>dis[j]) x=j;
		vis[x]=1;
		getmin(dis[(x+1)%n],dis[x]+1);
		s=inf;
		for(int j=0;j<n;j++)
			getmin(dis[(j+dis[x])%n],dis[x]+f[x][j]);
	}
	for(int i=0;i<n;i++) printf("%lld ",(i!=y)*dis[i]);
	printf("\n");
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			f[i][j]=inf;
	dis[n]=inf;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&x,&y,&z),getmin(f[x][y],z);
	for(int i=0;i<n;i++) work(i);
}