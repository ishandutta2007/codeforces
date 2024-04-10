#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=100100,N=100000,Inf=0x7fffffff;
int M;

#define li (i<<1)
#define ri (i<<1|1)
struct Node{int g,g2,c,z;ll s;};
struct SegmentTree
{
	Node T[MX*4];
	void Put(int i,int z){T[i].g+=z,T[i].s+=(ll)z*T[i].c,T[i].z+=z;}
	void PushDown(int i)
	{
		if(!T[i].z)return;
		int g=max(T[li].g,T[ri].g);
		if(g==T[li].g)Put(li,T[i].z);
		if(g==T[ri].g)Put(ri,T[i].z);
		T[i].z=0;
	}
	void PushUp(int i)
	{
		Node &o=T[i],&p=T[li],&q=T[ri];
		o.s=p.s+q.s;
		if(p.g>q.g)o.g=p.g,o.c=p.c,o.g2=max(p.g2,q.g);
		else if(p.g<q.g)o.g=q.g,o.c=q.c,o.g2=max(p.g,q.g2);
		else o.g=p.g,o.c=p.c+q.c,o.g2=max(p.g2,q.g2);
	}
	void Build(int i,int l,int r)
	{
		if(l==r){T[i].g=Inf,T[i].g2=-Inf;return;}
		int m=(l+r)>>1;
		Build(li,l,m);
		Build(ri,m+1,r);
		PushUp(i);
	}
	void Active(int i,int l,int r,int a)
	{
		if(l==r){T[i].c=1,T[i].s=T[i].g;return;}
		PushDown(i);
		int m=(l+r)>>1;
		if(a<=m)Active(li,l,m,a);
		else Active(ri,m+1,r,a);
		PushUp(i);
	}
	void Modify(int i,int l,int r,int a,int b,int x)
	{
		if(x>=T[i].g)return;
		if(a<=l&&r<=b&&x>T[i].g2){Put(i,x-T[i].g);return;}
		PushDown(i);
		int m=(l+r)>>1;
		if(a<=m)Modify(li,l,m,a,b,x);
		if(b>m)Modify(ri,m+1,r,a,b,x);
		PushUp(i);
	}
	ll Ask(int i,int l,int r,int a,int b)
	{
		if(a<=l&&r<=b)return T[i].s;
		PushDown(i);
		int m=(l+r)>>1;
		ll s=0;
		if(a<=m)s+=Ask(li,l,m,a,b);
		if(b>m)s+=Ask(ri,m+1,r,a,b);
		return s;
	}
	
	int F[MX];
	int Find(int x){return x==F[x]?x:F[x]=Find(F[x]);}
}S[2];

void Ins(int l,int r,int v)
{
	int k=0;
	if(v<0)k=1,v=-v;
	S[k].Modify(1,1,N,l,r,v);
	for(int i=S[k].Find(l);i<=r;i=S[k].Find(i))
	{
		S[k].F[i]=i+1;
		if(S[k^1].F[i]!=i)S[0].Active(1,1,N,i),S[1].Active(1,1,N,i);
	}
}
ll Query(int l,int r)
{
	return S[0].Ask(1,1,N,l,r)+S[1].Ask(1,1,N,l,r);
}

int main()
{
	scanf("%d",&M);
	Fr(i,0,1)
	{
		S[i].Build(1,1,N);
		Fr(j,1,N+1)S[i].F[j]=j;
	}
	int o,l,r,k;
	Fr(i,1,M)
	{
		scanf("%d%d%d",&o,&l,&r),--r;
		if(o==1)scanf("%d",&k),Ins(l,r,k);
		else printf("%lld\n",Query(l,r));
	}
	return 0;
}