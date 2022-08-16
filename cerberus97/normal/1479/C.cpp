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

const int N = 22;

struct edge_t {
	int u, v, w;
};

int main() {
	fast_cin();
	int l, r;
	cin >> l >> r;
	int n = N;
	vector<edge_t> edges;
	for (int i = n - 1, p = 1; i > 1; --i, p *= 2) {
		int cur = 1;
		edges.pb({i, n, cur++});
		for (int j = n - 1, q = 1; j > i; --j, q *= 2) {
			edges.pb({i, j, cur - 1});
			cur += q;
		}
	}
	int i = 2, p = (1 << (n - 3));
	while (l <= r) {
		if (l == 1) {
			edges.pb({1, n, 1});
			++l;
		} else if (r - l + 1 < p) {
			++i;
			p /= 2;
		} else {
			edges.pb({1, i, l - 1});
			l += p;
		}
	}
	cout << "YES\n" << n << ' ' << edges.size() << '\n';
	for (auto& e : edges) {
		cout << e.u << ' ' << e.v << ' ' << e.w << '\n';
	}
}