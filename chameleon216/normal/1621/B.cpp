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

const int Inf=0x3f3f3f3f;
void Work()
{
	int n;
	ll l,r,c;
	scanf("%d",&n);
	ll len=-Inf,cl=0,a=Inf,ca=0,b=-Inf,cb=0;
	Fr(i,1,n)
	{
		scanf("%lld%lld%lld",&l,&r,&c);
		if(l<a||(l==a&&c<ca))a=l,ca=c;
		if(r>b||(r==b&&c<cb))b=r,cb=c;
		if(r-l+1>len||(r-l+1==len&&c<cl))len=r-l+1,cl=c;
		if(len==b-a+1&&cl<ca+cb)printf("%lld\n",cl);
		else printf("%lld\n",ca+cb);
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
		Work();
	return 0;
}