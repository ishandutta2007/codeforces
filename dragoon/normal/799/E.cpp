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

int n, m, k;
int valid[200005];
VP V[4], Z;
vector<LL> cumsum[4];
int cost[200005];

int cnts[4 * 200005];
LL costs[4 * 200005];

void build(int at, int l, int r) {
	if (l == r) {
		cnts[at] = 0;
		costs[at] = 0;
		return;
	}
	int m = (l + r) / 2;
	build(at * 2, l, m);
	build(at * 2 + 1, m + 1, r);
	costs[at] = cnts[at] = 0;
}

void insert(int at, int l, int r, PII& p) {
	if (l == r) {
		cnts[at] = 1;
		costs[at] = Z[l].first;
		return;
	}
	int m = (l + r) / 2;
	if (p <= Z[m]) insert(at * 2, l, m, p);
	else insert(at * 2 + 1, m + 1, r, p);
	cnts[at] = cnts[at * 2] + cnts[at * 2 + 1];
	costs[at] = costs[at * 2] + costs[at * 2 + 1];
}

LL query(int at, int l, int r, int c) {
	if (c == 0) return 0;
	if (l == r) {
		return costs[at];
	}
	if (c == cnts[at]) return costs[at];

	int m = (l + r) / 2;
	if (c <= cnts[at * 2]) {
		return query(at * 2, l, m, c);
	}
	else {
		return query(at * 2, l, m, cnts[at * 2]) + query(at * 2 + 1, m + 1, r, c - cnts[at * 2]);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
//		cost[i] = 10;
	}
	for (int i = 0; i < 2; i++) {
		int p;
		scanf("%d", &p);
		while (p--) {
			int a;
			scanf("%d", &a);
			valid[a] |= (1 << i);
		}
	}

	for (int i = 1; i <= n; i++) {
		V[valid[i]].push_back(PII(cost[i], i));
		Z.push_back(PII(cost[i], i));
	}
	sort(ALL(Z));
	build(1, 0, SZ(Z) - 1);
	for (PII& p : V[0]) insert(1, 0, SZ(Z) - 1, p);
	for (int i = 1; i <= 3; i++) sort(ALL(V[i]));
	for (int i = 1; i <= 2; i++) {
		LL now = 0;
		for (int j = 0; j < SZ(V[i]); j++) {
			now += V[i][j].first;
			cumsum[i].push_back(now);

			if (j >= k) {
				insert(1, 0, SZ(Z) - 1, V[i][j]);
			}
		}
	}

	LL ans = 1000000000000000000LL;
	int last = n;
	LL run = 0;
	for (int i = 0; i <= m; i++) {
		if (V[3].size() < i) break;
		if (i) run += V[3][i - 1].first;
		int need = MAX(k - i, 0);
		if (SZ(V[1]) < need || SZ(V[2]) < need) continue;
		int has = i + 2 * need;
		int more_need = m - has;
		if (more_need < 0) continue;
		while (last >= need) {
			if (V[1].size() > last) {
				insert(1, 0, SZ(Z) - 1, V[1][last]);
			}
			if (V[2].size() > last) {
				insert(1, 0, SZ(Z) - 1, V[2][last]);
			}
			last--;
		}
		if (cnts[1] < more_need) continue;
		LL total = 0;
		total = run;
		if (need >= 1) total += cumsum[1][need - 1] + cumsum[2][need - 1];
		total += query(1, 0, SZ(Z) - 1, more_need);
		ans = MIN(ans, total);
	}
	if (ans == 1000000000000000000LL)ans = -1;
	printf("%lld\n", ans);

	return 0;
}