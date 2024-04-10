#include<bits/stdc++.h>
using namespace std;
const int MAXN = 25;
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
int a[MAXN];
int main() {
	int n, m = 20; read(n);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		for (int j = 1; j <= 20; j++) {
			a[j] += x & 1;
			x >>= 1;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll cur = 0;
		for (int j = 20; j >= 1; j--) {
			cur <<= 1;
			if (a[j]) {
				a[j]--;
				cur += 1;
			}
		}
		ans += cur * cur;
	}
	cout << ans << endl;
	return 0;
}