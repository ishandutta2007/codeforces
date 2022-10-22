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

int N;
char C,S[300100];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d %c%s",&N,&C,S+1);
		int b=1;
		Fr(i,1,N)if(S[i]!=C){b=0;break;}
		if(b){printf("0\n");continue;}
		b=1;
		Fr(i,N/2+1,N)if(S[i]==C)
			{printf("1\n%d\n",i),b=0;break;}
		if(b)printf("2\n%d %d\n",N-1,N);
	}
	return 0;
}