#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=500100;

struct Stack{int x,k;}stk[MX];
int tp;
struct DisjointSet
{
	int k,f[MX],sz[MX];
	char w[MX];
	void Init(int i,int n)
	{
		k=i;
		Fr(x,1,n)f[x]=x,sz[x]=1;
	}
	int Find(int& x)
	{
		int a=0;
		while(x!=f[x])a^=w[x],x=f[x];
		return a;
	}
	bool Union(int x,int y)
	{
		int a=Find(x),b=Find(y);
		if(x==y)return a^b;
		if(sz[x]>sz[y])swap(x,y);
		f[x]=y,sz[y]+=sz[x],w[x]=a^b^1;
		stk[++tp].x=x,stk[tp].k=k;
		return 1;
	}
}T[51];
void Rollback(int t)
{
	while(t<tp)
	{
		int x=stk[tp].x,k=stk[tp--].k;
		T[k].sz[T[k].f[x]]-=T[k].sz[x];
		T[k].f[x]=x,T[k].w[x]=0;
	}
}


int N,M,K,Q;
struct Edge{int x,y,k,las;}E[MX];
struct Change{int e,k,r,ans;}C[MX];

struct List{int e,nx;}L[MX<<5];
int H[MX<<2],lc;
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
void Modify(int i,int l,int r,int a,int b,int e)
{
	if(a<=l&&r<=b)
	{
		L[++lc].e=e,L[lc].nx=H[i],H[i]=lc;
		return;
	}
	if(a<=mid)Modify(li,l,mid,a,b,e);
	if(b>mid)Modify(ri,mid+1,r,a,b,e);
}
void Divide(int i,int l,int r)
{
	int t=tp;
	for(int j=H[i];j;j=L[j].nx)
	{
		int e=L[j].e;
		T[E[e].k].Union(E[e].x,E[e].y);
	}
	if(l==r)
	{
		int e=C[l].e;
		if(T[C[l].k].Union(E[e].x,E[e].y))
			E[e].k=C[l].k,C[l].ans=1;
		if(E[e].k&&l+1<=C[l].r)Modify(1,1,Q,l+1,C[l].r,e);
		Rollback(t);
		return;
	}
	Divide(li,l,mid);
	Divide(ri,mid+1,r);
	Rollback(t);
}


int main()
{
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	Fr(i,1,M)scanf("%d%d",&E[i].x,&E[i].y),E[i].las=Q+1;
	Fr(i,1,Q)scanf("%d%d",&C[i].e,&C[i].k);
	Fl(i,Q,1)
	{
		int e=C[i].e;
		C[i].r=E[e].las-1;
		E[e].las=i;
	}
	Fr(i,1,K)T[i].Init(i,N);
	Divide(1,1,Q);
	Fr(i,1,Q)puts(C[i].ans?"YES":"NO");
	return 0;
}