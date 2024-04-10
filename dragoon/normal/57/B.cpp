#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<math.h>
#include<stack>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X)>0?(X):(-(X)))
#define S(X) ((X)*(X))
#define D(x1,y1,x2,y2) (sqrt( S((x1)-(x2)) + S((y1)-(y2)) ))
#define EPS 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))
#define in(a,b,c) (a>=b && a<=c)
#define SORT(A) sort(A.begin(),A.end())
#define SZ(X) (int)(X.size())
#define D2(x1,y1,x2,y2) ( S((x1)-(x2)) + S((y1)-(y2)) )

typedef pair<int,int> PII;
typedef __int64 LL;

//int dr[]={0,0,1,-1,-1,-1,1,1};
//int dc[]={1,-1,0,0,1,-1,1,-1};

LL ans;
int n,m,k;
LL x;
int a[100002],b[100002],c[100002];

int main()
{
	int i,j;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}

	ans = 0;
	for(i=0;i<k;i++)
	{
		scanf("%I64d",&x);

		for(j=0;j<m;j++)
		{
			if(a[j]<=x && x<=b[j]) ; else continue;

			ans += (x-a[j]) + c[j];
		}


	}

	printf("%I64d\n",ans);

	return 0;
}