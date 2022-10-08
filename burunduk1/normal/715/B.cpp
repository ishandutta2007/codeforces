/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <vector>
#include <set>
#include <iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair <int, int> pii;

const ll inf = 1e9 + 10;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, m, L, s, t;
	cin >> n >> m >> L >> s >> t;
	vector<vector<pii>> c(n);
	vector<int> d(n), a(m), b(m), w(m);
	forn(i, m) 
		cin >> a[i] >> b[i] >> w[i];
	auto solve = [&]( ll x ) {
		forn(i, n)
			c[i].clear(), d[i] = inf;
		int len = min(x / m, inf), rest = x % m;
		forn(i, m) {
			ll z = w[i];
			if (!z)
				z = len + (rest > 0), rest--;
			c[a[i]].push_back(pii(b[i], z));
			c[b[i]].push_back(pii(a[i], z));
		}
		set<pii> heap;
		heap.insert(pii(0, s)), d[s] = 0;
		while (heap.size()) {
			int v = heap.begin()->second;
			heap.erase(heap.begin());
			for (auto e : c[v])
				if (d[e.first] > d[v] + e.second) {
					heap.erase(pii(d[e.first], e.first));
					d[e.first] = d[v] + e.second;
					heap.insert(pii(d[e.first], e.first));
				}
		}
		return d[t];
	};
	ll mi = 1 * m, ma = (ll)L * m;
	while (mi != ma) {
		ll x = (mi + ma) / 2;
		if (solve(x) < L)
			mi = x + 1;
		else
			ma = x;
	}
	if (solve(mi) != L) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	ll len = mi / m, rest = mi % m;
	forn(i, m) {
		if (!w[i]) 
			w[i] = len + (rest > 0), rest--;
		cout << a[i] << " " << b[i] << " " << w[i] << "\n";
	}
}