#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int INF  = 5e8;
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
pair <int, int> a[MAXN];
unordered_map <ll, bool> mp;
int n, dp[MAXN][2], c[MAXN][2][MAXN][2];
bool solve(int l, int r) {
	if (l >= r) return true;
	ll tmp = 1ll * INF * l + r;
	if (mp.count(tmp)) return mp[tmp];
	bool &ans = mp[tmp];
	ans = false; int Max = l;
	for (int i = 1; i <= n && !ans; i++)
		if (a[i].first > l && a[i].first < r) {
			if (a[i].first - a[i].second <= l) {
				int tmp = max(Max, a[i].first);
				for (int j = i + 1; j <= n && a[j].first <= tmp; j++)
					chkmax(tmp, a[j].first + a[j].second);
				ans |= solve(tmp, r);
			}
			chkmax(Max, a[i].first + a[i].second);
		}
	return ans;
}
int coef(int l, int tl, int r, int tr) {
	if (c[l][tl][r][tr] != -INF - 1) return c[l][tl][r][tr];
	int &ans = c[l][tl][r][tr]; ans = -INF;
	int bl = a[l].first - (tl == 0) * a[l].second, cl = a[l].first + (tl == 1) * a[l].second;
	int br = a[r].first - (tr == 0) * a[r].second, cr = a[r].first + (tr == 1) * a[r].second;
	if (bl > br || cl > cr || (l == r && tl != tr)) return ans;
	for (int i = 1; i <= n; i++)
		if (a[i].first >= bl && a[i].first <= cl && i != l) chkmax(cl, a[i].first + a[i].second);
	for (int i = n; i >= 1; i--)
		if (a[i].first <= cr && a[i].first >= br && i != r) chkmin(br, a[i].first - a[i].second);
	if (solve(cl, br)) return ans = cr - bl;
	return ans;
}
int main() {
	read(n);
	a[0] = make_pair(-INF, 0);
	for (int i = 1; i <= n; i++)
		read(a[i].first), read(a[i].second);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		c[i][0][j][0] = c[i][0][j][1] = c[i][1][j][0] = c[i][1][j][1] = -INF - 1;
	for (int i = 0; i <= n; i++) {
		int tmp = dp[i][0];
		for (int j = i + 1; j <= n; j++)
		for (int k = i + 1; k <= n; k++) {
			if (a[j].first > a[i].first) chkmax(dp[k][0], tmp + coef(j, 1, k, 0));
			if (a[j].first > a[i].first) chkmax(dp[k][1], tmp + coef(j, 1, k, 1));
			if (a[j].first - a[j].second > a[i].first) chkmax(dp[k][0], tmp + coef(j, 0, k, 0));
			if (a[j].first - a[j].second > a[i].first) chkmax(dp[k][1], tmp + coef(j, 0, k, 1));
		}
		tmp = dp[i][1];
		for (int j = i + 1; j <= n; j++)
		for (int k = i + 1; k <= n; k++) {
			if (a[j].first > a[i].first + a[i].second) chkmax(dp[k][0], tmp + coef(j, 1, k, 0));
			if (a[j].first > a[i].first + a[i].second) chkmax(dp[k][1], tmp + coef(j, 1, k, 1));
			if (a[j].first - a[j].second > a[i].first + a[i].second) chkmax(dp[k][0], tmp + coef(j, 0, k, 0));
			if (a[j].first - a[j].second > a[i].first + a[i].second) chkmax(dp[k][1], tmp + coef(j, 0, k, 1));
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		chkmax(ans, dp[i][0]);
		chkmax(ans, dp[i][1]);
	}
	cout << ans << endl;
	return 0;
}