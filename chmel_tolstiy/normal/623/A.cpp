#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
int e[512][512];
int d[512];

char s[512];

bool dfs(int v, char c) {
	if (s[v] != 0) {
		return s[v] == c;
	}
	s[v] = c;
	for (int i = 0; i < n; ++i) if (i != v && e[v][i] == 0) {
		if (!dfs(i, 'a' + 'c' - c))
			return false;
	}
	return true;
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		--x; --y;
		e[x][y] = e[y][x] = 1;
		d[x]++;
		d[y]++;
	}

	for (int i = 0; i < n; ++i) {
		if (s[i] != 0)
			continue;
		if (d[i] == n - 1) {
			s[i] = 'b';
		} else {
			if (dfs(i, 'a') == false) {
				cout << "No" << endl;
				return;
			}
		}
	}

	for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
		bool f = false;
		f |= s[i] == 'a' && s[j] == 'c';
		f |= s[i] == 'c' && s[j] == 'a';
		if (f && e[i][j]) {
			cout << "No" << endl;
			return;
		}
		if (!f && !e[i][j]) {
			cout << "No" << endl;
			return;
		}
	}

	cout << "Yes" << endl;
	cout << s << endl;
}

int main() {
	cin.sync_with_stdio(false);
	solve();
	return 0;
}