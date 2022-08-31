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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

struct S {
	ll prod;
	int a_ind, b_ind;
	bool operator<(const S &other) const {
		return prod < other.prod;
	}
};

ll a[N], b[N];
priority_queue<S> pq;

int main() {
	ll n, m, r, k;
	cin >> n >> m >> r >> k;
	for (int i = 1; i <= n; ++i) {
		int lo = max(1ll, i - r + 1);
		int hi = min(ll(i), n - r + 1);
		a[i] = hi - lo + 1;
		// cout << i << ' ' << a[i] << endl;
	}

	for (int i = 1; i <= m; ++i) {
		int lo = max(1ll, i - r + 1);
		int hi = min(ll(i), m - r + 1);
		b[i] = hi - lo + 1;
		// cout << i << ' ' << b[i] << endl;
	}

	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + m);
	for (int i = 1; i <= n; ++i) {
		pq.push({a[i] * b[m], i, m});
	}

	ll ans = 0;
	for (int i = 1; i <= k; ++i) {
		auto cur = pq.top();
		pq.pop();
		ans += cur.prod;
		if (cur.b_ind > 1) {
			--cur.b_ind;
			cur.prod = a[cur.a_ind] * b[cur.b_ind];
			pq.push(cur);
		}
	}

	cout << fixed << setprecision(15);
	cout << ld(ans) / ld((n - r + 1) * (m - r + 1)) << endl;
}