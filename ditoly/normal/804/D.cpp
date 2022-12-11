#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
#define p(x,y) make_pair(x,y)
struct edge{int nx,t;}e[MN*2+5];
int f[MN+5],h[MN+5],en,d[MN+5],d2[MN+5],mx[MN+5];
vector<double> v[MN+5];
map<pair<int,int>,double> mp;
int gf(int k){return f[k]?f[k]=gf(f[k]):k;}
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void upd(int x,int y)
{
	if(y>d[x])d2[x]=d[x],d[x]=y;
	else if(y>d2[x])d2[x]=y;
}
void dp(int x,int fa)
{
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
		dp(e[i].t,x),upd(x,d[e[i].t]+1);
	mx[gf(x)]=max(mx[gf(x)],d[x]+d2[x]);
}
void dfs(int x,int fa)
{
	v[gf(x)].push_back(d[x]);
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
		upd(e[i].t,d[e[i].t]+1==d[x]?d2[x]+1:d[x]+1),dfs(e[i].t,x);
}
int main()
{
	int n,m,q,x,y,i,j,l,r,mid,res;double ans;
	n=read();m=read();q=read();
	while(m--)ins(x=read(),y=read()),f[gf(x)]=gf(y);
	for(i=1;i<=n;++i)if(gf(i)==i)
	{
		dp(i,i);dfs(i,i);v[i].push_back(0);
		sort(v[i].begin(),v[i].end());
		for(j=1;j<v[i].size();++j)v[i][j]+=v[i][j-1];
	}
	while(q--)
	{
		if((x=gf(read()))==(y=gf(read()))){puts("-1");continue;}
		if(x>y)swap(x,y);
		if(mp[p(x,y)]){printf("%.10lf\n",mp[p(x,y)]);continue;}
		if(v[x].size()>v[y].size())swap(x,y);
		for(i=1,ans=0;i<v[x].size();++i)
		{
			for(l=1,r=v[y].size()-1,res=0;l<=r;)
			{
				mid=l+r>>1;
				if(v[x][i]-v[x][i-1]+v[y][mid]-v[y][mid-1]+1<=max(mx[x],mx[y]))
					res=mid,l=mid+1;
				else r=mid-1;
			}
			ans+=(double)res*max(mx[x],mx[y])+
				 (v[y].size()-1-res)*(v[x][i]-v[x][i-1]+1)+v[y][v[y].size()-1]-v[y][res];
		}
		if(x>y)swap(x,y);
		printf("%.10lf\n",mp[p(x,y)]=ans/(v[x].size()-1)/(v[y].size()-1));
	}
}