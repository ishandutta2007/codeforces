#include <bits/stdc++.h>
using namespace std;

int seed;
const int mod = 1e9 + 7;

inline int rnd() {
	int ret = seed;
	seed = (7LL * seed + 13) % mod;
	return ret;
}

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}

const int MAXN = 110000;
const int B = 200;
const long long inf = 1LL<<50;

long long a[MAXN];

map<int, int> b;

vector<int> c;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, vmax; scanf("%d%d%d%d", &n, &m, &seed, &vmax);
	for (int i = 1; i <= n; i++) a[i] = rnd() % vmax + 1;
	b[0] = 1;
	for (int i = 1, j; i <= n; i = j) {
		for (j = i; j <= n && a[i] == a[j]; j++);
		b[i] = j;
	}
	b[n+1] = n+2;
	auto split = [](int l) {
		auto it = --b.upper_bound(l);
		int ll = it->first;
		if (ll < l) {
			b[l] = b[ll];
			a[l] = a[ll];
			b[ll] = l;
		}
	};
	auto merge = [](int l) {
		auto it = --b.lower_bound(l);
		int ll = it->first;
		if (a[ll] == a[l]) {
			b[ll] = b[l];
			b.erase(l);
		}
	};
	while (m--) {
	    int op = (rnd() % 4) + 1;
	    int l = (rnd() % n) + 1;
	    int r = (rnd() % n) + 1;
	    if (l > r) swap(l, r);
	    int x, y;
	    if (op != 3) x = rnd() % vmax + 1;
	    else x = rnd() % (r - l + 1) + 1;
	    if (op == 4) y = rnd() % vmax + 1;
	    split(l);
	    if (r < n) split(r+1);
	    c.clear();
	    for (auto it = b.lower_bound(l); it->first <= r; it++) c.push_back(it->first);
	    if (op == 1) {
	    	for (auto p : c) a[p] += x;
		} else if (op == 2) {
			a[l] = x;
			for (auto p : c) b.erase(p);
			b[l] = r+1;
		} else if (op == 3) {
			long long lo = 0, hi = 1LL<<50;
			while (hi - lo > 1) {
				long long mid = lo + hi >> 1;
				int ret = 0;
				for (auto p : c) {
					if (a[p] <= mid) ret += b[p] - p;
					if (ret >= x) break;
				}
				if (ret >= x) hi = mid;
				else lo = mid;
			}
			merge(l);
			if (r < n) merge(r+1);
			printf("%lld\n", hi);
		} else {
			int ret = 0;
			for (auto p : c) ret = (ret + 1LL * (b[p] - p) * modExp(a[p] % y, x, y)) % y;
			printf("%d\n", ret);
		}
	}
	return 0;
}