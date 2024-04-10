#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

/*bool KGood(ll x,ll k)
{
	ll a=k*(k+1)/2,d=(k&1?0:k/2);
	return x>=a&&x%k==d;
}

bool Check(int x)
{
	for(int k=2;k*(k+1)/2<=x;++k)
		if(KGood(x,k))return 1;
	return 0;
}*/

ll Judge(ll x)
{
	ll a=x&-x,b=x/a;
	if(b==1)return -1;
//	if(KGood(x,a*2))return a*2;
//	if(b!=1&&KGood(x,b))return b;
	return min(a*2,b);
}

int main()
{
//	Fr(i,2,10000)if(!Check(i))printf(";%d\n",i);
//	Fr(i,2,10000)if(Judge(i)==-1)printf(":%d\n",i);
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		ll x;
		scanf("%lld",&x);
		printf("%lld\n",Judge(x));
	}
	return 0;
}