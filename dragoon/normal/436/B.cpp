#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
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

int ans[2005];
int L[4005][4005];
int R[4005][4005];
char field[2005][2005];

int main()
{
	int n, m, k;
	int i, j;

	scanf("%d %d %d", &n, &m, &k);
	FORN(i, n) scanf("%s", field[i]);
	FORN(i, n) FORN(j, m)
	{
		if(field[i][j] == 'U')
		{
			if(i % 2 == 0) ans[j]++;
		}

		if(field[i][j] == 'U' || field[i][j] == 'D')
			field[i][j] = '.';

		if(field[i][j] == 'R')
		{
			R[i][-j + m]++;
		}
		else if(field[i][j] == 'L')
		{
			L[i][j - (m - 1) + m]++;
		}
	}
	
	FORN(j, m)
	{
		FORN(i, n)
		{
			if(i - j + m >= 0) 
				ans[j] += R[i][i - j + m]; // t + j = i
			if(i - m + 1 + j + m >= 0) 
				ans[j] += L[i][i - m + 1 + j + m]; // t + m - 1 - j = i
		}
	}

	FORN(j, m)
	{
		if(j) printf(" ");
		printf("%d", ans[j]);
	}
	printf("\n");
	return 0;
}