#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) {x=~(x-1); putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=1e5+5,mod=1e9+7;
int t,n,m,p[N],q[N],siz[N],cnt,ans;

struct Edge
{
	int v,ne;
}e[N*2];
int head[N],tot;

inline void add(int u,int v);
inline int q_pow(int a,int b,int p);
void dfs1(int u,int fa);
void dfs2(int u,int fa);

signed main()
{
	//write(q_pow(59999,10,mod));
	t=read();
	while(t--)
	{
		tot=0;
		memset(head,0,sizeof(head));
		n=read();
		for(int i=1;i<=n-1;++i)
		{
			int u=read(),v=read();
			add(u,v);add(v,u);
		}
		m=read();
		for(int i=1;i<=m;++i) p[i]=read();
		sort(p+1,p+1+m);
		for(int i=m+1;i<=n-1;++i) p[i]=1;
		for(int i=n;i<=m;++i) p[n-1]=p[n-1]*p[i]%mod;
		cnt=0;
		dfs1(1,0);dfs2(1,0);
		sort(p+1,p+1+n-1);
		sort(q+1,q+1+n-1);
		ans=0;
		for(int i=1;i<=n-1;++i)
			ans=(ans+p[i]*q[i]%mod)%mod;
		write(ans);
		putchar('\n');
	}
	return 0;
}

inline void add(int u,int v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

inline int q_pow(int a,int b,int p)
{
	int c=1%p;
	while(b)
	{
		if(b&1) c=a*c%p;
		b>>=1;a=a*a%p;
	}
	return c;
}

void dfs1(int u,int fa)
{
	siz[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
	}
}

void dfs2(int u,int fa)
{
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(v==fa) continue;
		q[++cnt]=siz[v]*(n-siz[v]);
		dfs2(v,u);
	}
}