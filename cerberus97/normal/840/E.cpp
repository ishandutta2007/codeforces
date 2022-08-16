/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e4 + 10, K = 256, B = 16;

int a[N], parent[N], depth[N], up[N], ans[N][K];
vector <int> g[N];
bitset <(1 << (B + 1)) + 10> trie;

void make_tries(int i, int par);
void trie_insert(int val);
void trie_clear(int val);
int trie_max(int val);

int main() {
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	make_tries(1, 0);
	while(q--) {
		int u, v;
		cin >> u >> v;
		int dist = 0, res = 0;
		while (depth[v] - depth[u] >= K - 1) {
			res   = max(res, ans[v][dist]);
			v     = up[v];
			++dist;
		}

		dist <<= 8;
		while (depth[v] >= depth[u]) {
			res = max(res, dist xor a[v]);
			v   = parent[v];
			++dist;
		}

		cout << res << endl;
	}
}

void make_tries(int i, int par) {
	parent[i] = par;
	depth[i]  = 1 + depth[par];
	if (depth[i] >= K) {
		int u    = i;
		int dist = 0;
		while (depth[i] - depth[u] <= K - 1) {
			trie_insert(dist xor a[u]);
			u = parent[u];
			++dist;
		}

		for (int d = 0; d < K; ++d) {
			ans[i][d] = trie_max(d << 8);
		}

		up[i] = u;
		dist  = 0;
		u     = i;
		while (depth[i] - depth[u] <= K - 1) {
			trie_clear(dist xor a[u]);
			u = parent[u];
			++dist;
		}
	}

	for (auto &j : g[i]) {
		if (j != par) {
			make_tries(j, i);
		}
	}
}

void trie_insert(int val) {
	int pos = 1;
	for (int b = B - 1; b >= 0; --b) {
		pos = (pos << 1) | ((val & (1 << b)) >> b);
		trie[pos] = 1;
	}
}

void trie_clear(int val) {
	int pos = 1;
	for (int b = B - 1; b >= 0; --b) {
		pos = (pos << 1) | ((val & (1 << b)) >> b);
		trie[pos] = 0;
	}
}

int trie_max(int val) {
	int pos = 1, res = 0;
	for (int b = B - 1; b >= 0; --b) {
		pos = (pos << 1) | (((val & (1 << b)) >> b) ^ 1);
		if (trie[pos]) {
			res |= (1 << b);
		} else {
			pos ^= 1;
		}
	}

	return res;
}