#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 7;
const int K = 2e3 + 7;
const int LOG = 22 + 1;

int n, m, k, s;
vector<pair<int, int> > points;

int f[K][LOG];
int factor[N << 1], rev[N << 1];

void dec(int &a, int b) {
	a = a + MOD - b;
	a %= MOD;
}

int power(int a, int n) {
	int ret = 1;
	for (int i = 1; i <= n; i <<= 1) {
		if (n & i) {
			ret = 1LL * ret * a % MOD;
		}
		a = 1LL * a * a % MOD;
	}
	return ret;
}

int ways(int x, int y) {
	return 1LL * factor[x + y] * rev[x] % MOD * rev[y] % MOD;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &k, &s);
	n--, m--;
	factor[0] = 1;
	rev[0] = 1;
	for (int i = 1; i <= n + m; i++) {
		factor[i] = 1LL * factor[i - 1] * i % MOD;
		rev[i] = power(factor[i], MOD - 2);
	}

	for (int i = 0; i < k; i++) {
		int r, c;
		scanf("%d %d", &r, &c);
		r--; c--;
		points.push_back({r, c});
	}
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());
	assert(points.size() == k);
	for (int j = 1; j <= k && j < LOG; j++) {
		for (int i = 0; i < points.size(); i++) {
			f[i][j] = ways(points[i].first, points[i].second);
			for (int l = 0; l < i; l++) {
				if (points[l].first <= points[i].first && points[l].second <= points[i].second) {
					dec(f[i][j], 1LL * f[l][j] *
						ways(points[i].first - points[l].first, points[i].second - points[l].second) % MOD);
				}
			}
			for (int l = 0; l < j; l++) {
				dec(f[i][j], f[i][l]);
			}
		}
	}
	static int ans[N];
	for (int x = 0; x <= k && x + 1 < LOG; x++) {
		ans[x] = ways(n, m);
		for (int i = 0; i < (int)points.size(); i++) {
			dec(ans[x], 1LL * f[i][x + 1] * ways(n - points[i].first, m - points[i].second) % MOD);
		}
		for (int y = 0; y < x; y++) {
			dec(ans[x], ans[y]);
		}
	}
	int answer = 0;
	int tot = ways(n, m);
	for (int i = 0; i <= k && i + 1 < LOG; i++) {
		dec(tot, ans[i]);
		answer += 1LL * s * ans[i] % MOD;
		answer %= MOD;
		s = (s + 1) / 2;
	}
	answer += tot;
	answer %= MOD;
	printf("%d\n", 1LL * answer * power(ways(n, m), MOD - 2) % MOD);
	return 0;
}