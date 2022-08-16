/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, M = 130;

int a[N], nxt[N][M];
map<vector<int>, int> id;
vector<int> rev[M];
int compose[M][M];
bool reach[M];

int gen_permutations(int k);
int bfs(vector<int> g, int s);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	int tot = gen_permutations(k);
	for (int i = 1; i <= n; ++i) {
		vector<int> P(k);
		for (auto &j : P) {
			cin >> j;
			--j;
		}
		a[i] = id[P];
	}
	for (int j = 1; j <= tot; ++j) {
		nxt[n + 1][j] = n + 1;
	}
	for (int i = n; i >= 1; --i) {
		for (int j = 1; j <= tot; ++j) {
			nxt[i][j] = nxt[i + 1][j];
		}
		nxt[i][a[i]] = i;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		vector<pii> pos;
		for (int j = 1; j <= tot; ++j) {
			reach[j] = false;
			if (nxt[i][j] <= n) {
				pos.pb({nxt[i][j], j});
			}
		}
		sort(pos.begin(), pos.end());
		pos.pb({n + 1, 1});
		vector<int> g = {1};
		reach[1] = true;
		ll cnt = 1, prv = i;
		for (auto &temp : pos) {
			int p = temp.first, j = temp.second;
			ans += cnt * (p - prv);
			prv = p;
			if (!reach[j]) {
				g.pb(j);
				cnt += bfs(g, j);
			}
		}
	}
	cout << ans << endl;
}

int gen_permutations(int k) {
	vector<int> P(k);
	iota(P.begin(), P.end(), 0);
	int lid = 0;
	do {
		id[P] = ++lid;
		rev[lid] = P;
	} while (next_permutation(P.begin(), P.end()));
	for (int i = 1; i <= lid; ++i) {
		for (int j = 1; j <= lid; ++j) {
			vector<int> Q(k);
			for (int p = 0; p < k; ++p) {
				Q[p] = rev[i][rev[j][p]];
			}
			compose[i][j] = id[Q];
		}
	}
	return lid;
}

int bfs(vector<int> g, int s) {
	reach[s] = true;
	queue<int> q;
	q.push(s);
	int cnt = 0;
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		++cnt;
		for (auto &e : g) {
			int v = compose[u][e];
			if (!reach[v]) {
				reach[v] = true;
				q.push(v);
			}
			v = compose[e][u];
			if (!reach[v]) {
				reach[v] = true;
				q.push(v);
			}
		}
	}
	return cnt;
}