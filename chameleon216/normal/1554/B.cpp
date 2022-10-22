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

const int MX=100100;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int N,K,A[MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%d",&N,&K);
		Fr(i,1,N)scanf("%d",&A[i]);
		ll ans=-Inf;
		Fr(i,max(1,N-2*K),N)Fr(j,i+1,N)
			ans=max(ans,(ll)i*j-(ll)K*(A[i]|A[j]));
		printf("%lld\n",ans);
	}
	return 0;
}