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

const int MX=200100;
int N,K;
ll A[MX];


void Solve()
{
	scanf("%d%d",&N,&K);
	int k=min(K,N);
	ll ans=0;
	Fr(i,1,N)
	{
		scanf("%lld",&A[i]),A[i]+=A[i-1];
		if(i>=k)ans=max(ans,A[i]-A[i-k]);
	}
	ans+=(ll)K*(K-1)/2;
	if(K>N)ans-=(ll)(K-N)*(K-N-1)/2;
	printf("%lld\n",ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)Solve();
	return 0;
}