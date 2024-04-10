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
		int n;
		ll x,s=0;
		scanf("%d",&n);
		Fr(i,1,n)scanf("%lld",&x),s+=x;
		printf("%d\n",!!(s%n));
	}
	return 0;
}