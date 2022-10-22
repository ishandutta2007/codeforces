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


ll mian(ll s,ll k)
{
	if(s++==k)return 0;
	return s/(2*k)*k+min(s%(2*k),k)-1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		ll s,n,k;
		scanf("%lld%lld%lld",&s,&n,&k);
		ll x=mian(s,k);
		printf(n<=x?"NO\n":"YES\n");
	}
}