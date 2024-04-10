#pragma warning(disable:4786)
#include<stdio.h>
#include<queue>
#include<stack>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<map>
#include<set>
#include<math.h>
#include<sstream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define S(X) ((X)*(X))
#define ABS(X) ((X)>0?(X):(-(X)))

typedef __int64 LL;


int main()
{
	LL ans = 0, sx = 0, sy = 0;
	LL x,y;
	int n,i;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		ans += n*x*x + n*y*y;
		sx += x;
		sy += y;
	}

	ans -= sx*sx + sy*sy;

	printf("%I64d\n",ans);

	return 0;
}