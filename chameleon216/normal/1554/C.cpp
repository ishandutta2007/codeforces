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
		int x,y,z=0;
		scanf("%d%d",&x,&y),++y;
		Fl(i,30,0)
		{
			if(!(x>>i&1)&&(y>>i&1))z|=1<<i;
			if((x>>i&1)&&!(y>>i&1))break;
		}
		printf("%d\n",z);
	}
	return 0;
}