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
const int MX=150;

int N;
ll K,X[MX];

int mian()
{
	scanf("%d%lld",&N,&K);
	Fr(i,1,N)scanf("%lld",X+i);
	ll sum=X[1];
	ll ans=0;
	Fr(i,2,N)
	{
		if(100*X[i]>K*sum)
		{
			ll e=(X[i]*100-1)/K+1;
			ans+=e-sum;
	//		printf("+%lld\n",e-sum);
			sum=e;
		}
		sum+=X[i];
	//	printf("%lld\n",sum);
	}
	printf("%lld\n",ans);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian(),Fill(X,0);
}