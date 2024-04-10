#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
namespace BIT
{
	int sum[5050];
	inline void add(int x,int w){while(x<=5000)sum[x]+=w,x+=x&-x;}
	inline int qry(int x){int s=0;while(x)s+=sum[x],x-=x&-x;return s;}
}
int n,siz[10010],dt[10010];
int su[5050],sunum,d[10010],cnt[10010],tot,ge[10010],cnt1[10010];
bool bj[5050];
pair<int,int>p[5050];
void init()
{
	for(int i=2;i<=5000;++i)
	{
		if(!bj[i])su[++sunum]=i,d[i]=i;
		for(int j=1;j<=sunum&&su[j]*i<=5000;++j)
		{
			bj[su[j]*i]=1;
			d[su[j]*i]=d[i];
			if(i%su[j]==0)break;
		}
	}
	for(int i=5000;i;--i)ge[i]=bj[i]?ge[i+1]:i;
	for(int i=2;i<=5000;++i)
	{
		int x=i;
		while(x>1)++cnt[i],x/=d[x];
	}
//	printf("!!!");
	for(int i=2;i<=5000;++i)cnt[i]+=cnt[i-1];
	for(int i=2;i<=5000;++i)p[i]=make_pair(d[i],i);
	sort(p+2,p+5001);
	int last=5000;
	for(int i=sunum;i;--i)
	{
		for(int j=su[i],k;j<=5000;j+=su[i])
		{
			k=j;
			while(k%su[i]==0)BIT::add(j,1),k/=su[i];
		}
		while(p[last].first==su[i])cnt1[p[last].second]=BIT::qry(p[last].second-1),--last;
	}
}
int st[10010][2],tp;
struct bian
{
	int nxt,to;
}bi[20020];
int head[10010],num;
inline void add(int from,int to)
{
//	printf("%d %d\n",from,to);
	bi[++num]=bian{head[from],to};head[from]=num;
	bi[++num]=bian{head[to],from};head[to]=num;
}
int maxs[10010],rt,asiz[10010];
void dfs1(int v,int fa)
{
	asiz[v]=siz[v];
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs1(u,v);
		asiz[v]+=asiz[u];
		maxs[v]=max(maxs[v],asiz[u]);
	}
	maxs[v]=max(maxs[v],n-asiz[v]);
//	if(v<=10)printf("%d %d\n",v,maxs[v]);
	if(maxs[v]<maxs[rt])rt=v;
}
long long ans;
void calc(int v,int fa,int dis)
{
	ans=ans+1ll*dis*siz[v];
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		calc(u,v,dis+abs(cnt[u]-cnt[v]));
	}
}
int main()
{
	init();
//	for(int i=1;i<=10;++i)printf("%d ",d[i]);printf("\n");
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%d",&x);
		if(!x)++x;
		++siz[x];
	}
	st[++tp][0]=1,st[tp][1]=0x3f3f3f3f;
	tot=5000;
	for(int i=2,k=2;i<=5000;++i)
	{
		if(i==k)
		{
			st[++tp][0]=i,st[tp][1]=2;k<<=1;
			continue;
		}
		while(tp>1&&st[tp-1][1]<d[i])add(st[tp-1][0],st[tp][0]),--tp;
		if(tp>1)
		{
			if(!bj[i])add(1,st[tp][0]),--tp;
			else 
			{
				++tot,dt[tot]=i,add(tot,st[tp][0]),st[tp][0]=tot,st[tp][1]=ge[d[i]];
				cnt[tot]=cnt1[i];
			}
		}
		st[++tp][0]=i,st[tp][1]=2;
	}
	while(tp>1)add(st[tp-1][0],st[tp][0]),--tp;
//	printf("!!!");
	maxs[rt]=0x3f3f3f3f;
	dfs1(1,0);
//	printf("%d\n",rt);
	calc(rt,0,0);
	printf("%lld",ans);
	return 0;
}