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
const int MX=5000;

int N;
ll A[MX],B[MX];

int mian()
{
	scanf("%d",&N);
	Fill(A,0),Fill(B,0);
	Fr(i,1,N)scanf("%lld%lld",A+i,B+i);
	if(N%2==1){printf("1\n");return 0;}
	sort(A+1,A+1+N);
	sort(B+1,B+1+N);
	ll x=A[N/2+1]-A[N/2]+1;
	ll y=B[N/2+1]-B[N/2]+1;
	printf("%lld\n",x*y);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}