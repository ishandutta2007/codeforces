#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int N = 1e5 + 5;

int n;
long long bound, cf, cm, m, sum[N];
pair<long long, int> a[N];

bool bySec(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}

int main() {
	cin >> n >> bound >> cf >> cm >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i].first);
		a[i].second = i;
	}
	a[0].first = 0;
	a[n + 1].first = bound;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i].first;
	}

	long long choose = -1, level = -1, amount = -1, bak_m = m;
	for (int i = n + 1; i >= 1; i--) {
		if (i <= n) {
			if (bound - a[i].first > m) {
				break;
			} else {
				m -= (bound - a[i].first);
			}
		}
		int l = 0, r = i - 1;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (1LL * a[mid].first * mid - sum[mid] <= m) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		long long min_level;
		if (l == 0) {
			min_level = bound;
		} else {
			min_level = a[l].first + (m - (1LL * a[l].first * l - sum[l])) / l;
		}
		min_level = min(min_level, bound);
		if (l + 1 < i) {
			min_level = min(min_level, a[l + 1].first);
		}
		if (min_level * cm + (n - i + 1) * cf > amount) {
			amount = min_level * cm + (n - i + 1) * cf;
			choose = i;
			level = min_level;
		}
	}

	m = bak_m;
	for (int i = choose; i <= n; i++) {
		m -= bound - a[i].first;
		a[i].first = bound;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i].first < level) {
			a[i].first = level;
		}
	}
	sort(a + 1, a + n + 1, bySec);
	cout << amount << endl;
	for (int i = 1; i <= n; i++) {
		printf("%I64d%c", a[i].first, i == n ? '\n' : ' ');
	}
	return 0;
}