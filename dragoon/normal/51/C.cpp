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

int dr[]={0,0,1,-1,-1,-1,1,1};
int dc[]={1,-1,0,0,1,-1,1,-1};

int x[200010];
int n;

int check(int d)
{
	int i, j, cnt=0;
	for(i=0;i<n;)
	{
		for(j=i;j<n;j++)
			if(x[j]-x[i] > d )
				break;

		i = j;

		cnt++;

		if(cnt==4) return 0;
	}

	return 1;
}

void Print(int d)
{
	int i, j, cnt=0;
	double last;

	for(i=0;i<n;)
	{
		for(j=i;j<n;j++)
			if(x[j]-x[i] > d )
				break;

		if(cnt) printf(" ");
		printf("%.6lf",(x[j-1]+x[i])/2.+1e-7);

		i = j;

		cnt++;
	}

	if(cnt!=3)
	{
		while(cnt!=3)
		{
			cnt++;
			printf(" ");
			printf("%.6lf",x[0]*1.);
		}
	}
	printf("\n");
}

int main()
{
	int i;
	int lo, hi, mid;
	double ans;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}

	sort(x,x+n);

	lo = 0;
	hi = 2*x[n-1];
	while( hi-lo > 0 )
	{
		mid = (hi + lo)/2;

		if(check(mid)) 
			hi = mid;
		else 
			lo = mid+1;
	}

	printf("%.6lf\n",lo/2.+1e-8);
	Print(lo);

	return 0;
}