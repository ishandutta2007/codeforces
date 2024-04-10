#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;

int mian()
{
	ll a,b,c,p;
	scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
	ll ta=(p%a==0?a:p%a);
	ll tb=(p%b==0?b:p%b);
	ll tc=(p%c==0?c:p%c);
	printf("%lld\n",min(min(a-ta,b-tb),c-tc));
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
}