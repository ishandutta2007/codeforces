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

int n;
int x[100010];
int y[100010];

int check(int a,int b)
{
	int i;
	for(i=a+1;i<b;i++)
	{
		if( x[i-1]*x[i+1] != x[i]*x[i] )
			return 0;
	}

	return 1;
}

int checky(int a,int b)
{
	int i;
	for(i=a+1;i<b;i++)
	{
		if( y[i-1]*y[i+1] != y[i]*y[i] )
			return 0;
	}

	return 1;
}

int check2(int a,int b)
{
	int i, fault=-1;
	for(i=a+1;i<b;i++)
	{
		if(i==fault)
		{
			continue;
		}

		if(i==fault+1)
		{
			if( x[i-2]*x[i+1] != x[i]*x[i] )
			{
				return 0;
			}
			continue;
		}

		if( x[i-1]*x[i+1] != x[i]*x[i] )
		{
			if(i+2<n && x[i-1]*x[i+2] != x[i]*x[i] )
				return 0;

			if(fault!=-1) return 0;
			fault = i+1;
		}
	}

	return 1;
}

int cntzero()
{
	int i,cnt=0;
	for(i=0;i<n;i++)
		if(!x[i])
			cnt++;
	return cnt;
}


int main()
{
	int i;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}

	if(n==2 && x[0]==0 && x[1])
	{
		printf("1\n");
		return 0;
	}

	int cnt=cntzero();
	if(n<3 || cnt==n || (cnt==n-1 && x[0]))
	{
		printf("0\n");
		return 0;
	}

	if(cnt==n-1)
	{
		printf("1\n");
		return 0;
	}

	if(cnt==n-2 && x[0])
	{
		printf("1\n");
		return 0;
	}

	if(cnt==1)
	{
		for(i=0;i<n;i++)
			y[i] = x[i];
		for(i=0;i<n;i++) 
			if(!y[i])
				break;
		for(;i<n-1;i++)
			y[i]=y[i+1];
		if(checky(0,n-2))
		{
			printf("1\n");
			return 0;
		}
	}

	if(cnt)
	{
		printf("2\n");
		return 0;
	}
/*
	if(n>4 && x[0]==1 && x[1]==1 && x[2]==1)
	{
		cnt = 0;
		for(i=0;i<n;i++) if(x[i]!=1) cnt++;
		if(cnt==0) printf("0\n");
		else if(cnt==1) printf("1\n");
		else printf("2\n");
		return 0;
	}
*/
	if(check(0,n-1)) 
	{
		printf("0\n");
		return 0;
	}

	if(check(1,n-1)) 
	{
		printf("1\n");
		return 0;
	}

	int t = x[1];
	x[1] = x[0];
	if(check(1,n-1)) 
	{
		printf("1\n");
		return 0;
	}

	x[1] = t;
	if(check2(0,n-1))
		printf("1\n");
	else
		printf("2\n");

	return 0;
}