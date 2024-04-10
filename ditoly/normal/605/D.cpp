#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
#define N 131072
#define get(x) x=upper_bound(p+1,p+pn+1,x)-p-1
struct work{int a,b,id;}w[MN+5];
bool cmp(const work&a,const work&b){return a.b<b.b;}
int a[MN+5],b[MN+5],c[MN+5],d[MN+5],p[MN+5],pn;
int t[N*2+5],u[N*2+5],q[MN+5],qn,dis[MN+5],rw[MN+5];
vector< pair<int,int> > v[N*2+5];
void ins(int k,int x,int z)
{
	v[k+=N].push_back(make_pair(x,z));
	for(t[k]=min(t[k],x);k>>=1;)t[k]=min(t[k<<1],t[k<<1|1]);
}
void solve(int k,int x,int z)
{
	if(t[k]>x)return;
	if(k>N)
	{
		for(;u[k]<v[k].size()&&v[k][u[k]].first<=x;++u[k])
			rw[v[k][u[k]].second]=z,dis[q[++qn]=v[k][u[k]].second]=dis[z]+1;
		t[k]=u[k]<v[k].size()?v[k][u[k]].first:t[0];
		while(k>>=1)t[k]=min(t[k<<1],t[k<<1|1]);
	}
	else solve(k<<1,x,z),solve(k<<1|1,x,z);
}
void solve(int l,int r,int x,int z)
{
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)solve(l+1,x,z);
		if( r&1)solve(r-1,x,z);
	}
}
void out(int x)
{
	if(rw[x])out(rw[x]);
	printf("%d ",x);
}
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)p[i]=a[i]=read(),b[i]=read(),c[i]=read(),d[i]=read();
	sort(p+1,p+n+1);pn=unique(p+1,p+n+1)-p-1;
	for(i=1;i<=n;++i)get(a[i]),get(c[i]);get(c[0]);
	for(i=1;i<=n;++i)p[i]=b[i];
	sort(p+1,p+n+1);pn=unique(p+1,p+n+1)-p-1;
	for(i=1;i<=n;++i)get(b[i]),get(d[i]);get(d[0]);
	if(!c[0]||!d[0])return 0*puts("-1");
	for(i=1;i<=n;++i)w[i]=(work){a[i],b[i],i};
	sort(w+1,w+n+1,cmp);memset(t,40,sizeof(t));
	for(i=1;i<=n;++i)ins(w[i].a,w[i].b,w[i].id);
	for(i=0;i<=qn;++i)solve(1,c[q[i]],d[q[i]],q[i]);
	if(!dis[n])return 0*puts("-1");
	printf("%d\n",dis[n]);out(n);
}