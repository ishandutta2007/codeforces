#include <cstdio>
#include <iostream>	
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define LL long long 
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 gtmshb
#define x1 gtmjtjl
#define y0 gtmsub
#define y1 gtmsf
const long long base=288230376151711744LL;
int n,k;
int main()
{	
	scanf("%d%d",&n,&k);
	n=k+1;
	int minx=2147483647,cnt=0;
	for(int i=1;i<=k+1;i++)
	{
		putchar('?');
		for(int j=1;j<=k+1;j++)
			if (i!=j)printf(" %d",j);
		puts("");
		fflush(stdout);
		int pos,x;
		scanf("%d%d",&pos,&x);
		if (x==minx)cnt++;
		else if (x<minx){ minx=x; cnt=1; }
	}
	printf("! %d\n",k+1-cnt);
	fflush(stdout);
	return 0;
}