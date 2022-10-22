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
const int MX=120000;
int N;
ll A[MX],B[MX],bc;


int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",A+i);
	sort(A+1,A+1+N);
	ll a=0,s=0;
	Fl(i,N,1)
	{
		if(a&&a-A[i]<=1)B[++bc]=A[i],a=0;
		else a=A[i];
	}
//	Fr(i,1,bc)printf("%lld ",B[i]);putchar('\n');
	for(int i=1;i<bc;i+=2)
		s+=B[i]*B[i+1];
	printf("%lld\n",s);
	return 0;
}