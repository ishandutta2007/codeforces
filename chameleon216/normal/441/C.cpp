#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
int N,M,K;

void Next(int& x,int& y)
{
	if(x&1)y==M?++x:++y;
	else y==1?++x:--y;
}



int main()
{
	scanf("%d%d%d",&N,&M,&K);
	int x=1,y=1;
	Fo(i,1,K)
	{
		printf("2 ");
		Fr(i,1,2)printf("%d %d ",x,y),Next(x,y);
		putchar('\n');
	}
	int l=N*M-2*(K-1);
	printf("%d ",l);
	Fr(i,1,l)printf("%d %d ",x,y),Next(x,y);
	putchar('\n');
	return 0;
}