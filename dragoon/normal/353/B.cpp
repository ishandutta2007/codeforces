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
#define IN(A, B, C)  (B) <= (A) && (A) <= (C)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

int n, a[1000], i, j, sz1, sz2	;
VI V[1000];
VI One, Two, Multi;

int ans[1000];
set<int> S[3];

int main()
{
	scanf("%d", &n);
	n *= 2;

	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		V[a[i]].push_back(i);
	}

	for(i = 10; i <= 99; i++)
	{
		if(SZ(V[i]) == 0) continue;
		else if(SZ(V[i]) == 1)
		{
			One.push_back(V[i][0]);
		}
		else
		{
			for(j = 0; j < SZ(V[i]); j++)
			{
				if(j <= 1) Two.push_back(V[i][j]);
				else Multi.push_back(V[i][j]);
			}
		}
	}

	sz1 = sz2 = 0;
	for(i = 0; i < SZ(One); i++)
	{
		if(i & 1)
		{
			S[1].insert( a[One[i]] );
			sz1++;
			ans[One[i]] = 1;
		}
		else
		{
			S[2].insert( a[One[i]] );
			sz2++;
			ans[One[i]] = 2;
		}
	}

	for(i = 0; i < SZ(Two); i+=2)
	{
		S[1].insert( a[Two[i]] );
		sz1++;
		ans[Two[i]] = 1;

		S[2].insert( a[Two[i+1]] );
		sz2++;
		ans[Two[i+1]] = 2;
	}

	for(i = 0; i < SZ(Multi); i++)
	{
		if(sz1 < n/2)
		{
			S[1].insert( a[Multi[i]] );
			sz1++;
			ans[Multi[i]] = 1;
		}
		else
		{
			S[2].insert( a[Multi[i]] );
			sz2++;
			ans[Multi[i]] = 2;
		}
	}

	printf("%d\n", S[1].size() * S[2].size());
	FORN(i, n)
	{
		printf( i ? " %d" : "%d", ans[i]);
	}
	printf("\n");

	return 0;
}