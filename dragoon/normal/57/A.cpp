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
#define D(x1,yy1,x2,y2) (sqrt( S((x1)-(x2)) + S((yy1)-(y2)) ))
#define EPS 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))
#define in(a,b,c) (a>=b && a<=c)
#define SORT(A) sort(A.begin(),A.end())
#define SZ(X) (int)(X.size())
#define D2(x1,yy1,x2,y2) ( S((x1)-(x2)) + S((yy1)-(y2)) )

typedef pair<int,int> PII;
typedef __int64 LL;

//int dr[]={0,0,1,-1,-1,-1,1,1};
//int dc[]={1,-1,0,0,1,-1,1,-1};

int n,x1,x2,yy1,y2;
int w[10][10];

int DS()
{
	int i,j,k;

	if(x1==0 && x2==0) return ABS(yy1-y2);
	if(x1==n && x2==n) return ABS(yy1-y2);
	if(yy1==0 && y2==0) return ABS(x1-x2);
	if(yy1==n && y2==n) return ABS(x1-x2);

	if( (x1==0 && x2==n) || (x2==0 && x1==n) ) return n+MIN( yy1+y2 , n-yy1+n-y2 );
	if( (yy1==0 && y2==n) || (y2==0 && yy1==n) ) return n+MIN( x1+x2 , n-x1+n-x2 );

	for(i=0;i<=5;i++)
		for(j=0;j<=5;j++)
			w[i][j]=1000000;

	if(x1==0 || yy1==0) w[0][4] = w[4][0] = ABS(0-x1) + ABS(0-yy1);
	if(x2==0 || y2==0) w[0][5] = w[5][0] = ABS(0-x2) + ABS(0-y2);

	if(x1==0 || yy1==n) w[1][4] = w[4][1] = ABS(0-x1) + ABS(n-yy1);
	if(x2==0 || y2==n) w[1][5] = w[5][1] = ABS(0-x2) + ABS(n-y2);

	if(x1==n || yy1==n) w[2][4] = w[4][2] = ABS(n-x1) + ABS(n-yy1);
	if(x2==n || y2==n) w[2][5] = w[5][2] = ABS(n-x2) + ABS(n-y2);

	if(x1==n || yy1==0) w[3][4] = w[4][3] = ABS(n-x1) + ABS(0-yy1);
	if(x2==n || y2==0) w[3][5] = w[5][3] = ABS(n-x2) + ABS(0-y2);

	for(k=0;k<=5;k++)
		for(i=0;i<=5;i++)
			for(j=0;j<=5;j++)
				if( w[i][k] + w[k][j] < w[i][j])
					w[i][j] = w[i][k] + w[k][j];

	return w[4][5];
}

int main()
{
	scanf("%d%d%d%d%d",&n,&x1,&yy1,&x2,&y2);

	printf("%d\n",DS());
	

	return 0;
}