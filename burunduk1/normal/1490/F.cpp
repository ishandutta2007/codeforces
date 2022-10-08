/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

mt19937 gen(time(NULL));

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--) {
		int n, a;
		cin >> n;
		unordered_map<int, int> cnt(n + gen() % n);
		vector<int> k(n + 1);
		forn(_, n)
			cin >> a, cnt[a]++;
		for (auto& [a, b] : cnt)
			k[b]++;
		for (int i = n - 1; i >= 0; i--)
			k[i] += k[i + 1];

		int ans = n;
		for (int c = 1; c <= n; c++)
			ans = min(ans, n - k[c] * c);
		cout << ans << "\n";
	}
}