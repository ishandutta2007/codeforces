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
const int N=100000;

char isp[N+100];
void Eratos()
{
	Fill(isp,1),isp[0]=isp[1]=0;
	for(int i=2;i*i<=N;++i)if(isp[i])
		for(int j=i*i;j<=N;j+=i)isp[j]=0;
}

int main()
{
	Eratos();
	int t;
	scanf("%d",&t);
	ll x;
	while(t--)
	{
		scanf("%lld",&x);
		ll y=1+x;
		while(!isp[y])++y;
		ll z=y+x;
		while(!isp[z])++z;
		printf("%lld\n",y*z);
	}
	return 0;
}