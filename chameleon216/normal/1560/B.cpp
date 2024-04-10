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

int Query(int x,int y,int z)
{
	if(x<y)swap(x,y);
	int c=x-y,d=c*2;
	if(x>d||z>d)return -1;
	return (z-1+c)%d+1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		printf("%d\n",Query(x,y,z));
	}
	return 0;
}