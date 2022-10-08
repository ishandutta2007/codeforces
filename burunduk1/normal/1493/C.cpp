/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

const int E = 26;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	// printf("n = %d, k = %d, s = %s\n", n, k, s.c_str());
	vector<int> cnt(E);
	for (char c : s)
		cnt[c - 'a']++;

	auto need = [&]() {
		int r = 0;
		forn(i, E)
			if (cnt[i] % k)
				r += k - cnt[i] % k;
		return r;
	};
	if (!need()) {
		cout << s << "\n";
		return;
	}

	auto can = [&](int i, int d) {
		cnt[d]++;
		int r = need(), have = n - i - 1;
		cnt[d]--;
		// printf("i = %d, d = %d : need = %d, have = %d\n", i, d, r, have);
		return have >= r && (have - r) % k == 0;
	};
	auto set = [&](int i, int d) {
		s[i] = 'a' + d;
		cnt[d]++;
	};

	for (int i = n - 1; i >= 0; i--) {
		int x = s[i] - 'a';
		cnt[x]--;
		for (int d = x + 1; d < E; d++) {
			if (can(i, d)) {
				set(i, d);
				for (i++; i < n; i++)
					forn(d, E)
						if (can(i, d))
							set(i, d), d = E;
				cout << s << "\n";
				return;
			}
		}
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}