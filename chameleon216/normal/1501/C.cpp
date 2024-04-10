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
const int MX=220000,MY=5500000;
int N;
int A[MX];
int X[MY],Y[MY];

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",A+i);
	Fl(i,N,1)Fr(j,i+1,N)
	{
		int sum=A[i]+A[j];
		if(X[sum]==0)
			X[sum]=i,Y[sum]=j;
		else if(X[sum]!=i&&X[sum]!=j&&Y[sum]!=i&&Y[sum]!=j)
		{
			printf("YES\n");
			printf("%d %d %d %d\n",X[sum],Y[sum],i,j);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}