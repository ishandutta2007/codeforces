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
	int t,n;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&n);
		int a,b;
		scanf("%d",&b);
		Fr(i,2,n)scanf("%d",&a),b&=a;
		printf("%d\n",b);
	}
	return 0;
}