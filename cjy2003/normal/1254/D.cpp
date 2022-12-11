#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353,SIZ=500;
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
inline void ad(int &x,int y){(x+=y)>=mod?x-=mod:0;}
struct bian{int nxt,to;}bi[300030];
int n,q,head[150050],num,d[150050],invn,ans;
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;++d[to];}
int bg[610],cnt,id[150050],idnum,siz[150050],f[150050][610],dy[150050],w[150050];
int b[610],s[150050];
void dfs(int v,int fa)
{
	id[v]=++idnum;siz[v]=1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs(u,v);siz[v]+=siz[u];
	}
}
void dfs1(int v,int fa,int rt,int t)
{
	f[v][t]=rt;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs1(u,v,rt,t);
	}
}
inline void ins(int l,int r,int va)
{
	++r;
	ad(b[(l-1)/SIZ+1],va);
	ad(s[l],va);
	ad(b[(r-1)/SIZ+1],mod-va);
	ad(s[r],mod-va);
}
int qry(int x)
{
	int res=0;
	for(int i=1;i*SIZ<=x;++i)ad(res,b[i]);
	for(int i=x/SIZ*SIZ+1;i<=x;++i)ad(res,s[i]);
	return res;
}
int main()
{
	scanf("%d %d",&n,&q);
	invn=kpow(n,mod-2);
	int x,y,z;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
//	for(int i=1;i<=n;++i)printf("%d ",id[i]);printf("\n");
	for(int i=1;i<=n;++i)
		if(d[i]>=SIZ)
		{
			bg[++cnt]=i;dy[i]=cnt;
			for(int j=head[i];j;j=bi[j].nxt)dfs1(bi[j].to,i,bi[j].to,cnt);
		//	for(int j=1;j<=n;++j)printf("%d ",f[j][cnt]);printf("\n");
		}
	int c;
	while(q--)
	{
		scanf("%d",&c);
		if(c==1)
		{
			scanf("%d %d",&x,&y);
			y=1ll*y*invn%mod;
			ad(w[x],y);
			if(d[x]<SIZ)
			{
				for(int i=head[x];i;i=bi[i].nxt)
				{
					if(id[bi[i].to]>id[x])ins(id[bi[i].to],id[bi[i].to]+siz[bi[i].to]-1,1ll*(n-siz[bi[i].to])*y%mod);
					else
					{
						ins(1,id[x]-1,1ll*siz[x]*y%mod);
						ins(id[x]+siz[x],n,1ll*siz[x]*y%mod);
					}
				}
			}
		}
		else
		{
			scanf("%d",&x);
			ans=qry(id[x]);
			ans=(ans+1ll*w[x]*n)%mod;
			int sz;
			for(int i=1;i<=cnt;++i)
			{
				y=bg[i];
				if(x==y)continue;
				z=f[x][i];
				if(id[y]<id[z])ans=(ans+1ll*w[y]*(n-siz[z]))%mod;
				else ans=(ans+1ll*w[y]*siz[y])%mod;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}