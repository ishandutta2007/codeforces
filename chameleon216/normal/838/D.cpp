#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
#define Mset(i,x) memset((i),(x),sizeof(i))
using namespace std;
typedef long long ll;
const int MX=120000,Mod=1000000007;

ll Pow(ll a,ll p)
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

ll Calc(ll n,ll m)
{
	return (n-m+1)*Pow(n+1,m-1)%Mod*Pow(2,m)%Mod;
}


int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	printf("%lld\n",Calc(n,m));
	return 0;
}