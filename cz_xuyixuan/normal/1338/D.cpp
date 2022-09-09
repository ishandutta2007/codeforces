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
vector <int> a[MAXN];
int n, ans, d[MAXN], dp[MAXN][2];
void work(int pos, int fa) {
	dp[pos][1] = d[pos];
	for (auto x : a[pos])
		if (x != fa) {
			work(x, pos);
			chkmax(ans, dp[pos][1] + dp[x][0] - 1);
			chkmax(ans, dp[pos][0] + dp[x][1] - 1);
			chkmax(ans, dp[pos][1] + dp[x][1] - 2);
			chkmax(dp[pos][0], dp[x][1]);
			chkmax(dp[pos][1], dp[x][0] + d[pos] - 1);
			chkmax(dp[pos][1], dp[x][1] + d[pos] - 2);
		}
	chkmax(ans, dp[pos][1]);
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		d[i] = a[i].size();
	work(1, 0);
	cout << ans << endl;
	return 0;
}