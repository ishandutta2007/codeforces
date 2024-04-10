#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	
	FastIO(){p=q=ib,r=ob;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	char Get()
	{
//		return getchar();
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename Tp>
	void Read(Tp& x)
	{
		char c=Get(),l=0;
		for(x=0;!isdigit(c);c=Get())l=c;
		for(;isdigit(c);c=Get())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void Put(char c)
	{
//		putchar(c);return;
		if(r-ob==MB)fwrite(ob,1,MB,stdout),r=ob;
		*r++=c;
	}
	template<typename Tp>
	void Write(Tp x)
	{
		if(x<0)Put('-'),x=-x;
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)Put(stk[t--]);
	}
}IO;

const int MX=100100;
int N,M,rt;
ll L[MX];
int ans[MX];

struct Edge{int y,w,nx;}E[MX*2];
int H[MX],ec=1;
void Link(int x,int y,int w){E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}

ll dp[MX*2],mx[MX];
void dfs1(int x,int e)
{
	Fe(i,x,y)if((i^e)!=1)
		dfs1(y,i),dp[e]=max(dp[e],dp[i]);
	dp[e]+=E[e].w;
}
void dfs2(int x,int e)
{
	int son=0;
	ll mx2=0;
	for(int i=H[x];i;i=E[i].nx)
	{
		if(dp[i]>mx[x])mx2=mx[x],mx[x]=dp[i],son=i;
		else if(dp[i]>mx2)mx2=dp[i];
	}
	Fe(i,x,y)if((i^e)!=1)
		dp[i^1]=(i!=son?mx[x]:mx2)+E[i].w,dfs2(y,i);
}
int Center()
{
	dfs1(1,0);
	dfs2(1,0);
	int t=1;
	Fr(x,2,N)if(mx[x]<mx[t])t=x;
	return t;
}

ll U[MX],uc;
int mx_[MX];
struct Fenwick
{
	int v[MX];
	void Add(int i,int x)
	{
		while(i<=uc)v[i]+=x,i+=i&-i;
	}
	int Ask(int i)
	{
		int r=0;
		while(i)r+=v[i],i-=i&-i;
		return r;
	}
}T;

int F[MX],sz[MX],son[MX],dfn[MX],dfn_[MX],dc;
void dfs3(int x,int f)
{
	F[x]=f,sz[x]=1,dfn[x]=++dc,dfn_[dc]=x;
	Fe(i,x,y)if(y!=f)
	{
		dfs3(y,x),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs4(int x)
{
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])
	{
		dfs4(y);
		for(int j=dfn[y];j<dfn[y]+sz[y];++j)
			T.Add(mx_[dfn_[j]],-1);
	}
	if(son[x])dfs4(son[x]);
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])
	{
		for(int j=dfn[y];j<dfn[y]+sz[y];++j)
			T.Add(mx_[dfn_[j]],1);
	}
	T.Add(mx_[x],1);
	Fr(i,1,M)
	{
		int p=upper_bound(U+1,U+uc+1,mx[x]+L[i])-U-1;
		ans[i]=max(ans[i],T.Ask(p));
	}
}

int main()
{
	IO.Read(N);
	Fr(i,2,N)
	{
		int x,y,w;
		IO.Read(x),IO.Read(y),IO.Read(w);
		Link(x,y,w),Link(y,x,w);
	}
	IO.Read(M);
	Fr(i,1,M)IO.Read(L[i]);
	
	rt=Center();
	Fr(x,1,N)U[++uc]=mx[x];
	sort(U+1,U+uc+1);
	uc=unique(U+1,U+uc+1)-U-1;
	Fr(x,1,N)mx_[x]=lower_bound(U+1,U+uc+1,mx[x])-U;
	
	dfs3(rt,0);
	dfs4(rt);
	Fr(i,1,M)IO.Write(ans[i]),IO.Put('\n');
	return 0;
}