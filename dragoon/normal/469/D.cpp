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
#include<unordered_map>
#include<unordered_set>
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
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;
typedef long double ld;

/*
// Number of variables = n.
// Number of vertices = 2 * n.
// Use: (0, 1), (2, 3) format.
// 0 as !x, 1 as x.
init();  // not needed if you don't rerun
ForceRelation(0, 3); // if !var1 -> var3
TwoSat();
*/
// set 2 * number of vertices.
#define MAXN 200005

// Just clean these for init.
vector<int> V[MAXN], VT[MAXN];

void init() {
	for (int i = 0; i < MAXN; i++) {
		V[i].clear();
		VT[i].clear();
	}
}

bool used[MAXN];
vector<int> order, component[MAXN];
int mark[MAXN];
int assignment[MAXN];

void dfs1(int v) {
	used[v] = true;
	for (int i = 0; i < V[v].size(); ++i) {
		if (!used[V[v][i]]) {
			dfs1(V[v][i]);
		}
	}
	order.push_back(v);
}

void dfs2(int v, VI& component) {
	used[v] = true;
	component.push_back(v);
	for (int i = 0; i < VT[v].size(); ++i) {
		if (!used[VT[v][i]]) {
			dfs2(VT[v][i], component);
		}
	}
}

// Returns 0 if not solvable. Otherwise returns 1.
// Assignment is recorded in assign.
int TwoSat(int n)
{
	n *= 2;

	order.clear();
	for (int i = 0; i < n; i++) used[i] = false;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs1(i);
		}
	}

	for (int i = 0; i < n; i++) {
		used[i] = false;
		assignment[i] = -1;
	}
	int marker = 0;
	for (int i = 0; i < n; ++i) {
		int v = order[n - 1 - i];
		if (used[v]) continue;
		marker++;
		component[marker].clear();
		dfs2(v, component[marker]);
		for (int u : component[marker]) {
			mark[u] = marker;
		}
	}
	for (int i = 0; i < n; i += 2) {
		if (mark[i] == mark[i ^ 1]) {
			return 0;
		}
	}
	for (int i = 0; i < 2 * n; i += 2) {
		if (mark[i] < mark[i + 1]) {
			assignment[i / 2] = 1;
		}
		else {
			assignment[i / 2] = 0;
		}
	}
/*
	for (int i = marker; i >= 1; i--) {
		int to_assign = -1;
		for (int u : component[i]) {
			if (assignment[u / 2] == -1) continue;
			int my_assign = (u % 2 == 0 ? (assignment[u / 2] == 0) : (assignment[u / 2] == 1));
			if (to_assign == -1) to_assign = my_assign;
		}
		if (to_assign == -1) to_assign = 1;
		for (int u : component[i]) {
			assignment[u / 2] = (u % 2 == 0 ? (to_assign == 0) : (to_assign == 1));
		}
	}
	*/
	return 1;
}

// If a is true, b must be true.
void ForceRelation(int a, int b) {
	//printf("%d -> %d\n", a, b);
	V[a].push_back(b);
	VT[b].push_back(a);
}

int num[100005];
unordered_map<int, int> M;

void solve(int ks) {
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		M[num[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		if (M.find(a - num[i]) != M.end()) {
			ForceRelation(2 * (i - 1), 2 * (M[a - num[i]] - 1));
			ForceRelation(2 * (i - 1) + 1, 2 * (M[a - num[i]] - 1) + 1);
		}
		else {
			// i - 1 must be true
			ForceRelation(2 * (i - 1), 2 * (i - 1) + 1);
		}
		if (M.find(b - num[i]) != M.end()) {
			ForceRelation(2 * (i - 1) + 1, 2 * (M[b - num[i]] - 1) + 1);
			ForceRelation(2 * (i - 1), 2 * (M[b - num[i]] - 1));
		}
		else {
			// i - 1 must be false
			ForceRelation(2 * (i - 1) + 1, 2 * (i - 1));
		}
	}
	if (!TwoSat(n)) {
		printf("NO\n");
	}
	else {
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			if (assignment[i]) {
				assert(M.find(b - num[i + 1]) != M.end());
				assert(assignment[M[b - num[i + 1]] - 1] == 1);
			}
			else {
				assert(M.find(a - num[i + 1]) != M.end());
				assert(assignment[M[a - num[i + 1]] - 1] == 0);
			}
			printf("%d ", assignment[i]);
		}
		printf("\n");
	}
}

int main()
{
#ifdef LOCAL
	double start_time = clock();
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	if (0) {
		int T;
		scanf("%d", &T);
		for (int ks = 1; ks <= T; ks++) solve(ks);
	}
	else {
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}