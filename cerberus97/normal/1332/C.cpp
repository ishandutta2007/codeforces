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

const int N = 2e5 + 10;

int par[N];
vector<int> in[N];

int get_root(int u);
void merge(int u, int v);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, k; string s;
		cin >> n >> k >> s;
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			in[i] = {i};
		}
		for (int i = 0; i + k < n; ++i) {
			merge(i, i + k);
		}
		for (int i = 0; i < n; ++i) {
			merge(i, n - i - 1);
		}
		int ans = n;
		for (int i = 0; i < n; ++i) {
			if (i != par[i]) {
				continue;
			}
			int mx = 0;
			map<char, int> freq;
			for (auto& j : in[i]) {
				++freq[s[j]];
			}
			for (auto& p : freq) {
				mx = max(mx, p.second);
			}
			ans -= mx;
		}
		cout << ans << '\n';
	}
}

int get_root(int u) {
	if (u != par[u]) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

void merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return;
	}
	if (in[u].size() < in[v].size()) {
		swap(u, v);
	}
	for (auto& w : in[v]) {
		in[u].pb(w);
	}
	in[v].clear();
	par[v] = u;
}