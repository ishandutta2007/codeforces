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

pair<ld, ld> calc(int n) {
	long double lo = 0, hi = 1000;
	for (int i = 1; i <= 1000; i++) {
		ld m = (lo + hi) / 2.;
		ld g = m * m;
		if (g < S(n) - 4 * n) {
			lo = m;
		}
		else {
			hi = m;
		}
	}
	long double d = lo;
	long double x = (n + d) / 2.;
	long double y = (n - d) / 2.;
	return { x, y };
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif

	/*for (int i = 2; i <= 1000; i++) {
		auto p = calc(i);
		bool c1 = (p.first >= 0 && p.second >= 0);
		bool c2 = (p.first + p.second - p.first * p.second <= 1e-6);
		bool c3 = ((p.first + p.second - i) <= 1e-6);
		if (!c1 || !c2 || !c3) printf("%Lf %Lf %d\n", p.first, p.second, i);
		
	}*/
	int T;
	scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		if (n == 1 || n == 2 || n == 3) {
			printf("N\n");
			continue;
		}
		auto p = calc(n);
		printf("Y %.16Lf %.16Lf\n", p.first, p.second);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}