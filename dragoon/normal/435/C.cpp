#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
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
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

char ans[2020][2020];
int a[1020];

int main()
{
	int n, i, j;
	int row, col;
	int maxrow, minrow;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for(i = 0; i < 2010; i++)
		for(j = 0; j < 2010; j++)
			ans[i][j] = ' ';

	row = 1005;
	col = 0;
	minrow = 2010, maxrow = 0;
	for(i = 0; i < n; i++)
	{
		if(i % 2)
		{
			row++;
			for(j = 0; j < a[i]; j++)
			{
				ans[row][col] = '\\';
				minrow = MIN(row, minrow);
				maxrow = MAX(row, maxrow);
				row++;
				col++;
			}
		}
		else
		{
			if(i) row--;
			for(j = 0; j < a[i]; j++)
			{
				ans[row][col] = '/';
				minrow = MIN(row, minrow);
				maxrow = MAX(row, maxrow);
				row--;
				col++;
			}
		}
	}

	for(i = minrow; i <= maxrow; i++)
	{
		ans[i][col] = 0;
		printf("%s\n", ans[i]);
	}

	return 0;
}