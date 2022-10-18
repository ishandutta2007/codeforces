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

int main()
{
	vector< PII > V;
	int T, i, j;
	char grid[55][55];

	scanf("%d", &T);
	while(T--)
	{
		for(i = 0; i < 8; i++) scanf("%s", grid[i]);
		V.clear();
		FORN(i, 8) FORN(j, 8) if(grid[i][j] == 'K')
			V.push_back( PII(i, j) );

		if( (V[0].first % 2) == (V[1].first % 2) && (V[0].second % 2) == (V[1].second % 2) && (V[0].first + V[0].second)%4 == (V[1].first + V[1].second)%4)
		{
			int z = ABS(V[0].first - V[1].first);
			if(z % 4 ) {printf("NO\n"); continue;}
			z = ABS(V[0].second - V[1].second);
			if(z % 4 ) {printf("NO\n"); continue;}

			printf("YES\n");
			continue;
		}
		
		printf("NO\n");
	}

	return 0;
}