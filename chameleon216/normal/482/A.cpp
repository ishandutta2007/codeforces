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
	int n,k;
	scanf("%d%d",&n,&k);
	int l=1,r=n;
	for(;k>1;--k)printf("%d ",k&1?l++:r--);
	Fr(i,l,r)printf("%d ",i);
	putchar('\n');
	return 0;
}