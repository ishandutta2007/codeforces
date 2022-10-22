#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=1100;
int N,A[MX];

bool IsPrime(int x)
{
	if(x<2)return 0;
	for(int i=2;i*i<=x;++i)
		if(x%i==0)return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)scanf("%d",&A[i]);
		int s=0;
		Fr(i,1,N)s+=A[i];
		if(IsPrime(s))
		{
			printf("%d\n",N-1);
			int b=1;
			Fr(i,1,N)
			{
				if((A[i]&1)&&b)b=0;
				else printf("%d ",i);
			}
			putchar('\n');
		}
		else
		{
			printf("%d\n",N);
			Fr(i,1,N)printf("%d ",i);
			putchar('\n');
		}
		Fr(i,1,N)A[i]=0;
	}
	return 0;
}