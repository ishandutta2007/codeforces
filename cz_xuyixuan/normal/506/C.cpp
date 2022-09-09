#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, m, k, p;
ll a[MAXN], h[MAXN], req[MAXN], cnt[MAXN];
bool check(ll x) {
	ll tot = 0;
	for (int i = 1; i <= n; i++) {
		ll final = a[i] * m + h[i];
		if (final <= x) req[i] = cnt[i] = 0;
		else {
			req[i] = final - x;
			cnt[i] = req[i] / p + (req[i] % p != 0);
		}
		tot += cnt[i];
	}
	if (tot > m * k) return false;
	static int suf[MAXN];
	memset(suf, 0, sizeof(suf));
	for (int i = 1; i <= n; i++) {
		ll tmp = req[i];
		while (tmp > 0) {
			if (tmp <= h[i]) suf[1]++;
			else {
				ll tnp = 1 + (tmp - h[i]) / a[i] + ((tmp - h[i]) % a[i] != 0);
				if (tnp > m) return false;
				suf[tnp]++;
			}
			tmp -= p;
		}
	}
	for (int i = m; i >= 1; i--) {
		suf[i] += suf[i + 1];
		if (suf[i] > (m - i + 1) * k) return false;
	}
	return true;
}
int main() {
	read(n), read(m), read(k), read(p);
	for (int i = 1; i <= n; i++)
		read(h[i]), read(a[i]);
	ll l = 0, r = 1e15;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
	return 0;
}