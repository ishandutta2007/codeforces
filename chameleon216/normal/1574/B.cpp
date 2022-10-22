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
		int a[3],m;
		Fo(i,0,3)scanf("%d",&a[i]);
		scanf("%d",&m);
		sort(a,a+3);
		int x=a[0]+a[1]+a[2]-3;
		int y=a[2]-a[0]-a[1]-1;
		printf(y<=m&&m<=x?"YES\n":"NO\n");
	}
	return 0;
}