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

char grid[5][120];
int col;
int n;
int i;

int main()
{
//	freopen("a.out","w",stdout);

	scanf("%d",&n);

	if(n==1)
	{
		printf("a\na\nb\nb\n");
		return 0;
	}

	grid[0][0] = 'a';
	grid[1][0]='a';
	grid[2][0]='b'; grid[2][1]='b';
	grid[3][0]='c'; grid[3][1]='c';
	col=2;

	for(i=1;i<n-1;i++)
	{
		if(i%2)
		{
			col=(col+1)%26;
			grid[0][i]='a'+col; grid[0][i+1]='a'+col;
			col=(col+1)%26;
			grid[1][i]='a'+col; grid[1][i+1]='a'+col;
		}
		else
		{
			col=(col+1)%26;
			grid[2][i]='a'+col; grid[2][i+1]='a'+col;
			col=(col+1)%26;
			grid[3][i]='a'+col; grid[3][i+1]='a'+col;
		}
	}

	if(i%2)
	{
		col=(col+1)%26;
		grid[0][i]='a'+col; grid[1][i]='a'+col;
	}
	else
	{
		col=(col+1)%26;
		grid[2][i]='a'+col; grid[3][i]='a'+col;
	}

	grid[0][n]=grid[1][n]=grid[2][n]=grid[3][n]=0;

	for(i=0;i<4;i++)
		printf("%s\n",grid[i]);

	return 0;
}