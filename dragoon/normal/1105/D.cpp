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

char grid[1003][1003];
int n, m, p;
int pwr[10];
queue<PII> Q;
int ans[10];

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void Expand(VP& V, int player) {
	queue<tuple<int, int, int>> Qs;
	for (auto& p : V) Qs.push(make_tuple(p.first, p.second, pwr[player] ));
	while (!Qs.empty()) {
		auto u = Qs.front();
		Qs.pop();

		if (std::get<2>(u) == 0) continue;
		for (int d = 0; d < 4; d++) {
			int r = std::get<0>(u) + dr[d];
			int c = std::get<1>(u) + dc[d];
			if (r < 0 || r >= n || c < 0 || c >= m) continue;
			if (grid[r][c] != '.') continue;
			grid[r][c] = player + '0';
			Qs.push(make_tuple( r, c, get<2>(u) - 1 ));
			Q.push({ r, c });
		}
	}
}

void solve(int ks) {
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 1; i <= p; i++) {
		scanf("%d", &pwr[i]);
	}
	for (int i = 0; i < n; i++) scanf("%s", grid[i]);
	for (int i = 1; i <= p; i++) {
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				if (grid[r][c] == i + '0') {
					Q.push({ r, c });
				}
			}
		}
	}
	while (!Q.empty()) {
		PII u = Q.front();
		VP V;
		while (!Q.empty()) {
			PII v = Q.front();
			if (grid[v.first][v.second] != grid[u.first][u.second]) break;
			V.push_back(v);
			Q.pop();
		}
		Expand(V, grid[u.first][u.second] - '0');
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.' || grid[i][j] == '#') continue;
			ans[grid[i][j] - '0']++;
		}
	}
	for (int i = 1; i <= p; i++) {
		printf("%d ", ans[i]);
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