#include<bits/stdc++.h>
using namespace std;
#define MAXN	2000005
long long sum[MAXN], cnt[MAXN], a[MAXN];
long long x, y, z;
int tot, prime[MAXN], f[MAXN];
bool Isprime[MAXN];
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n >> x >> y;
	z = x / y;
	long long mx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		mx = max(mx, a[i]);
	}
	for (int i = 1; i <= mx * 2; i++) {
		cnt[i] += cnt[i - 1];
		sum[i] = cnt[i - 1] + sum[i - 1];
	}
	for (int i = 2; i <= max(mx, 2ll); i++) {
		if (f[i] == 0) {
			f[i] = i;
			prime[++tot] = i;
			Isprime[i] = true;
		}
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > mx) break;
			f[tmp] = prime[j];
		}
	}
	long long ans = x * n;
	for (int i = 2; i <= max(mx, 2ll); i++) {
		if (!Isprime[i]) continue;
		long long now = 0, j = i;
		for (j = i; j <= mx; j += i) {
			if (z < i) now += x * (cnt[j - z - 1] - cnt[j - i]);
			int tmp = max(j - z - 1, j - i);
			now += y * (sum[j] - sum[tmp] - cnt[tmp] * (j - tmp));
		}
		if (z < i) now += x * (cnt[j - z - 1] - cnt[j - i]);
		int tmp = max(j - z - 1, j - i);
		now += y * (sum[j] - sum[tmp] - cnt[tmp] * (j - tmp));
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}