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
		ll n;
		scanf("%lld",&n);
		printf("%lld %lld\n",-n+1,n);
	}
	return 0;
}