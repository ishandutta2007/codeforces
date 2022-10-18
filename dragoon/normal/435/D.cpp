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

int row[405][405], col[405][405], dplus[405][405], dminus[405][405];
char S[405][405];
int R, C;

int OUT(int r, int c)
{
	return !(r >= 0 && r < R && c >= 0 && c < C);
}

int OkayRow(int r, int c, int s)
{
	assert(!OUT(r, c + s));
	int sum = row[r][c + s];
	if(c) sum -= row[r][c - 1];
	return (sum == 0);
}

int OkayCol(int r, int c, int s)
{
	int sum = col[r][c];
	if(r - s >= 1) sum -= col[r - s - 1][c];
	return (sum == 0);
}

int OkayPlus(int r, int c, int s)
{
	assert(!OUT(r, c - s));
	int sum = dplus[r][c - s];
	if(r - s >= 1 && c + 1 < C) sum -= dplus[r - s - 1][c + 1];
	return (sum == 0);
}

int OkayMinus(int r, int c, int s)
{
	assert(!OUT(r, c + s));
	int sum = dminus[r][c + s];
	if(r - s >= 1 && c >= 1) sum -= dminus[r - s - 1][c - 1];
	return (sum == 0);
}

int main()
{
	int i, j, sz, h;

	scanf("%d %d", &R, &C);
	for(i = 0; i < R; i++)
	{
		scanf("%s", S[i]);
	}

	for(i = 0; i < R; i++)
		for(j = 0; j < C; j++)
		{
			if(S[i][j] == '0') h = 0; else h = 1;
			row[i][j] = h + (j ? row[i][j - 1] : 0);
			col[i][j] = h + (i ? col[i - 1][j] : 0);
			dplus[i][j] = h + ((i >= 1 && j + 1 < C) ? dplus[i - 1][j + 1] : 0);
			dminus[i][j] = h + ((i && j) ? dminus[i - 1][j - 1] : 0);
		}

	int ans = 0;
	int done, f1, f2, f3, f4;
	for(i = 0; i < R; i++)
		for(j = 0; j < C; j++)
		{
			f1 = f2 = f3 = f4 = 1;
			done = 0;
			for(sz = 1; done != 4; sz++)
			{
				if(f1)
				{
					if(OUT(i - sz, j + sz)) f1 = 0, done++;
					else if(OkayRow(i, j, sz) && OkayCol(i, j, sz) && OkayMinus(i, j, sz)) ans++;
				}

				if(f2)
				{
					if(OUT(i - sz, j - sz)) f2 = 0, done++;
					else if(OkayRow(i, j - sz, sz) && OkayCol(i, j, sz) && OkayPlus(i, j, sz)) ans++;
				}

				if(f3)
				{
					if(OUT(i + sz, j - sz)) f3 = 0, done++;
					else if(OkayRow(i, j - sz, sz) && OkayCol(i + sz, j, sz) && OkayMinus(i + sz, j - sz, sz)) ans++;
				}

				if(f4)
				{
					if(OUT(i + sz, j + sz)) f4 = 0, done++;
					else if(OkayRow(i, j, sz) && OkayCol(i + sz, j, sz) && OkayPlus(i + sz, j + sz, sz)) ans++;
				}
			}
		}

	for(i = 0; i < R; i++)
		for(j = 0; j < C; j++)
		{
			if(i == 2 && j == 2)
				i = j;
			f1 = f2 = f3 = f4 = 1;
			done = 0;
			for(sz = 1; done != 4; sz++)
			{
				if(f1)
				{
					if(OUT(i - sz, j - sz) || OUT(i - sz, j + sz)) f1 = 0, done++;
					else if(OkayRow(i - sz, j - sz, 2 * sz - 1) && OkayPlus(i, j + sz, sz) && OkayMinus(i, j - sz, sz)) ans++;
				}

				if(f2)
				{
					if(OUT(i - sz, j - sz) || OUT(i + sz, j - sz)) f2 = 0, done++;
					else if(OkayCol(i + sz, j - sz, 2 * sz - 1) && OkayPlus(i + sz, j, sz) && OkayMinus(i, j - sz, sz)) ans++;
				}

				if(f3)
				{
					if(OUT(i + sz, j - sz) || OUT(i + sz, j + sz)) f3 = 0, done++;
					else if(OkayRow(i + sz, j - sz, 2 * sz - 1) && OkayPlus(i + sz, j, sz) && OkayMinus(i + sz, j, sz)) ans++;
				}

				if(f4)
				{
					if(OUT(i + sz, j + sz) || OUT(i - sz, j + sz)) f4 = 0, done++;
					else if(OkayCol(i + sz, j + sz, 2 * sz - 1) && OkayPlus(i, j + sz, sz) && OkayMinus(i + sz, j, sz)) ans++;
				}
			}
		}

	printf("%d\n", ans);

	return 0;
}