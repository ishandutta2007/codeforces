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
		int l,r,sum=0;
		scanf("%d%d",&l,&r);
		while(r)sum+=r-l,r/=10,l/=10;
		printf("%d\n",sum);
	}
	return 0;
}