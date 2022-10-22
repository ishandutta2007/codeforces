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
		int a,b=0;
		scanf("%d",&a);
		if(!(a&(a-1)))for(int c=a;c>1;c>>=1)++b;
		printf(!(a&1)&&!(b&1)?"Alice\n":"Bob\n");
	}
	return 0;
}