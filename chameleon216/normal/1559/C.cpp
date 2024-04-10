#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;

const int MX=100100;
int N,A[MX];


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)scanf("%d",&A[i]);
		if(!A[N])
		{
			Fr(i,1,N+1)printf("%d ",i);
		}
		else if(A[1])
		{
			printf("%d ",N+1);
			Fr(i,1,N)printf("%d ",i);
		}
		else
		{
			int b=1;
			Fo(i,1,N)
			{
				if(!A[i]&&A[i+1])
				{
					Fr(j,1,i)printf("%d ",j);
					printf("%d ",N+1);
					Fr(j,i+1,N)printf("%d ",j);
					b=0;break;
				}
			}
			if(b)printf("-1");
		}
		putchar('\n');
	}
	return 0;
}