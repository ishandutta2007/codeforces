/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define read(T, a, n) vector<T> a(n); for (auto &z : a) cin >> z

const int M = 1e6;

vector<int> p;
bool is[M];

int main() {
	for (int i = 2; i < M; i++)
		if (!is[i]) {
			p.push_back(i);
			for (int j = i + i; j < M; j += i)
				is[j] = 1;
		}

	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int n, a;
		cin >> n;
		unordered_map<int, int> cnt;
		while (n--) {
			cin >> a;
			for (int i = 0; p[i] * p[i] <= a; i++)
				while (a % (p[i] * p[i]) == 0)
					a /= p[i] * p[i];
			cnt[a]++;
		}

		int z0 = 0;
		for (auto [a, x] : cnt)
			z0 = max(z0, x);
		int z1 = 0;
		for (auto [a, x] : cnt)
			if (a == 1 || x % 2 == 0)
				z1 += x;

		int q;
		cin >> q;
		while (q--) {
			int64_t w;
			cin >> w;
			cout << (w == 0 ? z0 : max(z0, z1)) << "\n";
		}
	}
}