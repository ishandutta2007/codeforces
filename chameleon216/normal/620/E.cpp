#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=401000;
struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y)
	{E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int N,M,X[MX];
int sz[MX],id[MX],id_[MX],ic;
#define y E[i].y
void dfs1(int x,int f)
{
	sz[x]=1,id[x]=++ic,id_[id[x]]=x;
	Fe(i,x)if(y!=f)dfs1(y,x),sz[x]+=sz[y];
}
#undef y

struct Seg
{
	int l,r;
	ll v,z;
	Seg *L,*R;
	void assign(ll x){v=z=x;}
	void pushup(){v=L->v|R->v;}
	void pushdown(){if(z!=-1)L->assign(z),R->assign(z),z=-1;}
	void build(int a,int b);
	void assign(int a,int b,ll x);
	ll ask(int a,int b);
}T[MX<<1],*tc=T;
void Seg::build(int a,int b)
{
	l=a,r=b,z=-1;
	if(l==r){v=(1ll<<X[id_[l]]);return;}
	int m=(l+r)>>1;
	L=++tc,L->build(l,m);
	R=++tc,R->build(m+1,r);
	pushup();
}
void Seg::assign(int a,int b,ll x)
{
	if(a<=l&&r<=b){assign(x);return;}
	pushdown();
	if(a<=L->r)L->assign(a,b,x);
	if(b>=R->l)R->assign(a,b,x);
	pushup();
}
ll Seg::ask(int a,int b)
{
	if(a<=l&&r<=b)return v;
	pushdown(); ll res=0;
	if(a<=L->r)res|=L->ask(a,b);
	if(b>=R->l)res|=R->ask(a,b);
	return res;
}


int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",X+i);
	Fo(i,1,N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Add(x,y),Add(y,x);
	}
	dfs1(1,0);
	T->build(1,N);
	int o,x,c;
	Fr(i,1,M)
	{
		scanf("%d",&o);
		if(o==1)
		{
			scanf("%d%d",&x,&c);
			T->assign(id[x],id[x]+sz[x]-1,1ll<<c);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",__builtin_popcountll(
				T->ask(id[x],id[x]+sz[x]-1)));
		}
	}
	return 0;
}