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

const int N = 1e5 + 10;

vector<int> g[N];
int a1[N], a2[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int pi = -1, pj = -1;
	for (int i = 1; i <= n; ++i) {
		if (g[i].size() == n - 1) {
			continue;
		}
		pi = i;
		set<int> s;
		for (auto &j : g[i]) {
			s.insert(j);
		}
		s.insert(pi);
		for (int j = 1; j <= n; ++j) {
			if (s.find(j) == s.end()) {
				pj = j;
				break;
			}
		}
		break;
	}
	if (pi == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		int nxt = 3;
		for (int i = 1; i <= n; ++i) {
			if (i != pi and i != pj) {
				a1[i] = a2[i] = nxt++;
			}
		}
		a1[pi] = 1; a1[pj] = 2;
		a2[pi] = 1; a2[pj] = 1;
		for (int i = 1; i <= n; ++i) {
			cout << a1[i] << ' ';
		}
		cout << '\n';
		for (int i = 1; i <= n; ++i) {
			cout << a2[i] << ' ';
		}
		cout << '\n';
	}
}