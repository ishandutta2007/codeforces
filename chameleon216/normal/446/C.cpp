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
const int MB=1<<21;
struct FastIO
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int MX=300100,Mod=1000000009;
const int Sq5=383008016,Q1=691504013,Q2=308495997;
const int Isq5=276601605;//,I1=691504013,I2=308495997;
// Inv(Q1-1)==Q1 Inv(Q2-1)==Q2

int N,M;
ll A[MX];

ll P1[MX],P2[MX];
void Init()
{
	P1[0]=P2[0]=1;
	Fr(i,1,N)
	{
		P1[i]=P1[i-1]*Q1%Mod;
		P2[i]=P2[i-1]*Q2%Mod;
	}
}


struct Segment
{
	ll v,z1,z2;
	int l,r;
	void add1(ll x) //add x*(1+p+p^2+...+p^(len-1))
	{
		v+=x*(P1[r-l+1]-1+Mod)%Mod*Q1%Mod,v%=Mod;
		z1+=x,z1%=Mod;
	}
	void add2(ll x)
	{
		v+=x*(P2[r-l+1]-1+Mod)%Mod*Q2%Mod,v%=Mod;
		z2+=x,z2%=Mod;
	}
}T[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
void PushUp(int i){T[i].v=(T[li].v+T[ri].v)%Mod;}
void PushDown(int i)
{
	Segment &t=T[i],&x=T[li],&y=T[ri];
	if(t.z1)x.add1(t.z1),y.add1(t.z1*P1[x.r-x.l+1]%Mod),t.z1=0;
	if(t.z2)x.add2(t.z2),y.add2(t.z2*P2[x.r-x.l+1]%Mod),t.z2=0;
}
void Build(int i,int l,int r)
{
	T[i].l=l,T[i].r=r;
	if(l==r){T[i].v=A[l];return;}
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
	PushUp(i);
}
void Add(int i,int a,int b)
{
	if(a<=T[i].l&&T[i].r<=b)
	{
		T[i].add1(P1[T[i].l-a+1]);
		T[i].add2((Mod-P2[T[i].l-a+1])%Mod);
		return;
	}
	PushDown(i);
	if(a<=T[li].r)Add(li,a,b);
	if(b>=T[ri].l)Add(ri,a,b);
	PushUp(i);
}
ll Ask(int i,int a,int b)
{
	if(a<=T[i].l&&T[i].r<=b)return T[i].v;
	PushDown(i);
	ll res=0;
	if(a<=T[li].r)res+=Ask(li,a,b);
	if(b>=T[ri].l)res+=Ask(ri,a,b);
	return res%Mod;
}


int main()
{
	IO>>N>>M;
	Fr(i,1,N)IO>>A[i],A[i]*=Sq5,A[i]%=Mod;
	Init();
	Build(1,1,N);
	
	Fr(i,1,M)
	{
		int o,l,r;
		IO>>o>>l>>r;
		if(o==1)Add(1,l,r);
		else printf("%lld\n",Ask(1,l,r)*Isq5%Mod);
	}
	return 0;
}