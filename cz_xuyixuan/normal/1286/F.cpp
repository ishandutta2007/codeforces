#include<bits/stdc++.h>
using namespace std;
const int MAXN = 25;
const int MAXS = 1 << 20;
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
int n, u, dp[MAXS]; ll a[MAXN];
int bit[MAXN], cnt[MAXS]; ll sum[MAXS];
bool check(int s) {
	if (cnt[s] == 1) return sum[s] == 0;
	if ((sum[s] + cnt[s]) % 2 == 0) return false;
	int tmp = s;
	for (int i = 1; i <= n; i++)
		if (bit[i] & s) tmp = s ^ bit[i];
	for (int t = tmp; t != 0; t = (t - 1) & s) {
		ll tmp = sum[t] * 2 - sum[s];
		if (tmp >= -cnt[s] + 1 && tmp <= cnt[s] - 1) return true;
	}
	return false;
}
int main() {
	read(n), u = (1 << n) - 1;
	for (int i = 1; i <= n; i++)
		read(a[i]), bit[i] = 1 << (i - 1);
	for (int s = 0; s <= u; s++) {
		for (int i = 1; i <= n; i++)
			if (bit[i] & s) {
				cnt[s]++;
				sum[s] += a[i];
			}
	}
	for (int s = 1; s <= u; s++)
		if (dp[s] == 0 && check(s)) {
			dp[s] = 1; int x = u ^ s;
			for (int t = x; t != 0; t = (t - 1) & x)
				chkmax(dp[s ^ t], dp[t] + dp[s]);
		}
	cout << n - dp[u] << endl;
	return 0;
}