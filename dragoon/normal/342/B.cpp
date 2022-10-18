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

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;

#define IN(A, B, C) assert( B <= A && A <= C)

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

int main()
{
	int n, m, s, f, now, i, t, l, r;

	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &f);

	if(s < f)
	{
		now = 0;
		for(i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &t, &l, &r);
			for( now = now + 1; now < t; now++)
			{
				if(s == f) return 0;
				s++;
				printf("R");
			}

			if( (l <= s && s <= r) || (l <= s + 1 && s + 1 <= r) )
			{
				if(s == f) return 0;
				printf("X");
				continue;
			}

			if(s == f) return 0;
			s++;
			printf("R");
		}

		for(; ; now++)
		{
			if(s == f) return 0;
			s++;
			printf("R");
		}
	}
	else
	{
		now = 0;
		for(i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &t, &l, &r);
			for( now = now + 1; now < t; now++)
			{
				if(s == f) return 0;
				s--;
				printf("L");
			}

			if( (l <= s && s <= r) || (l <= s - 1 && s - 1 <= r) )
			{
				if(s == f) return 0;
				printf("X");
				continue;
			}

			if(s == f) return 0;
			s--;
			printf("L");
		}

		for(; ; now++)
		{
			if(s == f) return 0;
			s--;
			printf("L");
		}
	}

	return 0;
}