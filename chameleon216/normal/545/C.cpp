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
int N;
ll X[MX],H[MX];

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld%lld",&X[i],&H[i]);
	X[N+1]=Inf;
	ll r=-Inf,c=0;
	Fr(i,1,N)
	{
		if(X[i]-H[i]>r)r=X[i],++c;
		else if(X[i]+H[i]<X[i+1])r=X[i]+H[i],++c;
		else r=X[i];
	}
	printf("%lld\n",c);
	return 0;
}