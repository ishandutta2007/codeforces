#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define S(X) ((X)*(X))
#define ABS(X) ((X)>0?(X):(-(X)))

typedef pair<int,int> PII;
typedef __int64 LL;

LL k[5],t[5],f[5][100005];
LL ans,x;
int n,i,j;

int main()
{
	scanf("%I64d%I64d%I64d",&k[1],&k[2],&k[3]);
	
	scanf("%I64d%I64d%I64d",&t[1],&t[2],&t[3]);

	scanf("%d",&n);

	for(i=1;i<=3;i++)
		k[i] = MIN(k[i], n);

	for(i=0;i<n;i++) scanf("%I64d",&f[0][i]);

	for(i=1;i<=3;i++)
	{
		queue<LL> Q;
		for(j=0;j<k[i];j++)
			Q.push(0);

		for(j=0;j<n;j++)
		{
			x = Q.front();
			f[i][j] = MAX(x, f[i-1][j]) + t[i];
			Q.pop();
			Q.push( f[i][j] );
		}
	}

	ans = -1;
	for(i=0;i<n;i++)
		if(ans==-1 || ans < f[3][i] - f[0][i])
			ans = f[3][i] - f[0][i];

	printf("%I64d\n",ans);




	return 0;
}