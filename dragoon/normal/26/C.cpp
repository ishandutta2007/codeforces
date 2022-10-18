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
#define ABS(X) ((X) < 0 ? (-(X)) : (X))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;
typedef __int64 LL;

int n,m;
char grid[105][105];
int f[400];

inline void mark(int x,int y)
{
	if(x>=0 && y>=0) f[ grid[x][y] ] = 1;
}

inline int avail()
{
	for(int i='a';;i++)
		if(f[i]==0)
		return  i;
}

int color(int a,int b,int c,int r1,int c1,int r2,int c2)
{
	int i,j,t;

	for(i=r1;i<r2;i+=2)
		for(j=c1;j<c2;j+=2)
		{
			f['a']=f['b']=f['c']=f['d']=f['e']=f['f']=0;
			mark(i-1,j); mark(i,j-1); mark(i+1,j-1); mark(i-1,j+1);

			if(c) 
			{
				t = avail();

				grid[i][j]=grid[i+1][j]=grid[i][j+1]=grid[i+1][j+1]=t; 
				c--;
			}
			else if(b>=2) 
			{
				t = avail();
				grid[i][j]=grid[i+1][j]=t; 
				mark(i,j);
				t=avail();
				grid[i][j+1]=grid[i+1][j+1]=t; 
				b-=2;
			}
			else if(a>=2) 
			{
				t=avail();
				grid[i][j]=grid[i][j+1]=t; 
				mark(i,j);
				t=avail();
				grid[i+1][j]=grid[i+1][j+1]=t; 
				a-=2;
			}
			else
				return 1;
		}

	return 0;
}

void print()
{
	int i;

	for(i=0;i<n;i++) 
	{
		grid[i][m]=0;
		printf("%s\n",grid[i]);
	}
}

int main()
{
	int a,b,c;
	int i;

	scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
	if( (n*m)%2 == 1)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}

	else if(n%2==1)
	{
		if(m/2 > a)
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}

		for(i=0;i<m;i+=2)
			if(i%4==0)
				grid[0][i]=grid[0][i+1]='a';
			else
				grid[0][i]=grid[0][i+1]='b';

		a-=m/2;

		if(color(a,b,c,1,0,n-1,m-1))
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}

	else if(m%2==1)
	{
		if(n/2 > b)
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}

		b-=n/2;

		for(i=0;i<n;i+=2)
			if(i%4==0)
				grid[i][0]=grid[i+1][0]='a';
			else
				grid[i][0]=grid[i+1][0]='b';

		if(color(a,b,c,0,1,n-1,m-1))
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}

	else if(n%2==0 && m%2==0)
	{
		if(color(a,b,c,0,0,n-1,m-1))
		{
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}

	print();

	return 0;
}