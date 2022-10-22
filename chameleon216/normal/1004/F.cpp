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

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	FastIO(){p=q=ib,r=ob;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char gc()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename Tp>
	void rd(Tp& x)
	{
		char c=gc(),l=0;
		for(x=0;!isdigit(c);c=gc())l=c;
		for(;isdigit(c);c=gc())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	void wc(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename Tp>
	void wd(Tp x)
	{
		if(x<0)wc('-'),x=-x;
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)wc(stk[t--]);
	}
}IO;

const int MX=100100;
int N,M,X,A[MX];

struct Data{int v[21],n[21],c;};
inline Data operator+(Data a,const Data &b)
{
	if(!a.c)return b;
	if(!b.c)return a;
	Fr(i,0,b.c-1)
	{
		if((a.v[a.c-1]|b.v[i])!=a.v[a.c-1])
			a.v[a.c]=a.v[a.c-1]|b.v[i],a.n[a.c++]=b.n[i];
		else a.n[a.c-1]+=b.n[i];
	}
	return a;
}
inline ll Calc(const Data &a,const Data &b)
{
	ll s=0;
	for(int i=0,j=b.c-1,n=0;i<a.c;++i)
	{
		while(j>=0&&(a.v[i]|b.v[j])>=X)n+=b.n[j--];
		s+=(ll)a.n[i]*n;
	}
	return s;
}

#define li (i<<1)
#define ri (i<<1|1)
struct Segment
{
	Data l,r;
	ll s;
	void Single(int x)
	{
		l.v[0]=r.v[0]=x;
		l.n[0]=r.n[0]=1;
		l.c=r.c=1,s=(x>=X);
	}
}T[MX*4];
void PushUp(int i)
{
	T[i].l=T[li].l+T[ri].l;
	T[i].r=T[ri].r+T[li].r;
	T[i].s=T[li].s+T[ri].s+Calc(T[li].r,T[ri].l);
}
void Build(int i,int l,int r)
{
	if(l==r){T[i].Single(A[l]);return;}
	int m=(l+r)>>1;
	Build(li,l,m);
	Build(ri,m+1,r);
	PushUp(i);
}
void Modify(int i,int l,int r,int a,int v)
{
	if(l==r){T[i].Single(v);return;}
	int m=(l+r)>>1;
	if(a<=m)Modify(li,l,m,a,v);
	else Modify(ri,m+1,r,a,v);
	PushUp(i);
}
void Query(int i,int l,int r,int a,int b,Data &d,ll &s)
{
	if(b<l||r<a)return;
	if(a<=l&&r<=b){s+=T[i].s+Calc(d,T[i].l),d=T[i].r+d;return;}
	int m=(l+r)>>1;
	Query(li,l,m,a,b,d,s);
	Query(ri,m+1,r,a,b,d,s);
}

int main()
{
	IO.rd(N),IO.rd(M),IO.rd(X);
	Fr(i,1,N)IO.rd(A[i]);
	Build(1,1,N);
	int o,l,r;
	ll s;
	Data d;
	Fr(i,1,M)
	{
		IO.rd(o),IO.rd(l),IO.rd(r);
		if(o==1)Modify(1,1,N,l,r);
		else
		{
			s=0,d.c=0;
			Query(1,1,N,l,r,d,s);
			IO.wd(s),IO.wc('\n');
		}
	}
	return 0;
}