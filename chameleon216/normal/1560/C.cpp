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



int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		ll x,y=1;
		scanf("%lld",&x);
		while(y*y<x)++y;
		ll z=(y-1)*(y-1),w=y*y;
		if(x<=z+y)printf("%lld %lld\n",x-z,y);
		else printf("%lld %lld\n",y,w-x+1);
	}
	return 0;
}