#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=2e5+100;
struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

template<typename T>
void accio(T& x)
{
	char c,l;
	for(c=0;!isdigit(c);c=getchar())l=c;
	for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
	if(l=='-')x=-x;
}


int N,M;
int W[MX]; // = +1/-1 
ll X[MX],Y[MX];

struct Seg
{
	ll z;
	int l,r;
	Seg *L,*R;
	void update(ll x){z+=x;}
	void pushdown(){if(z)L->update(z),R->update(z),z=0;}
	void init(int a,int b);
	void add(int a,int b,ll x);
	ll ask(int a);
}T[MX<<1],*tcnt=T;
Seg* New(){return ++tcnt;}
void Seg::init(int a,int b)
{
	l=a,r=b;
	if(l==r){z=Y[l];return;}
	int m=(l+r)>>1;
	L=New(),L->init(l,m);
	R=New(),R->init(m+1,r);
}
void Seg::add(int a,int b,ll x)
{
	if(a<=l&&r<=b){update(x);return;}
	pushdown();
	if(a<=L->r)L->add(a,b,x);
	if(b>=R->l)R->add(a,b,x);
}
ll Seg::ask(int a)
{
	if(l==r)return z;
	pushdown();
	if(a<=L->r)return L->ask(a);
	else return R->ask(a);
}

#define y E[i].y
int D[MX],sz[MX],id[MX],cnt;
void dfs1(int x,int f,int d)
{
	D[x]=d,sz[x]=1,id[x]=++cnt,W[x]=D[x]&1?1:-1;
	Y[id[x]]=W[x]*X[x];
	Fe(i,x)if(y!=f)dfs1(y,x,d+1),sz[x]+=sz[y];
}
#undef y


int main()
{
	accio(N),accio(M);
	Fr(i,1,N)accio(X[i]);
	ll op,x,y;
	Fr(i,2,N)accio(x),accio(y),add(x,y),add(y,x);
	dfs1(1,0,1);
	T->init(1,N);
	Fr(i,1,M)
	{
		scanf("%lld%lld",&op,&x);
		switch(op)
		{
		case 1:scanf("%lld",&y),T->add(id[x],id[x]+sz[x]-1,W[x]*y);break;
		case 2:printf("%lld\n",T->ask(id[x])*W[x]);break;
		}
	}
	return 0;
}