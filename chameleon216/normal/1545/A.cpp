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
int N;
int A[2][MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)scanf("%d",&A[i&1][i>>1]);
		sort(A[N&1],A[N&1]+(N>>1)+1);
		sort(A[(N-1)&1],A[(N-1)&1]+((N-1)>>1)+1);
		int b=1;
		Fo(i,1,N)
		{
			int j=i+1;
			if(A[i&1][i>>1]>A[j&1][j>>1]){b=0,printf("NO\n");break;}
		}
		if(b)printf("YES\n");
	}
	return 0;
}