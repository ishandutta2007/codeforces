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

inline ll DivFloor(ll a,ll b)
{
	int s=0;
	if(a<0)s^=1,a=-a;
	if(b<0)s^=1,b=-b;
	return s?-(a/b+(a%b!=0)):a/b;
}
inline ll DivCeil(ll a,ll b)
{
	int s=0;
	if(a<0)s^=1,a=-a;
	if(b<0)s^=1,b=-b;
	return s?-(a/b):a/b+(a%b!=0);
}

const int MX=2000100;
void Fail(){printf("NO\n"),exit(0);}

int N,L;
struct Info{ll t,n,i,x,y;}A[MX];
inline bool operator<(const Info& a,const Info& b){return a.i<b.i;}
ll Ax[MX],Ay[MX];
char Sx[MX],Sy[MX];

void Solve(ll* X,char* S)
{
	Fr(i,1,N)
	{
		if((X[i]+A[i].t)&1)Fail();
		X[i]=(X[i]+A[i].t)/2;
	}
	ll l=0,r=L;
	Fr(i,0,N)
	{
		ll x=X[i+1]-X[i],n=A[i+1].n-A[i].n,t=A[i+1].i-A[i].i;
		if(n>0)l=max(l,DivCeil(x-t,n)),r=min(r,DivFloor(x,n));
		else if(n<0)l=max(l,DivCeil(x,n)),r=min(r,DivFloor(x-t,n));
		else if(!(0<=x&&x<=t))Fail();
	}
	if(l>r)Fail();
	Fr(i,0,N)
	{
		ll d=(X[i+1]-A[i+1].n*l)-(X[i]-A[i].n*l);
		Fr(j,A[i].i+1,A[i].i+d)S[j]=1;
	}
}

int main()
{
	scanf("%d%d",&N,&L);
	Fr(i,1,N)
	{
		scanf("%lld%lld%lld",&A[i].t,&A[i].x,&A[i].y);
		A[i].n=A[i].t/L,A[i].i=A[i].t%L;
	}
	sort(A+1,A+N+1);
	A[N+1].i=L,A[N+1].n=-1;
	Fr(i,1,N)Ax[i]=A[i].x+A[i].y,Ay[i]=A[i].y-A[i].x;
	Solve(Ax,Sx),Solve(Ay,Sy);
	Fr(i,1,L)putchar("DLRU"[Sx[i]*2+Sy[i]]);
	return 0;
}