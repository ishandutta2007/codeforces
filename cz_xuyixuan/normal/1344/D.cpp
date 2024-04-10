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
int n, a[MAXN], b[MAXN]; ll k;
ll cnt(ll mid) {
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (mid >= a[i]) b[i] = 0;
		else {
			ll tmp = (a[i] - mid) / 3, res = sqrt(tmp);
			while (res * res > tmp) res--;
			while ((res + 1) * (res + 1) <= tmp) res++;
			if (res > a[i]) res = a[i];
			ans += (b[i] = res);
		}
	}
	return ans;
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	ll l = -4e18, r = 4e18;
	while (l < r) {
		ll mid = (l + r) / 2;
		if ((l + r) % 2 != 0) mid = (l + r - 1) / 2;
		if (cnt(mid) <= k) r = mid;
		else l = mid + 1;
	}
	k -= cnt(l);
	for (int i = 1; i <= n; i++) {
		if (l - 1 >= a[i]) b[i] = 0;
		else {
			ll tmp = (a[i] - (l - 1)) / 3, res = sqrt(tmp);
			while (res * res > tmp) res--;
			while ((res + 1) * (res + 1) <= tmp) res++;
			if (res > a[i]) res = a[i];
			ll inc = min(res - b[i], k);
			k -= inc, b[i] += inc;
		}
	}
	assert(k == 0);
	for (int i = 1; i <= n; i++)
		printf("%d ", b[i]);
	printf("\n");
	return 0;
}