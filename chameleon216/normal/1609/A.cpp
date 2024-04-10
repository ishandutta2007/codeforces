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

void Work()
{
	int n;
	scanf("%d",&n);
	ll mx=0,mul=1,sum=0;
	Fr(i,1,n)
	{
		ll a;
		scanf("%lld",&a);
		ll b=a&-a;
		mul*=b;
		mx=max(mx,a/b);
		sum+=a/b;
	}
	printf("%lld\n",sum-mx+mx*mul);
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)Work();
	return 0;
}