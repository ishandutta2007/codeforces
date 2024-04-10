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

char S[128];
int X,Y;
void Move(int x,int y)
{
	X=x,Y=y;
	printf("%d %d\n",x,y);
	fflush(stdout);
	scanf("%s",S);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		Move(1,2);
		if(S[2]=='n')continue;
		Move(1,1);
		while(1)
		{
			if(S[2]=='n')break;
			if(*S=='U'&&Y!=1)Move(X,1);
			else if(*S=='D'||Y==8)
			{
				Move(X+1,Y);
				if(Y!=1)
				{
					if(S[2]=='n')break;
					Move(X,1);
				}
			}
			else Move(X,Y+1);
		}
	}
	return 0;
}