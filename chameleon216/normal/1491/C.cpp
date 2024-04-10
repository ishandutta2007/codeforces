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
const int MX=12000;
ll ans=0;
ll A[MX],R[MX];
int N;

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",A+i);
	Fr(i,1,N)
	{
		ll a=A[i];
		if(a>N)R[i]-=a-N,a=N;
		while(a>1)++R[i+a],--R[i],--a;
		if(R[i]>0)R[i+1]+=R[i],R[i]=0;
		if(R[i]<0)ans+=-R[i];
	//	Fr(j,1,N)printf("%lld ",R[j]);putchar('\n');
	}
	printf("%lld\n",ans);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mian();
		Fill(R,0),ans=0;
	}
	return 0;
}