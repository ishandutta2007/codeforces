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
typedef __int64 LL;

int point[2003][2003];
LL dia1[5003], dia2[5003];

int main()
{
	int n, i, j;
	LL sameMax, diffMax;

	scanf("%d", &n);
	FORN(i, n) FORN(j, n)
	{
		scanf("%d", &point[i][j]);
		dia1[i + j] += point[i][j];
		dia2[i - j + 2000] += point[i][j];
	}

	sameMax = -1;
	PII same;
	FORN(i, n) FORN(j, n)
	{
		if(i % 2 != j % 2) continue;
		LL score = dia1[i + j] + dia2[i - j + 2000] - point[i][j];
		if(score > sameMax)
		{
			sameMax = score;
			same = PII(i, j);
		}
	}

	diffMax = -1;
	PII diff;
	FORN(i, n) FORN(j, n)
	{
		if(i % 2 == j % 2) continue;
		LL score = dia1[i + j] + dia2[i - j + 2000]- point[i][j];
		if(score > diffMax)
		{
			diffMax = score;
			diff = PII(i, j);
		}
	}

	printf("%I64d\n", sameMax + diffMax);
	printf("%d %d %d %d\n", same.first + 1, same.second + 1, diff.first + 1, diff.second + 1);

	return 0;
}