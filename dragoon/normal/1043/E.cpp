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
//#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

int sx[300005], sy[300005];
int n, m;
LL ans[300005];

struct Point {
	int x, y, id;
};

bool operator<(Point A, Point B) {
	return A.x - A.y < B.x - B.y;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &sx[i], &sy[i]);
	}

	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		int now = MIN(sx[u] + sy[v],
			          sx[v] + sy[u]);
		ans[u] -= now;
		ans[v] -= now;
	}

	vector<Point> V;
	for (int i = 1; i <= n; i++) {
		V.push_back({ sx[i], sy[i], i });
	}

	sort(ALL(V));
	LL sumx = 0;
	for (LL i = 0; i < n; i++) {
		LL now = V[i].y * i + sumx;
		ans[V[i].id] += now;
		sumx += V[i].x;
	}
	LL sumy = 0;
	for (LL i = n - 1; i >= 0; i--) {
		LL now = V[i].x * (n - 1 - i) + sumy;
		ans[V[i].id] += now;
		sumy += V[i].y;
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld ", ans[i]);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}