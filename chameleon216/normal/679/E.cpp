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
	char ob[MB+100],*r,stk[128];
	FastIO(){p=q=ib,r=ob;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char Get()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename Tp>
	void Read(Tp& x)
	{
		char c=Get(),l=0;
		for(x=0;!isdigit(c);c=Get())l=c;
		for(;isdigit(c);c=Get())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	void Put(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename Tp>
	void Write(Tp x)
	{
		if(x<0)Put('-'),x=-x;
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)Put(stk[t--]);
	}
}IO;

const int MX=100100;
int N,M,A[MX];
ll P[12];
ll Dis(ll x){return *lower_bound(P+1,P+12,x)-x;}

#define li (i<<1)
#define ri (i<<1|1)
struct SegmentTree{ll v,d;char b;}T[MX*4];
void PushDown(int i)
{
	if(T[i].b)
	{
		T[li].b=T[ri].b=1;
		T[li].v=T[ri].v=T[i].v;
		T[li].d=T[ri].d=T[i].d;
		T[i].b=T[i].v=0;
	}
	else
	{
		T[li].v+=T[i].v,T[li].d-=T[i].v;
		T[ri].v+=T[i].v,T[ri].d-=T[i].v;
		T[i].v=0;
	}
}
inline void PushUp(int i){T[i].d=min(T[li].d,T[ri].d);}
void Build(int i,int l,int r)
{
	if(l==r){T[i].b=1,T[i].v=A[l],T[i].d=Dis(A[l]);return;}
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
	PushUp(i);
}
void Set(int i,int l,int r,int a,int b,int x)
{
	if(a<=l&&r<=b){T[i].b=1,T[i].v=x,T[i].d=Dis(x);return;}
	PushDown(i);
	int m=(l+r)>>1;
	if(a<=m)Set(li,l,m,a,b,x);
	if(b>m)Set(ri,m+1,r,a,b,x);
	PushUp(i);
}
bool Add(int i,int l,int r,int a,int b,int x)
{
	if(a<=l&&r<=b)
	{
		if(x<=T[i].d){T[i].v+=x,T[i].d-=x;return T[i].d;}
		if(T[i].b){T[i].v+=x,T[i].d=Dis(T[i].v);return T[i].d;}
	}
	PushDown(i);
	int m=(l+r)>>1,v=1;
	if(a<=m)v&=Add(li,l,m,a,b,x);
	if(b>m)v&=Add(ri,m+1,r,a,b,x);
	PushUp(i);
	return v;
}
ll Ask(int i,int l,int r,int a)
{
	if(T[i].b)return T[i].v;
	PushDown(i);
	int m=(l+r)>>1;
	return a<=m?Ask(li,l,m,a):Ask(ri,m+1,r,a);
}


int main()
{
	IO.Read(N),IO.Read(M);
	Fr(i,1,N)IO.Read(A[i]);
	P[0]=1;
	Fr(i,1,11)P[i]=P[i-1]*42;
	Build(1,1,N);
	int o,l,r,x;
	Fr(i,1,M)
	{
		IO.Read(o);
		if(o==1)IO.Read(l),IO.Write(Ask(1,1,N,l)),IO.Put('\n');
		else if(o==2)IO.Read(l),IO.Read(r),IO.Read(x),Set(1,1,N,l,r,x);
		else
		{
			IO.Read(l),IO.Read(r),IO.Read(x);
			while(!Add(1,1,N,l,r,x));
		}
	}
	return 0;
}