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

int main()
{
	ll n,p,w,d;
	scanf("%lld%lld%lld%lld",&n,&p,&w,&d);
	Fo(y,0,w)if((p-d*y)%w==0)
	{
		ll x=(p-d*y)/w,z=n-x-y;
		if(x>=0&&z>=0){printf("%lld %d %lld\n",x,y,z);return 0;}
	}
	printf("-1\n");
	return 0;
}