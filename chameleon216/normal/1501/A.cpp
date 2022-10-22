#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=120;
int N;
ll A[MX],B[MX],T[MX];

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld%lld",A+i,B+i);
	Fr(i,1,N)scanf("%lld",T+i);
	ll t=0;
	Fr(i,1,N)
	{
		t+=A[i]-B[i-1]+T[i];
		ll tmp=(B[i]-A[i]+1)/2;
		if(i!=N)t=max(B[i],t+tmp);
	}
	printf("%lld\n",t);
	Fr(i,1,N)A[i]=B[i]=T[i]=0;
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}