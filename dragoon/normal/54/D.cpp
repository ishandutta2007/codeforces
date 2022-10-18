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

int n, k, p;
char name[200], line[200], ans[200];
int f[200];

void failure()
{
	f[0] = -1;
	int i, now = -1;
	for(i=1;i<p;i++)
	{
		while(now!=-1 && name[i]!=name[now+1])
		{
			now = f[now];
		}

		if(name[i]==name[now+1]) f[i] = now+1, now++;
		else f[i] = now = -1;
	}
}

int dp[200][200];

int NEXT(int now, int ch)
{
	if(now==p-1) now = f[now];

	while(now!=-1 && name[now+1]!=ch)
	{
		now = f[now];
	}

	if(now==-1)
	{
		if(name[0]==ch) return 0;
		return -1;
	}

	if(name[now+1]==ch) return now+1;
	return -1;
}

int DFS(int at, int fail)
{
	if(dp[at][fail+1]) return 0;
	dp[at][fail+1] = 1;

	if(at==n) return 1;

	int next;

	if(ans[at]!=0)
	{
		next = NEXT(fail,ans[at]);
		if(next==p-1)
		{
			int z = at-p+1;
			if(line[z]!='1') return 0;
		}

		if( DFS(at+1,next) ) return 1;
		return 0;
	}

	int i;
	for(i='a';i<'a'+k;i++)
	{
		next = NEXT(fail, i);
		if(next==p-1) continue;
		if( DFS(at+1,next) )
		{
			ans[at] = i;
			return 1;
		}
	}

	return 0;
}

int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",name);
	scanf("%s",line);

	int i, flag, j, t;

	for(i=0;i<=n;i++) ans[i] = 0;

	p = strlen(name);
	flag = 1;
	for(i=0;i<n-p+1;i++)
	{
		if(line[i]=='1')
		{
			for(j=i,t=0;j<i+p;j++,t++)
				if(ans[j]==0 || ans[j]==name[t]) ans[j]=name[t];
				else flag = 0;
		}
	}

	if(flag==0) {printf("No solution\n"); return 0;}

	failure();

	if(DFS(0,-1)) printf("%s\n",ans);
	else printf("No solution\n");

	return 0;
}