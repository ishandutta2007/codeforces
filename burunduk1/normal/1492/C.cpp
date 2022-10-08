/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define DEBUG 1

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

auto solve() {
	int sn, tn;
	string s, t;
	if (!(cin >> tn >> sn >> t >> s))
		exit(0);
	int p[2][sn];
	forn(z, 2) {
		int j = 0;
		forn(i, sn) {
			while (t[j] != s[i])
				j++;
			// printf("z = %d, i = %d : j = %d (%s, %s)\n", z, i, j, s.c_str(), t.c_str());
			p[z][i] = j++;
		}
		reverse(all(s));
		reverse(all(t));
	}
	int ans = 0;
	forn(i, sn - 1) {
		ans = max(ans, tn - (p[0][i] + p[1][sn - i - 2]) - 1);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	while (1)
		cout << solve() << "\n";
}