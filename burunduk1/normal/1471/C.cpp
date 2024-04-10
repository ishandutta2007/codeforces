/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define read(T, a, n) vector<T> a(n); for (auto &z : a) cin >> z

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int n, m;
		cin >> n >> m;
		read(int, k, n);
		read(int, c, m);
		sort(all(k), greater<int>());

		int64_t sum = 0;
		int i = 0;
		for (auto j : k)
			j--, sum += c[i <= j ? i++ : j];
		cout << sum << "\n";
	}
}