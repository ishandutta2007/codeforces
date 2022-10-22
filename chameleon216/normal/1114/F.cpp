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
	void rc(char& c)
	{
		do c=gc();
		while(!isgraph(c));
	}
	template<typename T>
	void rd(T& x)
	{
		char c=gc(),l;
		for(l=0;!isdigit(c);c=gc())l=c;
		for(x=0;isdigit(c);c=gc())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void wc(char x)
	{
		if(r-ob==MB)fwrite(ob,1,MB,stdout),r=ob;
		*r++=x;
	}
	template<typename T>
	void wd(T x)
	{
		if(x<0)wc('-'),x=-x;
		int tp=0;
		do stk[++tp]=x%10+'0',x/=10;
		while(x);
		while(tp)wc(stk[tp--]);
	}
}IO;

const int MX=400100,Mod=1000000007;

ll Pow(ll a,ll b)
{
	a%=Mod;
	ll r=1;
	while(b)
	{
		if(b&1)r=r*a%Mod;
		a=a*a%Mod,b>>=1;
	}
	return r%Mod;
}
ll Inv(ll a){return Pow(a,Mod-2);}

const int W=300;
int P[W+100],J[W+100],pc;
void Euler()
{
	Fr(i,2,W)
	{
		if(!J[i])P[++pc]=i,J[i]=pc;
		Fr(j,1,pc)
		{
			int p=P[j];
			if(i*p>W)break;
			J[i*p]=j;
			if(i%p==0)break;
		}
	}
}

ll Factor(int x)
{
	ll r=0;
	while(x>1)r|=1ll<<J[x],x/=P[J[x]];
	return r;
}

int P_[W+100];
void Init()
{
	Fr(i,1,pc)P_[i]=Inv(P[i]);
}

int N,M,A[MX];

struct SegmentTree
{
	ll m,f,zm,zf;
	int len;
	void Mul_(ll x,ll y)
	{
		m=m*Pow(x,len)%Mod,zm=zm*x%Mod;
		f|=y,zf|=y;
	}
}T[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
inline void PushUp(int i)
{
	T[i].m=T[li].m*T[ri].m%Mod;
	T[i].f=T[li].f|T[ri].f;
}
inline void PushDown(int i)
{
	ll &zm=T[i].zm,&zf=T[i].zf;
	if(zm!=1||zf)T[li].Mul_(zm,zf),T[ri].Mul_(zm,zf),zm=1,zf=0;
}
void Build(int i,int l,int r)
{
	T[i].len=r-l+1,T[i].zm=1;
	if(l==r){T[i].m=A[l],T[i].f=Factor(A[l]);return;}
	Build(li,l,mid),Build(ri,mid+1,r);
	PushUp(i);
}
void Modify(int i,int l,int r,int a,int b,ll x,ll y)
{
	if(a<=l&&r<=b){T[i].Mul_(x,y);return;}
	PushDown(i);
	if(a<=mid)Modify(li,l,mid,a,b,x,y);
	if(b>mid)Modify(ri,mid+1,r,a,b,x,y);
	PushUp(i);
}
void Ask(int i,int l,int r,int a,int b,ll& rm,ll& rf)
{
	if(a<=l&&r<=b){rm=rm*T[i].m%Mod,rf|=T[i].f;return;}
	PushDown(i);
	if(a<=mid)Ask(li,l,mid,a,b,rm,rf);
	if(b>mid)Ask(ri,mid+1,r,a,b,rm,rf);
}


int main()
{
	IO.rd(N),IO.rd(M);
	Fr(i,1,N)IO.rd(A[i]);
	
	Euler();
	Init();
	
	Build(1,1,N);
	char o;
	int l,r,x;
	Fr(i,1,M)
	{
		IO.rc(o),IO.rd(l),IO.rd(r);
		if(o=='M')
		{
			IO.rd(x);
			Modify(1,1,N,l,r,x,Factor(x));
		}
		else
		{
			ll m=1,f=0;
			Ask(1,1,N,l,r,m,f);
			Fr(j,1,pc)if(f>>j&1)m=m*P_[j]%Mod*(P[j]-1)%Mod;
			IO.wd(m),IO.wc('\n');
		}
	}
	return 0;
}