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
const int Mod=1000000007;


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		ll a=1,b,n,r=0;
		scanf("%lld%lld",&n,&b);
		while(b)
		{
			if(b&1)r=(r+a)%Mod;
			a=a*n%Mod,b>>=1;
		}
		printf("%lld\n",r);
	}
	return 0;
}