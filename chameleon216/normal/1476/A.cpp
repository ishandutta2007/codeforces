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

int mian()
{
	ll N,K;
	scanf("%lld%lld",&N,&K);
	if(K<N)
	{
		if(N%K==0)printf("1\n");
		else printf("2\n");
	}
	else printf("%lld\n",(K-1)/N+1);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
}