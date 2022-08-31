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
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3000 + 10;
const ll inf = 	1e15;

struct V {
	int p, c, idx;
	bool operator<(const V &o) {
		if (p == o.p) {
			return c < o.c;
		}
		return p < o.p;
	}
} v[N];

struct W {
	int p, c, idx;
	bool operator<(const W &o) {
		return c < o.c;
	}
} w[N];

bool used[N];
int ctr[N];

ll get_cost(int k, int n);

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i].p >> v[i].c;
		w[i].p = v[i].p;
		w[i].c = v[i].c;
		v[i].idx = w[i].idx = i;
	}
	sort(v + 1, v + 1 + n);
	sort(w + 1, w + 1 + n);
	// for (int i = 0; i <= n; ++i) {
	// 	cout << i << ' ' << get_cost(i, n) << endl;
	// }
	ll ans = inf;
	for (int i = 0; i <= n; ++i) {
		ans = min(ans, get_cost(i, n));
	}
	cout << ans << endl;
}

ll get_cost(int k, int n) {
	memset(used, 0, sizeof(used));
	memset(ctr, 0, sizeof(ctr));
	for (int i = 1; i <= n; ++i) {
		++ctr[v[i].p];
	}
	ll cost = 0;
	for (int i = 1; i <= n; ++i) {
		if (v[i].p != 1 and ctr[v[i].p] >= k) {
			--ctr[v[i].p];
			++ctr[1];
			cost += v[i].c;
			used[v[i].idx] = true;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (v[i].p != 1 and ctr[v[i].p] >= k) {
			return inf;
		}
	}
	if (ctr[1] > k) {
		return inf;
	}
	for (int i = 1; i <= n and ctr[1] < k; ++i) {
		if (!used[w[i].idx] and w[i].p != 1) {
			cost += w[i].c;
			used[w[i].idx] = true;
			++ctr[1];
			--ctr[w[i].p];
		}
	}
	return cost;
}