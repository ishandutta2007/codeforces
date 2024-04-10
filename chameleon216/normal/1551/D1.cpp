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
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		if(n&1)swap(n,m),k=n*m/2-k;
		printf(~k&1&&k<=(m&~1)*n/2?"YES\n":"NO\n");
	}
	return 0;
}