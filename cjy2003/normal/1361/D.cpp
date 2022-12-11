#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
struct point
{
	int x,y;
	friend bool operator < (point a,point b)
	{
		if(a.x==0&&a.y==0)return 1;
		if(b.x==0&&b.y==0)return 0;
		bool f1=a.y>0||(a.y==0&&a.x>0),f2=b.y>0||(b.y==0&&b.x>0);
		if(f1!=f2)return f1>f2;
		if(1ll*a.y*b.x!=1ll*b.y*a.x)return 1ll*a.y*b.x<1ll*b.y*a.x;
		return abs(a.x)+abs(a.y)<abs(b.x)+abs(b.y);
	}
}p[500050];
double qdis(point x,point y)
{
	return sqrt(1ll*(x.x-y.x)*(x.x-y.x)+1ll*(x.y-y.y)*(x.y-y.y));
}
int n,k;
int sgn(int x)
{
	if(x==0)return 0;
	return x>0?1:-1;
}
vector<int>E[500050];
void add(int x,int y){E[x].emplace_back(y);E[y].emplace_back(x);}
int siz[500050],a[500050],f[500050],id[500050],idnum,siz1[500050];
double ans,dis[500050],w[500050],sum;
bool cut[500050];
void dfs(int v,int fa)
{
	id[v]=++idnum,siz[v]=1;f[v]=fa;
	for(auto u:E[v])
	{
		if(u==fa)continue;
		dis[u]=dis[v]+qdis(p[u],p[v]);
		dfs(u,v);
		siz[v]+=siz[u];
	}
}
void getans(int v,int fa)
{
	siz1[v]=!cut[v];
	for(auto u:E[v])
	{
		if(u==fa)continue;
		getans(u,v);
		siz1[v]+=siz1[u];
	}
	sum+=qdis(p[v],p[fa])*siz1[v]*(k-siz1[v]);
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d %d",&p[i].x,&p[i].y);
	sort(p+1,p+1+n);
	for(int i=2;i<=n;++i)
	{
		if(sgn(p[i].x)==sgn(p[i-1].x)&&sgn(p[i].y)==sgn(p[i-1].y)&&1ll*p[i].x*p[i-1].y==1ll*p[i-1].x*p[i].y)add(i-1,i);
		else add(1,i);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)w[i]=2*siz[i]*dis[i]-(k+1)*dis[i];
	for(int i=1;i<=n;++i)a[i]=i;
	sort(a+1,a+1+n,[&](int x,int y){return w[x]>w[y];});
	for(int i=1;i<=n-k;++i)cut[a[i]]=1;
	sum=0;getans(1,0);ans=max(ans,sum);		
	for(auto i:E[1])
		if(siz[i]>=n-k+k/2)
		{
			memset(cut+1,0,n);
			for(int j=i+siz[i]-(n-k+k/2),c=1;c<=n-k;++j,++c)cut[j]=1;
			sum=0;getans(1,0);ans=max(ans,sum);
		}
	printf("%.12lf",ans);
	return 0;
}