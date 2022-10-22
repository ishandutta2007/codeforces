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
const int Inf=1e9;

int N;

int main()
{
	scanf("%d",&N);
	int l=0,r=N+1;
	int x=Inf,y=Inf+1;
	while(r-l>2)
	{
		int m=(l+r)>>1,z,w;
		printf("? %d\n",m),fflush(stdout);
		scanf("%d",&z);
		printf("? %d\n",m+1),fflush(stdout);
		scanf("%d",&w);
		if(z<w)r=m+1;
		else l=m;
	}
	printf("! %d\n",(l+r)>>1),fflush(stdout);
	return 0;
}