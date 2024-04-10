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
const int MX=20000;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll gcdsum(ll x)
{
	ll sum=0;
	for(ll y=x;y;y/=10)sum+=y%10;
	return gcd(x,sum);
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		while(1)
		{
			if(gcdsum(n)>1)break;
			++n;
		}
		printf("%lld\n",n);
	}
	return 0;
}