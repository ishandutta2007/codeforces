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

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char Get()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c=Get(),l=0;
		for(x=0;!isdigit(c);c=Get())l=c;
		for(;isdigit(c);c=Get())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int MX=500100,Inf=0x3f3f3f3f;
int N,K,A[MX],B[MX];

struct Segment
{
	int s,z; //, 
	int a,b; //A/B
	int a_,b_; //[l,a').s>sA, [b',r].s>sB
	int ui,uj; //
	int vi,vj; //()
	int wi,wj; //([vl,vr).s>s)
}T[MX*4];
#define li (i<<1)
#define ri (i<<1|1)
void Put(int i,int x){T[i].s+=x,T[i].z+=x;}
void PushDown(int i){if(T[i].z)Put(li,T[i].z),Put(ri,T[i].z),T[i].z=0;}
void PushUp(int i)
{
	Segment &o=T[i],&p=T[li],&q=T[ri];
	o.a=A[p.a]<A[q.a]?p.a:q.a;
	o.b=B[p.b]<B[q.b]?p.b:q.b;
	o.ui=p.a,o.uj=q.b;
	if(A[o.ui]+B[o.uj]>A[p.ui]+B[p.uj])o.ui=p.ui,o.uj=p.uj;
	if(A[o.ui]+B[o.uj]>A[q.ui]+B[q.uj])o.ui=q.ui,o.uj=q.uj;
	o.vi=q.a,o.vj=p.b;
	if(A[o.vi]+B[o.vj]>A[p.vi]+B[p.vj])o.vi=p.vi,o.vj=p.vj;
	if(A[o.vi]+B[o.vj]>A[q.vi]+B[q.vj])o.vi=q.vi,o.vj=q.vj;
	if(p.s<q.s)
	{
		o.s=p.s;
		o.a_=p.a_;
		o.b_=B[p.b_]<B[q.b]?p.b_:q.b;
		o.wi=q.a,o.wj=p.b_;
		if(A[o.wi]+B[o.wj]>A[p.wi]+B[p.wj])o.wi=p.wi,o.wj=p.wj;
		if(A[o.wi]+B[o.wj]>A[q.vi]+B[q.vj])o.wi=q.vi,o.wj=q.vj;
	}
	else if(p.s>q.s)
	{
		o.s=q.s;
		o.a_=A[p.a]<A[q.a_]?p.a:q.a_;
		o.b_=q.b_;
		o.wi=q.a_,o.wj=p.b;
		if(A[o.wi]+B[o.wj]>A[p.vi]+B[p.vj])o.wi=p.vi,o.wj=p.vj;
		if(A[o.wi]+B[o.wj]>A[q.wi]+B[q.wj])o.wi=q.wi,o.wj=q.wj;
	}
	else
	{
		o.s=p.s;
		o.a_=p.a_;
		o.b_=q.b_;
		o.wi=q.a_,o.wj=p.b_;
		if(A[o.wi]+B[o.wj]>A[p.wi]+B[p.wj])o.wi=p.wi,o.wj=p.wj;
		if(A[o.wi]+B[o.wj]>A[q.wi]+B[q.wj])o.wi=q.wi,o.wj=q.wj;
	}
}
void Build(int i,int l,int r)
{
	if(l==r)
	{
		Segment &o=T[i];
		o.a=o.b=o.a_=o.ui=o.uj=l;
		return;
	}
	int m=(l+r)>>1;
	Build(li,l,m);
	Build(ri,m+1,r);
	PushUp(i);
}
void Add(int i,int l,int r,int a,int b,int x)
{
	if(a<=l&&r<=b){Put(i,x);return;}
	int m=(l+r)>>1;
	PushDown(i);
	if(a<=m)Add(li,l,m,a,b,x);
	if(b>m)Add(ri,m+1,r,a,b,x);
	PushUp(i);
}
void Update(int i,int l,int r,int a)
{
	if(l==r)return;
	int m=(l+r)>>1;
	PushDown(i);
	if(a<=m)Update(li,l,m,a);
	else Update(ri,m+1,r,a);
	PushUp(i);
}

int main()
{
	IO>>N>>K;
	Fr(i,1,N)IO>>A[i];
	Fr(i,1,N)IO>>B[i];
	A[0]=B[0]=Inf;
	
	Build(1,1,N);
	ll ans=0;
	Fr(i,1,K)
	{
		int l=T[1].ui,r=T[1].uj;
		if(A[l]+B[r]>A[T[1].wi]+B[T[1].wj])
			l=T[1].wi,r=T[1].wj;
		ans+=A[l]+B[r];
//		printf("%d %d: %d\n",l,r,A[l]+B[r]);
		if(l<r)Add(1,1,N,l,r-1,1);
		if(l>r)Add(1,1,N,r,l-1,-1);
		A[l]=Inf,Update(1,1,N,l);
		B[r]=Inf,Update(1,1,N,r);
	}
	printf("%lld\n",ans);
	return 0;
}