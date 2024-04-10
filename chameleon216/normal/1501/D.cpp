#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define MOD(x,m) (((x)%(m)+(m))%(m))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int MX=1100000;

ll mul(ll a,ll b,ll mod)
{
	a=MOD(a,mod),b=MOD(b,mod);
	return ((ull)a*b-(ull)((ld)a*b/mod)*mod+mod)%mod;
}

void exgcd(ll a,ll b,ll& x,ll& y,ll& g)
{
	if(b)exgcd(b,a%b,y,x,g),y-=x*(a/b);
	else g=a,x=1,y=0;
}

bool Merge(ll a1,ll m1,ll a2,ll m2,ll& a,ll& m)
{
	ll c=a2-a1,x,y,g;
	
	exgcd(m1,m2,x,y,g);
	if(c%g)return 0;
	ll c_=c/g,b_=m2/g;
	x=mul(x,c_,b_);
	
	a=a1+x*m1;
	m=m1/g*m2;
	return 1;
}


ll N,M,K;
ll A[MX],B[MX];
ll id[MX];

ll BB[MX],AA[MX],MM[MX];

void Init()
{
	Fr(i,1,M)
	{
		if(B[i]==-1)BB[i]=0;
		else BB[i]=Merge(B[i],N,i-1,M,AA[i],MM[i]);
	}
}

ll Check(ll t)
{
	ll sum=0;
	Fr(i,1,M)
	{
		if(!BB[i])continue;
		ll a=AA[i],m=MM[i];
		sum+=t/m+(t%m>=a);
	}
	return sum;
}

ll Bin(ll l,ll r)
{
	--l,++r;
	while(r-l>1)
	{
		ll m=(l+r)>>1;
		if(m-Check(m)+1>=K)r=m;
		else l=m;
	}
	return r;
}

int main()
{
	scanf("%lld%lld%lld",&N,&M,&K);
	Fr(i,1,N)scanf("%lld",A+i);
	Fr(i,1,M)scanf("%lld",B+i);
	if(N<M)
	{
		swap(N,M);
		Fr(i,1,N)swap(A[i],B[i]);
	}
	Fr(i,1,N)id[A[i]]=i;
	Fr(i,1,M)B[i]=id[B[i]];
	Fr(i,1,M)B[i]--;
	//Fr(i,1,M)printf("%lld ",B[i]);putchar('\n');
	Init();
	//printf("%d\n",Ask(1,41));
	printf("%lld\n",Bin(0,1e18)+1);
	return 0;
}