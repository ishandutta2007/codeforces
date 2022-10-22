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

const int P=1000000007;
ll Pow(ll a,ll b)
{
	ll r=1;
	a%=P;
	while(b)
	{
		if(b&1)r=r*a%P;
		a=a*a%P,b>>=1;
	}
	return r%P;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int n,m,cnt=0;
		char c;
		scanf("%d%d",&n,&m);
		Fr(i,1,n)Fr(j,1,m)
			scanf(" %c",&c),cnt+=c=='#';
		printf("%lld\n",(Pow(2,cnt)-(cnt==n*m)+P)%P);
	}
	return 0;
}