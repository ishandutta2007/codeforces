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
#define Fe(i,x) for(int i=H[x],y=E[i].y;i;\
						i=E[i].nx,y=E[i].y)
using namespace std;
typedef long long ll;
const int MX=5e5+100;
struct Star{int y,nx;}E[MX<<1];
int H[MX],ec;
void add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int N,M;

struct Seg
{
	int z,l,r;
	Seg *L,*R;
	void ud(int x){z=x;}
	void pd(){if(z!=-1)L->ud(z),R->ud(z),z=-1;}
	void init(int a,int b);
	void set(int a,int b,int x);
	int ask(int a);
}T[MX<<1],*tcnt=T;
Seg* New(){return ++tcnt;}
void Seg::init(int a,int b)
{
	l=a,r=b,z=-1;
	if(l==r){z=0;return;}
	int m=(l+r)>>1;
	L=New(),L->init(a,m);
	R=New(),R->init(m+1,b);
}
void Seg::set(int a,int b,int x)
{
	if(a<=l&&r<=b){ud(x);return;}
	pd();
	if(a<=L->r)L->set(a,b,x);
	if(b>=R->l)R->set(a,b,x);
}
int Seg::ask(int a)
{
	if(l==r)return z;
	pd();
	if(a<=L->r)return L->ask(a);
	else return R->ask(a);
}


int F[MX],D[MX],sz[MX],son[MX];
int U[MX],id[MX],cnt;
void dfs1(int x,int f,int d)
{
	F[x]=f,D[x]=d,sz[x]=1,son[x]=-1;
	int mx=0;
	Fe(i,x)if(y!=f)
	{
		dfs1(y,x,d+1),sz[x]+=sz[y];
		if(sz[y]>mx)mx=sz[y],son[x]=y;
	}
}
void dfs2(int x,int u)
{
	U[x]=u,id[x]=++cnt;
	if(son[x]!=-1)dfs2(son[x],u);
	Fe(i,x)if(y!=F[x]&&y!=son[x])dfs2(y,y);
}
void Set1(int x)
{
	T->set(id[x],id[x]+sz[x]-1,1);
}
void Set0(int x)
{
	while(x)T->set(id[U[x]],id[x],0),x=F[U[x]];
}
int Ask(int x)
{
	return T->ask(id[x]);
}


int main()
{
	scanf("%d",&N);
	int x,y;
	Fr(i,2,N)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	T->init(1,N);
	dfs1(1,0,1);
	dfs2(1,1);
//	while(1)
//	{
//		int x,y,z;
//		scanf("%d%d%d",&x,&y,&z),T->set(x,y,z);
//		Fr(i,1,N)printf("%d",T->ask(i));printf("\n");
//	}
	
	int k;
	scanf("%d",&M);
	Fr(i,1,M)
	{
		scanf("%d%d",&k,&x);
		switch(k)
		{
		case 1:Set1(x);break;
		case 2:Set0(x);break;
		case 3:printf("%d\n",Ask(x));break;
		}
	}
	return 0;
}