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

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e3 + 10, P = 5e3 + 10, M = 2 * N;

int p[N], c[N], k[N], ans[N];
bool done[N];
vector<int> g[M];
bool matched[M], seen[M];
int match[M], back[M];

bool aug_path(int s, int n);
void dfs(int u, int t);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	int d; cin >> d;
	for (int i = 1; i <= d; ++i) {
		cin >> k[i];
		done[k[i]] = true;
	}
	int id = d;
	for (int i = 1; i <= n; ++i) {
		if (!done[i]) {
			done[i] = true;
			k[++id] = i;
		}
	}
	int best = 0;
	for (int i = n; i >= 1; --i) {
		ans[i] = best;
		int u = p[k[i]], v = P + c[k[i]];
		g[u].pb(v); g[v].pb(u);
		while (aug_path(best, P + m)) {
			++best;
		}
	}
	for (int i = 1; i <= d; ++i) {
		cout << ans[i] << '\n';
	}
}

bool aug_path(int s, int n) {
	if (matched[s]) {
		return false;
	}
	memset(seen, 0, sizeof(seen));
	dfs(s, 0);
	for (int i = 0; i <= n; ++i) {
		if (i != s and !matched[i] and seen[i]) {
			int u = i;
			matched[u] = matched[s] = true;
			while (true) {
				match[u] = back[u];
				match[back[u]] = u;
				if (back[u] == s) {
					break;
				} else {
					u = back[back[u]];
				}
			}
			return true;
		}
	}
	return false;
}

void dfs(int u, int t) {
	seen[u] = true;
	for (auto &v : g[u]) {
		if (seen[v]) {
			continue;
		}
		if (t == 0) {
			if (match[u] != v) {
				back[v] = u;
				dfs(v, 1);
			}
		} else {
			if (match[u] == v) {
				back[v] = u;
				dfs(v, 0);
			}
		}
	}
}