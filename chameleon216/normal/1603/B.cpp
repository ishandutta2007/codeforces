#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;



int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		ll x,y,n;
		scanf("%lld%lld",&x,&y);
		if(x>y)n=x+y;
		else n=y-y%x/2;
		printf("%lld\n",n);
	}
	return 0;
}