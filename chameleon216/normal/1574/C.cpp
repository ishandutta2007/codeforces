#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;

const int MX=200100;
int N,M;
ll A[MX],sum;

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",&A[i]),sum+=A[i];
	sort(A+1,A+N+1);
	scanf("%d",&M);
	Fr(i,1,M)
	{
		ll x,y,r=0x3f3f3f3f3f3f3f3fll;
		scanf("%lld%lld",&x,&y);
		int p=lower_bound(A+1,A+N+1,x)-A;
		if(p-1!=0)r=min(r,max(0ll,x-A[p-1])+max(0ll,y-(sum-A[p-1])));
		if(p!=N+1)r=min(r,max(0ll,y-(sum-A[p])));
		printf("%lld\n",r);
	}
	return 0;
}