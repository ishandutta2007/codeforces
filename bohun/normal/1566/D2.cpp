//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

template<typename T, int N>
struct fenwick {
	T f[N];
	void add(int x, T y) {
		for (x++; x < N; x += x & -x)
			f[x] += y;
	}
	T query(int x) {
		T res = 0;
		for (x++; 0 < x; x -= x & -x)
			res += f[x];
		return res;
	}
	T range(int l, int r) {
		return query(r) - query(l - 1);
	};
};

const int N = 400;
fenwick<int, N> F[N];
int n, m, a[N * N], b[N * N];
map<int, set<pair<int, int>>> M;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		FOR(i, n * m) {
			cin >> a[i];
			b[i] = a[i];
		}
		sort(a, a + n * m);

		FOR(i, n * m) {
			int r = i / m;
			int c = i % m;
			M[a[i]].insert(make_pair(r, -c));
		}

		ll res = 0;
		FOR(i, n * m) {
			assert(!M[b[i]].empty());
			auto [r, c] = *M[b[i]].begin();
			c = -c;
			M[b[i]].erase(M[b[i]].begin());

			res += F[r].query(c);
			F[r].add(c, 1);
		}
		cout << res << '\n';

		FOR(i, n) 
			FOR(j, m) 
				F[i].add(j, -1);
	}
	return 0;
}