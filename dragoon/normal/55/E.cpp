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

LL x[100005],y[100005];
int cw(int a, int b, int c)
{
	LL d = x[a]*y[b] + x[b]*y[c] + x[c]*y[a] - y[a]*x[b] - y[b]*x[c] - y[c]*x[a];
	if(d<0) return 1;
	return 0;
}

int main()
{
	int i,t,now,p;
	LL n;
	LL ans,cnt;

	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d%I64d",&x[i],&y[i]);
	}

	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d%I64d",&x[n],&y[n]);

		int flag = 0;
		for(i=0;i<n;i++)
			if( !cw(i,(i+1)%n,n) )
				flag = 1;
		if(flag)
		{
			printf("0\n");

			continue;
		}

		now = 0;
		ans = 0;
		for(i=0;i<n;i++)
		{
			p = (now+1)%n;
			while( cw(i,p,n) )
			{
				now = p;
				p = (now+1)%n;
			}

			cnt = now - i - 1;
			if(cnt<0) cnt+=n;

			ans += (cnt*(cnt+1))/2;
		}

		ans = -ans;
		ans += (n*(n-1)*(n-2))/6;

		printf("%I64d\n",ans);
	}

	return 0;
}