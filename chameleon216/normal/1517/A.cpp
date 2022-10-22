#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;


int Calc(ll x)
{
	if(x%2050)return -1;
	x/=2050;
	int c=0;
	while(x)c+=x%10,x/=10;
	return c;
}


int main()
{
	int t;
	ll x;
	scanf("%d",&t);
	while(t --> 0)
		scanf("%lld",&x),printf("%d\n",Calc(x));
	return 0;
}