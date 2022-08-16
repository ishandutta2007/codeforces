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

const int N = 1e6 + 10;
const ll inf = 1e16 + 42;

pll a[N], b[N];
ll sum[N];
int ans[N];

void add(int l, int r, ll val);

int main() {
	fast_cin();
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i].first;
		b[i].second = i;
		b[i].first -= m;
	}
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	for (int i = n + 1; i <= 3 * n; ++i) {
		b[i].first = b[i - n].first + m;
		b[i].second = b[i - n].second;
	}
	a[0].first = b[0].first = -inf;
	a[n + 1].first = b[3 * n + 1].first = inf;
	for (int i = 1; i <= n; ++i) {
		int j = upper_bound(b, b + 3 * n + 1, make_pair(a[i].first, inf)) - b;
		int k = j - i;
		add(0, k - 1, a[i].first);
		add(k, 2 * n, -a[i].first);
	}
	for (int i = 1; i <= 3 * n; ++i) {
		int j = lower_bound(a, a + n + 1, make_pair(b[i].first, -inf)) - a - 1;
		int k = i - j;
		add(max(0, i - n), min(k - 1, i - 1), -b[i].first);
		add(max(k, i - n), min(2 * n, i - 1), b[i].first);
	}
	ll best = inf, cur = 0;
	int best_id = 0;
	for (int k = 0; k <= 2 * n; ++k) {
		cur += sum[k];
		if (cur < best) {
			best = cur;
			best_id = k;
		}
	}
	cout << best << '\n';
	for (int i = 1; i <= n; ++i) {
		ans[a[i].second] = b[i + best_id].second;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << endl;
}

void add(int l, int r, ll val) {
	if (l <= r) {
		sum[l] += val;
		sum[r + 1] -= val;
	}
}