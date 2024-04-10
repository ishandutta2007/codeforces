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

ll N;
bool Check(ll x)
{
	x=x*2+1;
	x=x*x;
	x=x/2+1;
	return x<=N;
}

ll Bin(ll l,ll r)
{
	--l,++r;
	while(r-l>1)
	{
		int m=(l+r)>>1;
		if(Check(m))l=m;
		else r=m;
	}
	return l;
}

void mian()
{
	scanf("%lld",&N);
	printf("%lld\n",Bin(1,N));
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}