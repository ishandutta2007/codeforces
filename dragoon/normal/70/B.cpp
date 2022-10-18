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

char line[20005];

int main()
{
	int n,len,here,cnt,i,last;

	scanf("%d",&n);
	gets(line);
	gets(line);
	len = strlen(line);

	here = 0;
	cnt = 0;
	while(here<len)
	{
		last = -1;
		for(i=here;i<len && i<here+n;i++)
		{
			if(line[i]=='.' || line[i]=='?' || line[i]=='!')
				last = i;
		}

		if(last==-1) {printf("Impossible\n"); return 0;}
		cnt++;
		here = last+2;
	}

	printf("%d\n",cnt);

	return 0;
}