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

const int N = 1e5 + 10;

ll give[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		give[u] += d;
		give[v] -= d;
	}
	vector<int> ids(n);
	iota(ids.begin(), ids.end(), 1);
	sort(ids.begin(), ids.end(), [&] (int i, int j) {
		return give[i] < give[j];
	});
	vector<pair<pii, ll>> owes;
	int l = 0, r = n - 1;
	while (l < r) {
		int u = ids[l], v = ids[r];
		if (give[u] == 0) {
			++l;
		} else if (give[v] == 0) {
			--r;
		} else {
			ll here = min(-give[u], give[v]);
			owes.pb({{v, u}, here});
			give[u] += here;
			give[v] -= here;
		}
	}
	cout << owes.size() << '\n';
	for (auto &p : owes) {
		cout << p.first.first << ' ' << p.first.second << ' ' << p.second << '\n';
	}
}