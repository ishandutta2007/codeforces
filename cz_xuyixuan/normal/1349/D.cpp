#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int P = 998244353;
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
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int n, s, a[MAXN], inv[MAXN];
void init(int n) {
	for (int i = 1; i <= n; i++)
		inv[i] = power(i, P - 2);
}
int k[MAXN], b[MAXN], dp[MAXN];
int main() {
	read(n), s = 0;
	for (int i = 1; i <= n; i++)
		read(a[i]), s += a[i];
	init(max(s, n));
	k[0] = 1, b[0] = n - 1;
	for (int i = 1; i <= s - 1; i++) {
		int p = 1ll * i * inv[s] % P;
		int q = 1ll * (s - i) * inv[s] % P * inv[n - 1] % P;
		int r = (1 - 1ll * (s - i) * inv[s] % P * (n - 2) % P * inv[n - 1] % P + P) % P;
		int c = (1 + 1ll * p * b[i - 1]) % P;
		update(r, P - 1ll * p * k[i - 1] % P);
		r = power(r, P - 2);
		k[i] = 1ll * q * r % P;
		b[i] = 1ll * c * r % P;
	}
	for (int i = s - 1; i >= 0; i--)
		dp[i] = (1ll * dp[i + 1] * k[i] + b[i]) % P;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		update(ans, dp[a[i]]);
		if (i != 1) update(ans, P - dp[0]);
	}
	cout << 1ll * ans * inv[n] % P << endl;
	return 0;
}