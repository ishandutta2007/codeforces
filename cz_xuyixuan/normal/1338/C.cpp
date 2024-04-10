#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 30;
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
int m; ll bit[MAXM];
ll getinc(ll n) {
	ll ans = 0, bit = 1;
	while (n != 0) {
		int tmp = n & 3;
		if (tmp == 1) ans += bit * 2;
		if (tmp == 2) ans += bit * 3;
		if (tmp == 3) ans += bit;
		n >>= 2, bit <<= 2;
	}
	return ans;
}
int main() {
	int m = 28;
	for (int i = 0; i <= m; i++)
		bit[i] = 1ll << (2 * i);
	int T; read(T);
	while (T--) {
		ll n; read(n);
		int type = n % 3;
		n = (n + 2) / 3;
		ll x = 0, y = 0, z = 0;
		for (int i = 0; i <= m; i++)
			if (bit[i] >= n) {
				ll inc = getinc(n - 1);
				x = bit[i] + (n - 1);
				y = bit[i] * 2 + inc; z = x ^ y;
				break;
			} else n -= bit[i];
		if (type == 1) printf("%lld\n", x);
		if (type == 2) printf("%lld\n", y);
		if (type == 0) printf("%lld\n", z);
	}
	return 0;
}