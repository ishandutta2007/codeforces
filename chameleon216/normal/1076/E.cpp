#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=300100;
int N,M;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int D[MX],sz[MX],dfn[MX],dc;
vector<int> V[MX];
vector<ll> S[MX];
ll W[MX];

void dfs1(int x,int f,int d)
{
	D[x]=d,sz[x]=1,dfn[x]=++dc;
	V[d].push_back(x);
	Fe(i,x,y)if(y!=f)
		dfs1(y,x,d+1),sz[x]+=sz[y];
}

bool cmp(int x,int p){return dfn[x]<p;}
void Modify(int x,int d,int a)
{
	W[x]+=a;
	d=D[x]+d+1;
	if(d>N)return;
	vector<int> &v=V[d];
	int l=lower_bound(v.begin(),v.end(),dfn[x],cmp)-v.begin();
	int r=lower_bound(v.begin(),v.end(),dfn[x]+sz[x],cmp)-v.begin();
	int z=v.size();
	if(l!=z)S[d][l]-=a;
	if(r!=z)S[d][r]+=a;
}

void dfs2(int x,int f)
{
	W[x]+=W[f];
	Fe(i,x,y)if(y!=f)dfs2(y,x);
}


int main()
{
	scanf("%d",&N);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0,1);
	for(int i=1;V[i].size();++i)
		S[i].resize(V[i].size());
	
	scanf("%d",&M);
	Fr(i,1,M)
	{
		int x,d,a;
		scanf("%d%d%d",&x,&d,&a);
		Modify(x,d,a);
	}
	
	Fr(i,1,N)
	{
		int z=V[i].size();
		Fr(j,1,z-1)S[i][j]+=S[i][j-1];
		Fr(j,0,z-1)W[V[i][j]]+=S[i][j];
	}
	dfs2(1,0);
	Fr(i,1,N)printf("%lld ",W[i]);putchar('\n');
	
	return 0;
}