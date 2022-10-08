/**
12121212121212121212
21212121212121212121
12121212121212121212
2121212121212121212.
.2.2.2.2.2.2.2.2.2.2
2.2.2.2.2.2.2.2.2.2.


*/

/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> p[2];
	forn(i, n)
		forn(j, n)
			p[(i + j) % 2].push_back({i, j});

	size_t k[2] = {0, 0};
	auto out = [](pair<int, int> a, int c) {
		printf("%d %d %d\n", c + 1, a.first + 1, a.second + 1);
		fflush(stdout);
	};
	auto ask = []() {
		int x;
		cin >> x, x--;
		return x;
	};
	while (k[0] < p[0].size() && k[1] < p[1].size()) {
		if (ask() == 0)
			out(p[1][k[1]++], 1);
		else
			out(p[0][k[0]++], 0);
	}
	forn(t, 2)
		while (k[t] < p[t].size()) 
			out(p[t][k[t]++], ask() == t ? 2 : t);
}