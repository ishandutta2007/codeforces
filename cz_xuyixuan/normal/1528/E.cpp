#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int P = 998244353;
const int inv2 = (P + 1) / 2;
const int inv6 = (P + 1) / 6;
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
int dp[MAXN], sum[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int work(int x) {
	int ans1 = x;
	int ans2 = (1ll * x * x + x) % P * inv2 % P;
	return (0ll + ans1 + ans2) % P;
}
int fork(int x) {
	int ans1 = x;
	int ans2 = (1ll * x * x + x) % P * inv2 % P;
	int ans3 = (1ll * x * x % P * x % P + 3ll * x % P * x % P + 2ll * x) % P * inv6 % P;
	return (0ll + ans1 + ans2 + ans3) % P;
}
int main() {
	int n; read(n);
	dp[0] = sum[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = work(sum[i - 1]);
		if (i >= 2) update(dp[i], P - work(sum[i - 2]));
		sum[i] = (sum[i - 1] + dp[i]) % P;
	}
	int ans = fork(sum[n - 1]);
	if (n >= 2) update(ans, P - fork(sum[n - 2]));
	ans = (2ll * ans - 1) % P;
	for (int i = 1; i <= n - 1; i++) {
		int tmp = (dp[n - i - 1] - 1 + P) % P;
		int x = sum[i - 1], tnp = (1ll * x * x + x) % P * inv2 % P;
		if (i >= 2) {
			x = sum[i - 2];
			update(tnp, P - (1ll * x * x + x) % P * inv2 % P);
		}
		update(ans, 1ll * tmp * tnp % P);
	}
	cout << ans << endl;
	return 0;
}