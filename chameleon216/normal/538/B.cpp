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

int N,D[10],dc;

int main()
{
	scanf("%d",&N);
	do D[++dc]=N%10;
	while(N/=10);
	int ans=0;
	Fr(i,1,dc)ans=max(ans,D[i]);
	printf("%d\n",ans);
	Fr(i,1,ans)
	{
		int x=0;
		Fl(j,dc,1)
		{
			x=x*10+!!D[j];
			if(D[j])--D[j];
		}
		printf("%d ",x);
	}
	putchar('\n');
	return 0;
}