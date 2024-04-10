/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int M = 2e5 + 1;
const int MOD = 1e9 + 7;

int d[M];

int main() {
	for (int i = 2; i < M; i++)
		if (!d[i]) {
			d[i] = i;
			for (int j = i + i; j < M; j += i)
				if (!d[j])
					d[j] = i;
		}

	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, q;
	cin >> n >> q;

	vector<map<int, int>> cnt(n);
	map<int, multiset<int>> degs;
	int r = 1;

	auto get = [&](int p) {
		auto &d = degs[p];
		return (int)d.size() != n ? 0 : *d.begin();
	};
	auto inc = [&](int i, int p) {
		auto old = get(p);
		auto &x = cnt[i][p];
		auto &d = degs[p];
		if (x)
			d.erase(d.find(x));
		d.insert(++x);
		if (get(p) != old)
			r = ((int64_t)r * p) % MOD;
	};

	auto process = [&](int i, int x) {
		for (; x > 1; x /= d[x])
			inc(i, d[x]);
	};

	forn(i, n) {
		int x;
		cin >> x;
		process(i, x);
	}
	while (q--) {
		int i, x;
		cin >> i >> x, i--;
		process(i, x);
		cout << r << "\n";
	}
}