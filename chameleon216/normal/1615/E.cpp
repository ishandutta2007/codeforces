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

const int MX=200100;
int N,K;

struct Edge{int y,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int F[MX],he[MX],son[MX];
void dfs1(int x,int f)
{
	F[x]=f,he[x]=1;
	Fe(i,x,y)if(y!=f)
	{
		dfs1(y,x),he[x]=max(he[x],he[y]+1);
		if(he[y]>he[son[x]])son[x]=y;
	}
}

int C[MX],cc;

int main()
{
	scanf("%d%d",&N,&K);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0);
	Fr(x,1,N)if(x!=son[F[x]])C[++cc]=he[x];
	if(K>=cc)
	{
		ll r=max(cc,min(K,N/2));
		printf("%lld\n",r*(N-r));
	}
	else
	{
		sort(C+1,C+cc+1);
		int s=0;
		Fr(i,cc-K+1,cc)s+=C[i];
		ll r=K,b=min(N-s,N/2);
//		printf("%lld %lld\n",r,b);
		printf("%lld\n",(N-r-b)*(r-b));
	}
	return 0;
}