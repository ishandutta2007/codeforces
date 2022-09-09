#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int ans, dp[MAXN][2], sum[MAXN][2];
vector <int> a[MAXN];
void update(int pos) {
	dp[pos][0] = sum[pos][1] + 1;
	dp[pos][1] = sum[pos][0];
}
void getdp(int pos, int fa) {
	for (auto x : a[pos])
		if (x != fa) {
			getdp(x, pos);
			sum[pos][0] += dp[x][0];
			sum[pos][1] += dp[x][1];
		}
	update(pos);
}
void getans(int pos, int fa) {
	chkmin(ans, dp[pos][0] - 1);
	for (auto x : a[pos])
		if (x != fa) {
			sum[pos][0] -= dp[x][0];
			sum[pos][1] -= dp[x][1];
			update(pos);
			sum[x][0] += dp[pos][0];
			sum[x][1] += dp[pos][1];
			update(x);
			getans(x, pos);
			sum[x][0] -= dp[pos][0];
			sum[x][1] -= dp[pos][1];
			update(x);
			sum[pos][0] += dp[x][0];
			sum[pos][1] += dp[x][1];
			update(pos);
		}
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	ans = n + 1;
	getdp(1, 0);
	getans(1, 0);
	cout << ans << endl;
	return 0;
}