#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
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
ll n, s, a[MAXN]; int m;
bool query(ll x) {
	cout << '?' << ' ' << x << endl;
	bool res; read(res);
	return res;
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), m = 0;
		for (ll t = n - 1; t != 0; t -= a[m])
			a[++m] = (t + 1) / 2;
		ll t = n - 1; s = 1;
		for (int i = 1; i <= m; i += 2)
			s += a[i];
		query(s); ll l = 0, r = n - 1;
		for (int i = 1; l != r; i++) {
			ll len = l + (r - l + 1) / 2; bool res;
			if (i & 1) res = query(s -= len);
			else res = query(s += len);
			if (!res) l = len;
			else r = len - 1;
		}
		cout << '=' << ' ' << l + 1 << endl;
	}
	return 0;
}