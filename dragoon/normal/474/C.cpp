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

typedef pair<double, double> PDD;
typedef vector<int> VI;
//typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;
typedef pair<LL, LL> PII;

void input(PII &A, PII &B)
{
	scanf("%I64d %I64d %I64d %I64d", &A.first, &A.second, &B.first, &B.second);
}

PII rotate(PII point, PII base, int n)
{
	if(n == 0) return point;
	if(n == 2) return PII(2 * base.first - point.first, 2 * base.second - point.second);
	if(n == 1) return PII(base.first - (point.second - base.second), base.second + (point.first - base.first));
	if(n == 3) return PII(base.first + (point.second - base.second), base.second - (point.first - base.first));
}

LL dist(PII A, PII B)
{
	return S(A.first - B.first) + S(A.second - B.second);
}

int okay(PII A, PII B, PII C, PII D)
{
	if(A.first == B.first && A.second == B.second) return 0;
	vector<LL> V;
	V.push_back(dist(A,B));
	V.push_back(dist(B,C));
	V.push_back(dist(C,D));
	V.push_back(dist(D,A));
	V.push_back(dist(A,C));
	V.push_back(dist(D,B));
	sort(ALL(V));
	if(V[0] == 0) return 0;
	if(V[0] != V[1]) return 0;
	if(V[0] != V[2]) return 0;
	if(V[0] != V[3]) return 0;
	if(V[4] != V[5]) return 0;
	if(V[0] + V[1] != V[4]) return 0;
	return 1;


}

int main()
{
	PII point[5], base[5], p[5];

	int n, i, j, k, l;
	scanf("%d", &n);
	while(n--)
	{
		FORN(i, 4)
		{
			input(point[i], base[i]);
		}

		int ans = -1;
		FORN(i, 4) FORN(j, 4) FORN(k, 4) FORN(l, 4)
		{
			p[0] = rotate(point[0], base[0], i);
			p[1] = rotate(point[1], base[1], j);
			p[2] = rotate(point[2], base[2], k);
			p[3] = rotate(point[3], base[3], l);
			if(okay(p[0],p[1], p[2], p[3]))
			{
				if(ans == -1 || ans > i + j + k + l)
					ans = i + j + k + l;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}