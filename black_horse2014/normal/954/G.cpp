#include <bits/stdc++.h>
using namespace std;

const int N = 550000;

vector<pair<int, long long> > V;
long long s[N], a[N];

bool check(int n, int r, long long m, long long mid) {
	V.clear();
	long long add = 0;
	int j = 0;
	for (int i = 1; i <= n; i++) {
		while (j < V.size() && V[j].first < i - r) add -= V[j].second, j++;
		long long cur = s[min(i + r, n)] - s[max(i - r - 1, 0)] + add;
		if (cur >= mid) continue;
		V.push_back(make_pair(min(i + r, n), mid - cur));
		add += mid - cur;
		m -= mid - cur;
		if (m < 0) return 0;
	}
	return 1;
}

int main() {
	int n, r; long long m; scanf("%d%d%lld", &n, &r, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	long long st = 0, en = m + s[n] + 1;
	while (en - st > 1) {
		long long mid = st + en >> 1;
		if (check(n, r, m, mid)) st = mid;
		else en = mid;
	}
	printf("%lld\n", st);
	return 0;
}