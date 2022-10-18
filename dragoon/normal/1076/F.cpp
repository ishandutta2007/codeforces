#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
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
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int128 LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

typedef long double ld;

int n, k;
int x[300005], y[300005];

int choose(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return MIN(a, b);
}

PII calc(int mn, LL x, LL y) {
	int rem = k - mn;

	int first = -1, second = -1;
	if (x == y) {
		first = 1;
		if (rem > 0) second = 1;
		else if (rem == 0 && k > 1 && y > 1) second = 1;
		return { first, second };
	}
	
	if (y > x) {
		if (k*x >= y) first = 1;
		second = 1 + MAX(y - 1 - k * x, 0);
		if (second > k) second = -1;
		return { first, second };
	}

	if (x > y) {
		if (rem + (y - 1)*k < x) second = -1;
		else second = 1;
		first = MAX(1, x - (rem + k * (y - 1)));
		if (first > k) first = -1;
		return { first, second };
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &y[i]);
	int ax = 0, ay = 0;
	for (int i = 1; i <= n; i++) {
		PII p = { -1, -1 }, q = { -1, -1 };
		if (ax != -1) p = calc(ax, x[i], y[i]);
		if (ay != -1) q = calc(ay, y[i], x[i]);
		swap(q.first, q.second);
		ax = choose(q.first, p.first);
		ay = choose(q.second, p.second);
		if (ax == -1 && ay == -1) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}