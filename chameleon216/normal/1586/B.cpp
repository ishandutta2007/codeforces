#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=100100;
int N,M;
char B[MX];

int mian()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		B[b]=1;
	}
	int x=0;
	Fr(i,1,N)if(!B[i]){x=i;break;}
	Fr(y,1,N)if(x!=y)printf("%d %d\n",x,y);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
		memset(B,0,(N+1)*sizeof(char));
	}
}