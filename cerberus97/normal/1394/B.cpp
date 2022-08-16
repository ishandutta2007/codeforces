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

const int N = 2e5 + 10, K = 10, K2 = 50;

vector<pii> g[N];
bool banned[K2][K2];
int id[K][K];
int cnt_ids[N][K2];
int nid;

void recurse(int i, ll mask, int k, int& ans);

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb({w, v});
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < i; ++j) {
			id[i][j] = nid++;
		}
	}
	for (int u = 1; u <= n; ++u) {
		sort(g[u].begin(), g[u].end());
		int sz = g[u].size();
		for (int i = 0; i < sz; ++i) {
			cnt_ids[g[u][i].second][id[sz][i]]++;
		}
	}
	for (int u = 1; u <= n; ++u) {
		for (int id1 = 0; id1 < nid; ++id1) {
			if (cnt_ids[u][id1] >= 2) {
				banned[id1][id1] = true;
			}
			for (int id2 = 0; id2 < id1; ++id2) {
				if (cnt_ids[u][id1] and cnt_ids[u][id2]) {
					banned[id1][id2] = true;
				}
			}
		}
	}
	int ans = 0;
	recurse(1, 0, k, ans);
	cout << ans << '\n';
}

void recurse(int i, ll mask, int k, int& ans) {
	if (i > k) {
		++ans;
	} else {
		for (int j = 0; j < i; ++j) {
			int here = id[i][j];
			bool ok = !banned[here][here];
			for (int other = 0; other < nid; ++other) {
				if (((mask >> other) & 1) and (banned[here][other] or banned[other][here])) {
					ok = false;
					break;
				}
			}
			if (ok) {
				recurse(i + 1, mask | (1ll << id[i][j]), k, ans);
			}
		}
	}
}