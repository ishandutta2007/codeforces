#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;

void solve(ll n,ll& a,ll& b,ll& c)
{
	if(n==4)a=1,b=1,c=2;
	else if(n&1)a=b=n/2,c=1;
	else solve(n/2,a,b,c),a*=2,b*=2,c*=2;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,k,a,b,c;
		scanf("%lld%lld",&n,&k);
		solve(n,a,b,c);
		printf("%lld %lld %lld\n",a,b,c);
	}
	return 0;
}