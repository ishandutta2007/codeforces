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
const int MX=300000;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int N;
ll K;
ll X[MX];

int mian()
{
	scanf("%d%lld",&N,&K);
	Fr(i,1,N)scanf("%lld",X+i);
	sort(X+1,X+1+N);
	ll g=X[2]-X[1];
	Fr(i,3,N)g=gcd(g,X[i]-X[1]);
	//printf("%lld\n",g);
	if((K-X[1])%g==0)printf("YES\n");
	else printf("NO\n");
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mian();
		Fr(i,1,N)X[i]=0;
	}
}