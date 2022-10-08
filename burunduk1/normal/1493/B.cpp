/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

//          0  1  2   3   4  5  6   7  8  9
int to[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

void solve() {
	int h, m, h0, m0;
	assert(scanf("%d%d %d:%d", &h, &m, &h0, &m0) == 4);
	assert(h0 < h && m0 < m);

	auto good = [&]() {
		int a = h0 / 10, b = h0 % 10, c = m0 / 10, d = m0 % 10;
		if (to[a] == -1 || to[b] == -1 || to[c] == -1 || to[d] == -1)
			return false;
		int h1 = to[d] * 10 + to[c];
		int m1 = to[b] * 10 + to[a];
		return h1 < h && m1 < m;
	};
	while (!good()) {
		if (++m0 == m) {
			m0 = 0;
			if (++h0 == h)
				h0 = 0;
		}
	}
	printf("%02d:%02d\n", h0, m0);
}

int main() {
	int tn;
	assert(scanf("%d", &tn) == 1);
	while (tn--)
		solve();
}