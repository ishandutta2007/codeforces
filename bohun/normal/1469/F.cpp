#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	

int n, k, l[1 << 20];
ll cnt[1 << 20], lazy[1 << 20];

bool solve(int d) {
	memset(lazy, 0, sizeof lazy);
	memset(cnt, 0, sizeof cnt);
	cnt[0] = 1;
	ll s = 1;
	for (int j = 0, i = 0; i < n; ++i) {
		while (j <= d && !cnt[j]) {
			j++;
			lazy[j] += lazy[j - 1];
			cnt[j] += lazy[j];
		}
		if (j == d + 1) break;
		s--;
		cnt[j]--;
		int m = 2 * (d - j - 1);
		if (!m) break;
		int have = min(m, l[i] - 1);
		int p0 = have / 2;
		int p1 = have % 2;
		if (p1 == 1)
			cnt[j + 2 + p0]++;
		lazy[j + 2] += 2;
		lazy[j + 2 + p0] -= 2;
		s += have;
		if (s >= k) return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", l + i);
	sort(l, l + n, greater<int>());
	ll l = 2, r = 1e9;
	while (l < r) {
		ll m = (l + r) / 2;
		if (solve(m))
			r = m;
		else
			l = m + 1;
	}
	if (l == 1e9) l = -1;
	printf("%lld\n", l);
	return 0;
}