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
	
	char g()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename Tp>
	void d(Tp& x)
	{
		char c=g(),l=0;
		for(x=0;!isdigit(c);c=g())l=c;
		for(;isdigit(c);c=g())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void w(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename Tp>
	void n(Tp x,char c=0)
	{
		if(x<0)w('-'),x=-x;
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)w(stk[t--]);
		if(c)w(c);
	}
}IO;

const int MX=100100;
int N,C[MX];

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int F[MX],sz[MX],son[MX],dfn[MX],dfn_[MX],dc;
void dfs1(int x,int f)
{
	F[x]=f,sz[x]=1,dfn[x]=++dc,dfn_[dc]=x;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x),sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}

int cnt[MX],mx;
ll sum,A[MX];
inline void Add(int x)
{
	int c=C[x];
	++cnt[c];
	if(cnt[c]>mx)mx=cnt[c],sum=c;
	else if(cnt[c]==mx)sum+=c;
}
void Divide(int x)
{
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])
	{
		Divide(y),mx=sum=0;
		Fo(j,dfn[y],dfn[y]+sz[y])
			cnt[C[dfn_[j]]]=0;
	}
	if(son[x])Divide(son[x]);
	Add(x);
	Fe(i,x,y)if(y!=F[x]&&y!=son[x])
	{
		Fo(j,dfn[y],dfn[y]+sz[y])
			Add(dfn_[j]);
	}
	A[x]=sum;
}


int main()
{
	IO.d(N);
	Fr(i,1,N)IO.d(C[i]);
	Fr(i,2,N)
	{
		int x,y;
		IO.d(x),IO.d(y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0);
	Divide(1);
	Fr(i,1,N)IO.n(A[i],' ');
	IO.w('\n');
	return 0;
}