#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=220000;
int N,M;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}


#define y E[i].y
int sz[MX];
void dfs1(int x,int f)
{
	sz[x]=1;
	Fe(i,x)if(y!=f)dfs1(y,x),sz[x]+=sz[y];
}

ll A;
void dfs2(int x,int f,ll a)
{
	A=max(A,a);
	Fe(i,x)if(y!=f)dfs2(y,x,a+N-2*sz[y]);
}
#undef y


int main()
{
	scanf("%d",&N);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y),Add(y,x);
	}
	dfs1(1,0);
	ll sum=0;
	Fr(x,1,N)sum+=sz[x];
	dfs2(1,0,sum);
	printf("%lld\n",A);
	return 0;
}