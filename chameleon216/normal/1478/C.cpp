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
const int MX=210000;

int N;
ll D[MX],A[MX],B[MX];
ll E[MX];

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N*2)scanf("%lld",D+i);
	sort(D+1,D+1+N*2);
	Fr(j,1,N)
	{
		if(D[2*j]!=D[2*j-1])return 0;
		E[j]=D[2*j];
	}
//	Fr(i,1,N)printf("%lld ",E[i]);putchar('\n');
	Fl(i,N,2)
	{
		ll d=E[i]-E[i-1],q=2*(i-1);
//		printf("%lld %lld\n",d,q);
		if(d<=0)return 0;
		if(d%q!=0)return 0;
		A[i]=d/q;
	}
	ll d=0;
	Fr(i,2,N)d+=(N-i+1)*A[i];
//	printf("d=%lld\n",d);
	ll e=E[1]-d-d;
//	printf("e=%lld\n",e);
	if(e<=0)return 0;
	if(e%(2*N)!=0)return 0;
//	Fr(i,1,N)printf("%lld ",A[i]);putchar('\n');
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int res=mian();
		if(res)printf("YES\n");
		else printf("NO\n");
		Fr(i,1,N)D[i]=A[i]=B[i]=E[i]=0;
	}
	return 0;
}