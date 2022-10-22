#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=200100,Mod=1000000007;

ll Pow(ll a,ll b)
{
	ll r=1;
	a%=Mod;
	while(b)
	{
		if(b&1)r=r*a%Mod;
		a=a*a%Mod,b>>=1;
	}
	return r%Mod;
}

int mian()
{
	int n,m,w=0;
	scanf("%d%d",&n,&m);
	Fr(i,1,m)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		w|=x;
	}
	printf("%lld\n",w*Pow(2,n-1)%Mod);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)mian();
}