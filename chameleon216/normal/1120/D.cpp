#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
#define Mset(i,x) memset((i),(x),sizeof(i))
using namespace std;
typedef long long ll;
const int MX=320000;
int N;
ll A[MX];

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void AddE(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int F[MX],son[MX],U[MX],V[MX],B[MX];
ll W[MX];

#define y E[i].y
void dfs1(int x,int f)
{
	F[x]=f,W[x]=A[x];
	int mx=-1;
	Fe(i,x)if(y!=f)
	{
		dfs1(y,x);
		if(W[y]>mx)son[x]=y,mx=W[y];
	}
	if(son[x])W[x]=min(W[x],W[son[x]]);
}
void dfs2(int x,int u)
{
	U[x]=u;
	if(son[x])dfs2(son[x],u);
	Fe(i,x)if(y!=F[x]&&y!=son[x])dfs2(y,y);
}
void dfs3(int x,int v)
{
	V[x]=v;
	int cnt=0;
	Fe(i,x)if(y!=F[x]&&W[y]==W[son[x]])++cnt;
	if(cnt==1)dfs3(son[x],v);
	Fe(i,x)if(y!=F[x]&&(cnt>1||y!=son[x]))dfs3(y,y);
}
#undef y



int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",A+i);
	Fo(i,1,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		AddE(x,y),AddE(y,x);
	}
	dfs1(1,0);
	dfs2(1,1);
	dfs3(1,1);
	ll ans=0,cnt=0;
	Fr(i,1,N)
	{
		if(U[i]==i)ans+=W[i];
		if(W[V[i]]==A[i])++cnt;
	}
	printf("%lld %lld\n",ans,cnt);
	Fr(i,1,N)if(W[V[i]]==A[i])printf("%d ",i);
	putchar('\n');
	return 0;
}