#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<vector<int>> sum1(n + 1, vector<int>(m + 1));
	vector<vector<int>> sum2(n + 1, vector<int>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum1[i + 1][j + 1] = sum1[i][j + 1] + sum1[i + 1][j] - sum1[i][j] + (a[i][j] == 'X');
		}
	}
	auto calc1 = [&](int __x1, int __y1, int __x2, int __y2) {
		return sum1[__x2][__y2] - sum1[__x1][__y2] - sum1[__x2][__y1] + sum1[__x1][__y1];
	};
	auto calc2 = [&](int __x1, int __y1, int __x2, int __y2) {
		__x1 = max(__x1, 0), __y1 = max(__y1, 0), __x2 = min(__x2, n), __y2 = min(__y2, m);
		return sum2[__x2][__y2] - sum2[__x1][__y2] - sum2[__x2][__y1] + sum2[__x1][__y1];
	};
	auto can = [&](int mid, int print_mode = 0) {
		for (int i = 0; i <= n; i++) 
			for (int j = 0; j <= m; j++) {
				sum2[i][j] = 0;
			}
		for (int i = mid; i + mid < n; i++)
			for (int j = mid; j + mid < m; j++) {
				if (a[i][j] == 'X' && calc1(i - mid, j - mid, i + mid + 1, j + mid + 1) == (long long)(2 * mid + 1) * (2 * mid + 1)) {
					sum2[i + 1][j + 1] = 1;
				} else {
					sum2[i + 1][j + 1] = 0;
				}
			}
		if (!print_mode) {
			for (int i = 1; i <= n; i++) 
				for (int j = 1; j <= m; j++) {
					sum2[i][j] += sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1];
				}
			for (int i = 0; i < n; i++) 
				for (int j = 0; j < m; j++) {
					if (a[i][j] == 'X' && calc2(i - mid, j - mid, i + mid + 1, j + mid + 1) == 0) {
						return false;
					}
				}
			return true;
		} else {
			return true;
		}
	};
	int st = 0, en = (min(n, m) + 1) / 2;
	int ret = 0;
	while (en - st > 1) {
		int mid = st + en >> 1;
		if (can(mid)) {
			ret = mid;
			st = mid;
		} else {
			en = mid;
		}
	}
	cout << ret << "\n";
	can(ret, 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << (sum2[i][j] ? 'X' : '.');
		}
		cout << "\n";
	}
	return 0;
}