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
	int t,n,s;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%d",&n,&s);
		int k=n/2+1;
		printf("%d\n",s/k);
	}
	return 0;
}