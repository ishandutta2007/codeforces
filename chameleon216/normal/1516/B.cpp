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

const int MX=2100;
int N,A[MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)scanf("%d",&A[i]),A[i]^=A[i-1];
		if(!A[N])printf("YES\n");
		else
		{
			int b=0;
			Fl(i,N,1)
			{
				if(b==0&&A[i]==0)b=1;
				else if(b==1&&A[i]==A[N]){b=2;break;}
			}
			printf(b==2?"YES\n":"NO\n");
		}
	}
	return 0;
}