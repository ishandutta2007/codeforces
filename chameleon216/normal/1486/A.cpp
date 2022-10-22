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
const int MX=21000;

int N;
ll A[MX];

int mian()
{
	Fill(A,0);
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",A+i);
	A[0]=-1;
	Fr(i,1,N)
	{
		if(A[i]<=A[i-1])return 0;
		ll delta=A[i]-(A[i-1]+1);
		A[i]-=delta,A[i+1]+=delta;
	}
	//Fr(i,1,N+1)printf("%lld ",A[i]);
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
	}
}