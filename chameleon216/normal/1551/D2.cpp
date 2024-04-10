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


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int n,m,k,q=0;
		scanf("%d%d%d",&n,&m,&k);
		if(n&1)swap(n,m),k=n*m/2-k,q=1;
		if(~k&1&&k<=(m&~1)*n/2)
		{
			printf("YES\n");
			if(q)Fo(j,0,m)
			{
				Fo(i,0,n)putchar('a'+(i<<1&4)+(j&2)+((j&1)^((i^j)&((i>>1)+(j>>1)*(n>>1)<(k>>1)))));
				putchar('\n');
			}
			else Fo(i,0,n)
			{
				Fo(j,0,m)putchar('a'+(i<<1&4)+(j&2)+((j&1)^((i^j)&((i>>1)+(j>>1)*(n>>1)<(k>>1)))));
				putchar('\n');
			}
		}
		else printf("NO\n");
	}
	return 0;
}