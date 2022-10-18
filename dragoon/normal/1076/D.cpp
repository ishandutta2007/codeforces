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

int n, m, k;
struct Edge {
	int u, v; LL d;
	int id;
	void scan(int _id) {
		id = _id;
		scanf("%d %d %lld", &u, &v, &d);
	}
};
Edge e[300005];
VI V[300005];
int pre[300005];
LL cost[300005];
int done[300005];
int mark[300005];
int vis[300005];
VI ans;

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	double start_time = clock();
#endif
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		e[i].scan(i);
		V[e[i].u].push_back(i);
		V[e[i].v].push_back(i);
	}

	for (int i = 1; i <= n; i++) cost[i] = 1000000000000000000LL;
	cost[1] = 0;
	priority_queue<pair<LL, int>> Q;
	Q.push({ -cost[1], 1 });
	while (!Q.empty()) {
		auto u = Q.top();
		Q.pop();
		if (done[u.second]) continue;
		done[u.second] = 1;

		for (int iv : V[u.second]) {
			auto& v = e[iv];
			int other = u.second ^ v.u ^ v.v;
			if (cost[other] > cost[u.second] + v.d) {
				cost[other] = cost[u.second] + v.d;
				pre[other] = iv;
				Q.push({ -cost[other], other });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (pre[i]) {
			mark[pre[i]] = 1;
		}
	}

	queue<int> QQ;
	QQ.push(1);
	vis[1] = 1;
	while (!QQ.empty()) {
		int u = QQ.front();
		QQ.pop();
		for (int iv : V[u]) {
			if (mark[iv] == 0) continue;
			auto& v = e[iv];
			int other = u ^ v.u ^ v.v;
			if (vis[other]) continue;
			QQ.push(other);
			vis[other] = 1;
			ans.push_back(iv);
		}
	}

	int x = MIN(SZ(ans), k);
	printf("%d\n", x);
	for (int i = 0; i < x; i++) {
		printf("%d ", ans[i]);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}