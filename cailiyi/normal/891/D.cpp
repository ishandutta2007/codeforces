#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define N 500000
using namespace std;
long long ans;
int n,size[N+5];
vector<int> e[N+5];
struct node
{
	int a[2][2]/*1010*/;
	node() {a[1][0]=1;a[0][0]=a[0][1]=a[1][1]=0;}
	inline node operator+(const node &_b) const
	{
		node ret;
		ret.a[0][0]=a[0][0]*_b.a[0][0]+a[1][0]*_b.a[1][0];
		ret.a[0][1]=a[0][1]*_b.a[0][0]+a[0][0]*(_b.a[0][1]+_b.a[1][0])+a[1][1]*_b.a[1][0]+a[1][0]*_b.a[1][1];
		ret.a[1][0]=a[1][0]*_b.a[0][0];
		ret.a[1][1]=a[1][0]*(_b.a[1][0]+_b.a[0][1])+a[1][1]*_b.a[0][0];
		return ret;
	}
	inline node operator|(const node &_b) const
	{
		node ret;
		ret.a[0][0]=a[0][0]*_b.a[1][0]+a[1][0]*_b.a[0][0];
		ret.a[0][1]=a[0][1]*_b.a[1][0]+a[1][1]*_b.a[0][0]+a[0][0]*_b.a[1][1]+a[1][0]*_b.a[0][1];
		ret.a[1][0]=a[1][0]*_b.a[1][0];
		ret.a[1][1]=a[1][0]*_b.a[1][1]+a[1][1]*_b.a[1][0];
		return ret;
	}
}f[N+5],g[N+5];
void dfs(int x,int fa)
{
	if(fa) e[x].erase(find(e[x].begin(),e[x].end(),fa));
	size[x]=1;for(int y:e[x]) dfs(y,x),f[x]=f[x]+f[y],size[x]+=size[y];
}
void dfs2(int x,int fa)
{
	node temp;vector<node> sum;
	sum.push_back(fa?temp+g[x]:temp);
	for(int y:e[x]) sum.push_back(sum.back()+f[y]);
	for(int i=(int)e[x].size()-1;i>=0;--i)
		g[e[x][i]]=sum[i]|temp,temp=temp+f[e[x][i]],dfs2(e[x][i],x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	dfs(1,0),dfs2(1,0);
	for(int i=2;i<=n;++i)
		if(f[i].a[0][0] && g[i].a[0][0]) ans+=1ll*size[i]*(n-size[i]);
		else ans+=1ll*(f[i].a[0][1]+f[i].a[1][0])*(g[i].a[0][1]+g[i].a[1][0]);
	printf("%lld",ans);
	return 0;
}