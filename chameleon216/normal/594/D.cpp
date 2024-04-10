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
using namespace std;
typedef long long ll;
const int MX=2e5+100,MXA=1e6+100,Mod=1e9+7;

int N,M;
int X[MX];

char isp[MXA];
int P[MX],pcnt;
int P_[MXA];
void Euler(int N)
{
	Fill(isp,1),isp[0]=isp[1]=0;
	Fr(i,2,N)
	{
		if(isp[i])P[++pcnt]=i,P_[i]=pcnt;
		Fr(j,1,pcnt)
		{
			int p=P[j];
			if(i*p>N)break;
			isp[i*p]=0;
			if(i%p==0)break;
		}
	}
}

int F[100],fcnt;
void Factor(int n)
{
	fcnt=0;
	Fr(i,1,pcnt)
	{
		int p=P[i];
		if(p*p>n)break;
		while(n%p==0)F[++fcnt]=i,n/=p;
	}
	if(n>1)F[++fcnt]=P_[n];
}

ll qpow(ll a,ll p)
{
	ll r=1;
	a%=Mod;
	while(p)
	{
		if(p&1)r=r*a%Mod;
		a=a*a%Mod,p>>=1;
	}
	return r%Mod;
}
ll Inv(ll a){return qpow(a,Mod-2);}
ll inv[MXA];


struct Bit
{
	ll v[MX];
	int lowbit(int x){return x&-x;}
	Bit(){fill(v,v+MX,1);}
	void mul(int i,ll x)
	{
		while(i<=N)v[i]*=x,v[i]%=Mod,i+=lowbit(i);
	}
	ll ask(int i)
	{
		ll res=1;
		while(i)res*=v[i],res%=Mod,i-=lowbit(i);
		return res;
	}
	ll ask(int a,int b)
	{
		return ask(b)*Inv(ask(a-1))%Mod;
	}
}bit;

ll ans[MX];
struct Query{int l,id,nx;}Q[MX];
int H[MX],qc;
void add(int l,int r,int id)
{
	Q[++qc].l=l,Q[qc].id=id,Q[qc].nx=H[r],H[r]=qc;
}
#define Fq(i,x) for(int i=H[x];i;i=Q[i].nx)

int A[MX];
int t[MX];
ll Mul[MX];

void Init()
{
	inv[1]=1; ll p=Mod;
	Fr(i,2,1000000)inv[i]=(p-p/i)*inv[p%i]%p;
	
	Fr(i,1,N)
	{
		Factor(X[i]);
		Fr(j,1,fcnt)if(A[F[j]]!=i)
		{
			int f=F[j];
			
//			printf("%d %d %lld\n",f,P[f],inv[P[f]]);
			if(A[f])bit.mul(A[f],inv[P[f]-1]*P[f]%Mod);
			A[f]=i;
			bit.mul(A[f],(P[f]-1)*inv[P[f]]%Mod);
		}
//		Fr(k,1,N)printf("%d ",A[k]);
//		printf("\n");
//		Fr(j,1,N)printf("%lld ",bit.ask(1,j));
//		printf("\n");

		Fq(j,i)
		{
			int l=Q[j].l,r=i,id=Q[j].id;
			ans[id]=Mul[r]*Inv(Mul[l-1])%Mod*bit.ask(l,r)%Mod;
		}
	}
}


int main()
{
	Euler(1e6);
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",X+i);
	
	Mul[0]=1;
	Fr(i,1,N)Mul[i]=X[i]*Mul[i-1]%Mod;
	
	scanf("%d",&M);
	int a,b;
	Fr(i,1,M)scanf("%d%d",&a,&b),add(a,b,i);//printf("%lld\n",Mul[b]*Inv(Mul[a-1])%Mod*bit.ask(a,b)%Mod);
	Init();
	Fr(i,1,M)printf("%lld\n",ans[i]);
	
	return 0;
}