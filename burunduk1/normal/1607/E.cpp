/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

void solve() {
	// 4 3
	// LUURRDDLLLUU
	int w, h;
	string s;
	cin >> h >> w >> s;
	map<char, int> dx = {{'L', -1}, {'R', 1}, {'D', 0}, {'U', 0}};
	map<char, int> dy = {{'L', 0}, {'R', 0}, {'D', 1}, {'U', -1}};

	int min_x = 0, max_x = 0, x = 0, ans_x = 0;
	int min_y = 0, max_y = 0, y = 0, ans_y = 0;
	for (char c : s) {
		x += dx[c], y += dy[c];
		min_x = min(min_x, x);
		max_x = max(max_x, x);
		min_y = min(min_y, y);
		max_y = max(max_y, y);
		// printf("x=%d, y=%d, [%d..%d] [%d..%d]\n", x, y, min_x, max_x, min_y, max_y);
		if (!(max_x - min_x + 1 <= w and max_y - min_y + 1 <= h))
			break;
		ans_x = -min_x;
		ans_y = -min_y;
	}
	cout << ans_y+1 << " " << ans_x+1 << "\n";
}

int main() {
	int tn;
	cin >> tn;
	while (tn--)
		solve();
}