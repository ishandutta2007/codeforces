//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

LL x1, yy1, x2, y2;
LL a, b, c;

vector<PDD> calc(LL x, LL y) {
	vector<PDD> V;
	if (b) {
		double yy = (-c - a * x) / (1. * b);
		V.push_back({ x, yy });
	}
	if (a) {
		double xx = (-c - b * y) / (1. * a);
		V.push_back({ xx, y });
	}
	return V;
}
void solve() {
	scanf("%lld %lld %lld", &a, &b, &c);
	scanf("%lld %lld %lld %lld", &x1, &yy1, &x2, &y2);
	double ans = ABS(x1 - x2) + ABS(yy1 - y2);
	vector<PDD> V1, V2;
	V1 = calc(x1, yy1);
	V2 = calc(x2, y2);
	for (auto& p1 : V1) {
		for (auto& p2 : V2) {
			double now = sqrt(S(p1.first - p2.first) + S(p1.second - p2.second));
			now += ABS(x1 - p1.first) + ABS(yy1 - p1.second);
			now += ABS(x2 - p2.first) + ABS(y2 - p2.second);
			ans = MIN(ans, now);
		}
	}
	printf("%.12lf\n", ans);
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	solve();


	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}