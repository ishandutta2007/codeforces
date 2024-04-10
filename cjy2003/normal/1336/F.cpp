#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#ifdef cjy
	#define getc() getchar()
	#else
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	#endif
	inline int read()
	{
		static int an,f;an=0,f=1;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=='-'?f=-1:0,ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an*f;
	}
	char buff[N],*T=buff;
	void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	inline void print(int x)
	{
		if(x<0)putc('-'),x=-x;
		if(!x)return putc('0'),void();
		static int st[20],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp]^48),--tp;
	}
}
using io::read;
using io::putc;
using io::flush;
using io::print;
struct edge
{
	int nxt,to;
}e[300030];
int n,m,k,head[150050],num,p[150050][2];
int dep[150050],up[150050][18],siz[150050],id[150050],idnum;
vector<int>q[150050],E[150050],s[150050];
long long ans;
inline void add(int from,int to){e[++num]=edge{head[from],to};head[from]=num;}
struct BIT
{
	int sum[150050];
	inline void ins(int p,int w){/*printf("bitins %d %d\n",p,w);*/while(p<=n)sum[p]+=w,p+=p&-p;}
	inline int query(int p){/*printf("bitquery %d\n",p);*/int s=0;while(p)s+=sum[p],p-=p&-p;return s;}
}t1,t2;
void dfs(int v,int fa)
{
	up[v][0]=fa;dep[v]=dep[fa]+1;siz[v]=1;id[v]=++idnum;
	for(int i=1;i<=17;++i)up[v][i]=up[up[v][i-1]][i-1];
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		dfs(u,v);siz[v]+=siz[u];
	}
}
int qlca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int d=dep[x]-dep[y];
	for(int i=0;i<=17;++i)if(d>>i&1)x=up[x][i];
	if(x==y)return x;
	for(int i=17;~i;--i)if(up[x][i]!=up[y][i])x=up[x][i],y=up[y][i];
	return up[x][0];
}
int getup(int x,int d)
{
	for(int i=0;i<=17;++i)if(d>>i&1)x=up[x][i];
	return x;
}
int siz1[150050],zson[150050];
void predsu(int v)
{
	siz1[v]=s[v].size();zson[v]=0;
	for(auto u:E[v])
	{
		predsu(u);
		siz1[v]+=siz1[u];
		if(siz1[u]>siz[zson[v]])zson[v]=u;
	}
}
void clear(int v)
{
	if(!siz1[v])return;
	for(auto u:s[v])
	{
		static int x;
		x=v==p[u][0]?p[u][1]:p[u][0];
		t2.ins(id[x],-1);
	}
	for(auto u:E[v])clear(u);
}
void ins(int v)
{
	if(!siz1[v])return;
	for(auto u:s[v])
	{
		static int x;
		x=v==p[u][0]?p[u][1]:p[u][0];
		t2.ins(id[x],1);
	}
	for(auto u:E[v])ins(u);
}
void getans(int v,int rt,int nv)
{
	if(!siz1[v])return;
	for(auto u:s[v])
	{
		static int x,dis;
		x=v==p[u][0]?p[u][1]:p[u][0];
		dis=dep[x]-dep[rt]+dep[nv]-dep[rt];
		if(dis<k)continue;
		x=getup(x,min(dep[x]-dep[rt],dis-k));
		// printf("getans:queryt2:%d\n",x);
		ans+=t2.query(id[x]+siz[x]-1)-t2.query(id[x]-1);
	}
	for(auto u:E[v])getans(u,rt,nv);
}
void dsu(int v,int rt)
{
	if(!siz1[v])return;
	// printf("dsu:%d %d\n",v,rt);
	for(auto u:E[v])
		if(u!=zson[v])
		{
			dsu(u,rt);
			clear(u);
		}
	if(zson[v])dsu(zson[v],rt);
	for(auto u:s[v])
	{
		static int x,dis;
		x=v==p[u][0]?p[u][1]:p[u][0];
		dis=dep[x]-dep[rt]+dep[v]-dep[rt];
		if(dis>=k)
		{
			x=getup(x,min(dep[x]-dep[rt],dis-k));
			// printf("dsu:queryt2:%d\n",x);
			ans+=t2.query(id[x]+siz[x]-1)-t2.query(id[x]-1);			
		}
		x=v==p[u][0]?p[u][1]:p[u][0];
		t2.ins(id[x],1);
	}
	for(auto u:E[v])if(u!=zson[v])getans(u,rt,v),ins(u);
}
int stk[150050],tp,a[150050],cnt,cnt1;
bool vis[150050];
void solve(int v,int fa)
{
	// printf("solve:%d\n",v);
	for(auto u:q[v])
	{
		static int x;
		x=p[u][0];
		if(dep[x]-dep[v]>=k)
		{
			x=getup(x,dep[x]-dep[v]-k);
			// printf("queryt1:%d\n",x);
			ans+=2*(t1.query(id[x]+siz[x]-1)-t1.query(id[x]-1));
		}
		x=p[u][1];
		if(dep[x]-dep[v]>=k)
		{
			x=getup(x,dep[x]-dep[v]-k);
			// printf("queryt1:%d\n",x);
			ans+=2*(t1.query(id[x]+siz[x]-1)-t1.query(id[x]-1));
		}
	}
	// printf("ans:%lld\n",ans);
	for(auto u:q[v])
	{
		static int x;
		x=p[u][0];t1.ins(id[x],1);if(!vis[x])vis[x]=1,a[++cnt]=x;s[x].emplace_back(u);
		x=p[u][1];t1.ins(id[x],1);if(!vis[x])vis[x]=1,a[++cnt]=x;s[x].emplace_back(u);
	}
	if(!vis[v])vis[v]=1,a[++cnt]=v;
	sort(a+1,a+1+cnt,[&](int x,int y){return id[x]<id[y];});
	// printf("a:");for(int i=1;i<=cnt;++i)printf("%d ",a[i]);printf("\n");
	stk[tp=1]=v;cnt1=cnt;
	for(int i=2,l;i<=cnt;++i)
	{
		l=qlca(stk[tp],a[i]);
		while(id[l]<id[stk[tp]])
		{
			if(id[l]<id[stk[tp-1]])
			{
				E[stk[tp-1]].emplace_back(stk[tp]);
				--tp;
			}
			else
			{
				E[l].emplace_back(stk[tp]);
				if(l==stk[tp-1])--tp;
				else stk[tp]=l,vis[l]=1,a[++cnt1]=l;
				break;
			}
		}
		stk[++tp]=a[i];
	}
	// printf("stack:");for(int i=1;i<=tp;++i)printf("%d ",stk[i]);printf("\n");
	while(tp>1)E[stk[tp-1]].emplace_back(stk[tp]),--tp;
	// for(int i=1;i<=n;++i)
		// for(auto u:E[i])printf("edge:%d %d\n",i,u);
	predsu(v);dsu(v,v);clear(v);
	for(int i=1;i<=cnt1;++i)vis[a[i]]=0,E[a[i]].clear(),s[a[i]].clear();cnt=cnt1=0;
	// printf("ans:%lld\n",ans);
	for(int i=head[v],u;i;i=e[i].nxt)
	{
		u=e[i].to;
		if(u==fa)continue;
		solve(u,v);
	}
	for(auto u:q[v])
	{
		static int x;
		x=p[u][0];t1.ins(id[x],-1);
		x=p[u][1];t1.ins(id[x],-1);
	}
}
int main()
{
	n=read(),m=read(),k=read();
	for(int i=1,x,y;i<n;++i)
	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	for(int i=1;i<=m;++i)p[i][0]=read(),p[i][1]=read();
	dfs(1,0);
	for(int i=1;i<=m;++i)q[qlca(p[i][0],p[i][1])].emplace_back(i);
	// printf("tag1\n");
	solve(1,0);
	ans/=2;
	printf("%lld",ans);
	return 0;
}