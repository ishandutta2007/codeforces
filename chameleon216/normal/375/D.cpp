#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=120000,W=100001;
struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y)
	{ E[++ec].y=y,E[ec].nx=H[x],H[x]=ec; }
int N,M;
int C[MX];

vector<pair<int,int> > Q[MX];
int cnt[MX];
struct Bit
{
	int v[MX];
	void add(int i,int x)
	{ ++i;while(i<=W)v[i]+=x,i+=(i&-i); }
	int ask(int i)
	{
		++i;int r=0;
		while(i)r+=v[i],i-=(i&-i);
		return r;
	}
	int ask(int l,int r)
	{ return ask(r)-ask(l-1); }
}T;

int sz[MX],son[MX];
#define y E[i].y
void dfs1(int x,int f)
{
	sz[x]=1;
	int mx=0;
	Fe(i,x)if(y!=f)
	{
		dfs1(y,x),sz[x]+=sz[y];
		if(sz[y]>mx)mx=sz[y],son[x]=y;
	}
}

void AddN(int x,int w)
{
	int c=C[x];
	T.add(cnt[c],-1);
	cnt[c]+=w;
	T.add(cnt[c],1);
}
void AddT(int x,int f)
{
	AddN(x,1);
	Fe(i,x)if(y!=f)AddT(y,x);
}
void ClearT(int x,int f)
{
	AddN(x,-1);
	Fe(i,x)if(y!=f)ClearT(y,x);
}

int A[MX];
void dfs2(int x,int f)
{
	Fe(i,x)if(y!=f&&y!=son[x])
		dfs2(y,x),ClearT(y,x);
	if(son[x])dfs2(son[x],x);
	Fe(i,x)if(y!=f&&y!=son[x])
		AddT(y,x);
	AddN(x,1);
	int siz=Q[x].size();
	Fo(i,0,siz)
	{
		pair<int,int> p=Q[x][i];
		A[p.second]=T.ask(p.first,W);
	}
}
#undef y

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",C+i);
	T.add(0,N);
	Fr(i,2,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y),Add(y,x);
	}
	Fr(i,1,M)
	{
		int x,k;
		scanf("%d%d",&x,&k);
		Q[x].push_back(make_pair(k,i));
	}
	dfs1(1,0);
	dfs2(1,0);
	Fr(i,1,M)printf("%d\n",A[i]);
	putchar('\n');
	return 0;
}