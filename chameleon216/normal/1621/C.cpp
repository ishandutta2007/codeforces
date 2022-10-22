#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;

const int MX=100100;
int N,P[MX];

int Query(int i)
{
	printf("? %d\n",i);
	fflush(stdout);
	int p;
	scanf("%d",&p);
	return p;
}

void Print()
{
	printf("! ");
	Fr(i,1,N)
	{
		printf("%d ",P[i]);
	}
	putchar('\n');
	fflush(stdout);
}

void Work()
{
	scanf("%d",&N);
	Fr(i,1,N)if(!P[i])
	{
		int x=Query(i);
		while(!P[x])
		{
			int y=Query(i);
			P[x]=y;
			x=y;
		}
	}
	Print();
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		Work();
		Fr(i,1,N)P[i]=0;
	}
	return 0;
}