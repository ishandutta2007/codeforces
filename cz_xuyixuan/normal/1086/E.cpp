#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
const int P = 998244353;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct BinaryIndexTree {
	int n, a[MAXN];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	int query(int x) {
		int ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
	int query(int l, int r) {
		int ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
} BIT[3];
int n, a[MAXN][MAXN], dp[MAXN][MAXN], power[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	read(n), dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1ll * i * dp[i - 1][0] % P;
		for (int j = 1; j <= i; j++)
			dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - 1] + P) % P;
	}
	power[0] = 1;
	for (int i = 1; i <= n; i++)
		power[i] = 1ll * power[i - 1] * dp[n][n] % P;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		read(a[i][j]);
	int ans = 0;
	BIT[0].init(n);
	for (int i = n; i >= 1; i--) {
		BIT[0].modify(a[1][i], 1);
		update(ans, 1ll * BIT[0].query(a[1][i] - 1) * dp[n - i][0] % P * power[n - 1] % P);
	}
	for (int i = 2; i <= n; i++) {
		bool visa[MAXN], visb[MAXN];
		memset(visa, 0, sizeof(visa));
		memset(visb, 0, sizeof(visb));
		BIT[0].init(n), BIT[1].init(n);
		for (int j = n; j >= 1; j--) {
			visb[a[i][j]] = true;
			if (!visa[a[i][j]]) BIT[0].modify(a[i][j], 1);
			else BIT[1].modify(a[i][j], 1);
			int cnt = BIT[1].query(n);
			update(ans, 1ll * BIT[0].query(a[i][j] - 1) * dp[n - j][cnt] % P * power[n - i] % P);
			if (cnt) update(ans, 1ll * BIT[1].query(a[i][j] - 1) * dp[n - j][cnt - 1] % P * power[n - i] % P);
			if (a[i][j] > a[i - 1][j] && visb[a[i - 1][j]]) {
				if (visa[a[i - 1][j]]) update(ans, P - 1ll * dp[n - j][cnt - 1] * power[n - i] % P);
				else update(ans, P - 1ll * dp[n - j][cnt] * power[n - i] % P);
			}
			if (!visb[a[i - 1][j]]) visa[a[i - 1][j]] = true;
			else {
				visa[a[i - 1][j]] = true;
				BIT[0].modify(a[i - 1][j], -1);
				BIT[1].modify(a[i - 1][j], 1);
			}
		}
	}
	writeln(ans);
	return 0;
}