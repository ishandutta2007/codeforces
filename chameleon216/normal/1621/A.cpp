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


void Solve(int n,int k)
{
	if((n+1)/2<k){puts("-1");return;}
	Fr(i,1,n)
	{
		Fr(j,1,n)
			if(i==j&&(i&1)==1&&k)--k,putchar('R');
			else putchar('.');
		putchar('\n');
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		Solve(n,k);
	}
	return 0;
}