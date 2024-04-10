#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2025;
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
int ans, n, k;
vector <int> a;
bool ok(vector <int> a) {
	sort(a.begin(), a.end());
	if (k == 3) {
		int sum = 0;
		for (auto x : a) sum += x;
		if (sum > n) return false;
		vector <int> b; int tmp = 0;
		reverse(a.begin(), a.end());
		for (auto x : a) {
			tmp++;
			while (x--) b.push_back(tmp);
		}
		a = b; tmp = sum = 0;
		reverse(a.begin(), a.end());
		for (auto x : a) {
			tmp++;
			sum += tmp * x;
		}
		return sum <= n;
	}
	for (int i = 1; i <= k; i++) {
		int sum = 0;
		for (auto x : a) sum += x;
		if (sum > n) return false;
		vector <int> b; int tmp = 0;
		reverse(a.begin(), a.end());
		for (auto x : a) {
			tmp++;
			while (x--) b.push_back(tmp);
		}
		a = b;
	}
	return true;
}
void work(int pos, int now) {
	a.push_back(now);
	if (ok(a)) {
		ans++;
		work(pos + 1, now);
	}
	a.pop_back();
	if (now != 1) work(pos, now - 1);
}
int dp[MAXN][MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	read(n), read(k);
	if (k == 1) {
		for (int i = 1; i <= n; i++)
			dp[i][n - i] = 1;
		for (int i = n; i >= 1; i--)
		for (int j = 0; j <= n; j++) {
			int tmp = dp[i][j];
			if (tmp != 0) {
				for (int k = 0; i * k <= j; k++)
					update(dp[i - 1][j - i * k], tmp);
			}
		}
		int ans = 0;
		for (int i = 0; i <= n; i++)
			update(ans, dp[0][i]);
		cout << ans << endl;
	} else if (k == 2) {
		for (int i = 1; i * (i + 1) / 2 <= n; i++)
			dp[i][n - i * (i + 1) / 2] = 1;
		for (int i = n; i >= 1; i--)
		for (int j = 0; j <= n; j++) {
			int tmp = dp[i][j];
			if (tmp != 0) {
				for (int k = 0; i * (i + 1) / 2 * k <= j; k++)
					update(dp[i - 1][j - i * (i + 1) / 2 * k], tmp);
			}
		}
		int ans = 0;
		for (int i = 0; i <= n; i++)
			update(ans, dp[0][i]);
		cout << ans << endl;
	} else {
		work(1, n);
		cout << ans << endl;
	}
	return 0;
}