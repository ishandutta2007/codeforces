#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
set<pair<int, int>> S;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

void add(int x, int y) {
	if (S.count(make_pair(x, y))) return;
	S.emplace(x, y);
	printf("%d %d\n", x, y);
}

int main() {
	int n; cin >> n;
	if (n <= 10) {
		for (int i = 0; i < n; i++) printf("%d 0\n", i);
		return 0;
	}
	int m = n / 3 + 1;
	if (n >= 40) {
		for (int i = 2; i < m; i++) {
			for (int j = 2; j <= 4; j++) {
				if ((i + j) % 2 == 0) add(j, i);
			}
		}
		int K = n - S.size();
		int D = (K + 1) / 2, U = K / 2;
		for (int i = 0; i < D; i++) add(i, 1);
		for (int i = 0; i < U; i++) add(i, m);
	} else {
		int m = n / 3 + 2;
		int rest = n;
		for (int i = 0; i <= m && rest; i++) {
			for (int j = 0; j <= m && rest; j++) {
				if (i >= 3 && j >= 3) continue;
				if ((i+j)&1) {
					add(i, j);
					rest--;
				}
			}
		}
	}
}