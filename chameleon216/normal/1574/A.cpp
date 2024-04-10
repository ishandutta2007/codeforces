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


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int n;
		scanf("%d",&n);
		Fr(i,1,n)
		{
			Fr(j,1,i-1)putchar('(');
			Fr(j,i,n)printf("()");
			Fr(j,1,i-1)putchar(')');
			putchar('\n');
		}
	}
	return 0;
}