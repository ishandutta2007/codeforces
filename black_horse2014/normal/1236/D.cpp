#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

vector<int> C[N], R[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, k; cin >> n >> m >> k;
	long long tot = 1LL * n * m - k;
	while (k--) {
		int x, y; cin >> x >> y;
		C[y].push_back(x);
		R[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		R[i].push_back(0);
		R[i].push_back(m + 1);
		sort(R[i].begin(), R[i].end());
	}
	for (int i = 1; i <= m; i++) {
		C[i].push_back(0);
		C[i].push_back(n + 1);
		sort(C[i].begin(), C[i].end());
	}
	auto solve = [&](int n, int m, vector<int> R[], vector<int> C[]) {
		int Lx = 1, Rx = n, Ly = 1, Ry = m;
		int x = 1, y = 1, d = 1, _x, _y;
		long long ans = 1;
		while (Lx <= Rx && Ly <= Ry) {
			_x = x, _y = y;
			if (d == 1) {
				_y = min(Ry, *upper_bound(R[x].begin(), R[x].end(), y) - 1);
				Ry = _y;
				Lx++;
			} else if (d == 2) {
				_x = min(Rx, *upper_bound(C[y].begin(), C[y].end(), x) - 1);
				Rx = _x;
				Ry--;
			} else if (d == 3) {
				_y = max(Ly, *(--lower_bound(R[x].begin(), R[x].end(), y)) + 1);
				Ly = _y;
				Rx--;
			} else {
				_x = max(Lx, *(--lower_bound(C[y].begin(), C[y].end(), x)) + 1);
				Lx = _x;
				Ly++;
			}
			d++;
			ans += abs(x - _x) + abs(y - _y);
			if (d > 4) d = 1;
			x = _x, y = _y;
		}
		return ans == tot;
	};
	if (!solve(n, m, R, C) && !solve(m, n, C, R)) puts("No");
	else puts("Yes");
	return 0;
}