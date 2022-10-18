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

int vis[1002][1002];
int flag;
int d[1002];

int main()
{
	int now, flag, m,n,i;

	scanf("%d",&n);
	if(n==1)
	{
		printf("YES\n");
		return 0;
	}

	vis[0][0]=1;
	d[0]=1;
	now = m= 0;
	while(1)
	{
		now=(now+m+1)%n;
		m=(m+1)%(n-1);
		if(vis[now][m]) break;
		vis[now][m]=1;
		d[now]=1;
	}

	flag = 1;
	for(i=0;i<n;i++)
		if(d[i]==0)
			flag = 0;
	if(flag) printf("YES\n"); else printf("NO\n");

	return 0;
}