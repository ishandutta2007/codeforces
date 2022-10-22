#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100;
int N;

struct Edge{int y,w,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y,int w)
{
	E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;
}

int B[MX],O[MX],W[MX],oc;
void dfs1(int x,int f)
{
	B[x]=1;
	Fe(i,x,y)
	{
		if(B[y]==0)
		{
			dfs1(y,x);
			if(B[y]==2&&y!=O[1])
				B[x]=2,O[++oc]=y,W[oc]=E[i].w;
		}
		else if(B[y]==1&&y!=f)
			B[x]=2,O[++oc]=y,W[oc]=E[i].w;
	}
}

void dfs2(int x,int f,ll d,int& x_,ll& d_)
{
	if(d_<d)x_=x,d_=d;
	Fe(i,x,y)if(y!=f&&!(B[x]==2&&B[y]==2))
		dfs2(y,x,d+E[i].w,x_,d_);
}

ll D[MX],Ls[MX],Lm[MX],Rs[MX],Rm[MX];
ll Solve()
{
	ll dm=0;
	Fr(i,1,oc)
	{
		int x=O[i],y=O[i];
		ll d=0;
		dfs2(x,0,0,y,d),D[i]=d;
		dfs2(y,0,0,x,d),dm=max(dm,d);
	}
	ll s,n;
	Ls[1]=n=D[1],s=0;
	Fr(i,2,oc)
	{
		s+=W[i-1];
		Ls[i]=max(Ls[i-1],D[i]+s);
		Lm[i]=max(Lm[i-1],D[i]+s+n);
		n=max(n,D[i]-s);
	}
	Rs[oc]=n=D[oc],s=0;
	Fl(i,oc-1,1)
	{
		s+=W[i];
		Rs[i]=max(Rs[i+1],D[i]+s);
		Rm[i]=max(Rm[i+1],D[i]+s+n);
		n=max(n,D[i]-s);
	}
	
	ll ans=max(dm,Lm[oc]);
	Fr(i,1,oc-1)ans=min(ans,
		max(max(dm,Ls[i]+W[oc]+Rs[i+1]),
		max(Lm[i],Rm[i+1])));
	
	return ans;
}

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		Link(x,y,w),Link(y,x,w);
	}
	dfs1(1,0);
	ll res=Solve();
	printf("%lld\n",res);
	return 0;
}