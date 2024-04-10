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
typedef long long int LL;
//typedef __int64 LL;
typedef pair<LL, LL> PLL;

pair<LL, LL> p[100005];

LL dist(int i, int j) {
	return S(p[i].first - p[j].first) + S(p[i].second - p[j].second);
}

LL area(int i, int j, int k) {
	LL d = p[i].first * p[j].second - p[i].second*p[j].first
		+ p[j].first * p[k].second - p[j].second*p[k].first
		+ p[k].first * p[i].second - p[k].second*p[i].first;
	return ABS(d);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%I64d %I64d", &p[i].first, &p[i].second);
	}

	int j = 1;
	for (int i = 2; i < n; i++) {
		if (dist(0, j) > dist(0, i)) {
			j = i;
		}
	}

	int k = -1;
	for (int i = 1; i < n; i++) {
		if (i == j) continue;
		LL newA = area(0, j, i);
		if (newA == 0) continue;
		if (k == -1) {
			k = i; continue;
		}
		LL prev = area(0, j, k);
		if (newA < prev) {
			k = i;
		}
	}
	printf("%d %d %d\n", 0 + 1, j + 1, k + 1);
	return 0;
}