#include <bits/stdc++.h>

using namespace std;

const int N = 7e3 + 4;

vector<int> a[2];

int n;

int f[N][2], cnt[N][2];

void place(int pos, int who, bool win) {
	// cout << pos << " " << who << " " << win << endl;
	f[pos][who] = win;
	if (win == 0) {
		for (auto v : a[who ^ 1]) {
			int u = pos - v;
			if (u < 0) u += n;
			if (f[u][who ^ 1] == -1) {
				place(u, who ^ 1, 1);
			}
		}
	} else {
		for (auto v : a[who ^ 1]) {
			int u = pos - v;
			if (u < 0) u += n;
			if (f[u][who ^ 1] == -1) {
				if (++cnt[u][who ^ 1] == a[who ^ 1].size()) {
					place(u, who ^ 1, 0);
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		a[0].push_back(x);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		a[1].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		f[i][0] = f[i][1] = -1;
	}
	f[0][0] = f[0][1] = 0;
	place(0, 0, 0);
	place(0, 1, 0);
	for (int who = 0; who < 2; who++) {
		for (int i = 1; i < n; i++) {
			if (f[i][who] == 1) {
				printf("Win");
			} else if (f[i][who] == 0) {
				printf("Lose");
			} else {
				printf("Loop");
			}
			printf("%c", i + 1 == n ? '\n' : ' ');
		}
	}
	return 0;
}