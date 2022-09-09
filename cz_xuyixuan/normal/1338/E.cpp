#include<bits/stdc++.h>
using namespace std;
const int MAXN = 8005;
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
int n, m, d[MAXN]; ll ans;
bitset <MAXN> p, q, vis, in[MAXN], out[MAXN];
int calc(vector <int> a) {
	int ans = 3 * a.size() * (a.size() - 1) / 2;
	static int cnt[MAXN]; memset(cnt, 0, sizeof(cnt));
	for (auto x : a) ans += cnt[x]++;
	return ans;
}
int main() {
	read(n), m = n;
	for (int i = 1; i <= n; i++) {
		static char s[MAXN];
		scanf("\n%s", s + 1);
		for (int j = 1; j <= n / 4; j++) {
			int ch = s[j] - '0';
			if ('A' <= s[j] && s[j] <= 'F') ch = s[j] - 'A' + 10;
			for (int k = 0; k <= 3; k++, ch >>= 1)
				out[i][j * 4 - k] = ch & 1;
		}
	}
	for (int i = 1; i <= n; i++)
		d[i] = out[i].count();
	for (int i = 1; i <= n; i++) {
		bool found = false;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && (d[j] == 0 || d[j] == m - 1)) {
				found = vis[j] = true;
				ans += (1ll + 614 * n) * (--m);
				for (int k = 1; k <= n; k++)
					if (!vis[k]) {
						d[k] -= out[k][j];
						out[k][j] = false;
					}
			}
		if (!found) break;
	}
	if (m == 0) {
		cout << ans << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		if (out[i][j]) in[j][i] = true;
	int Max = 0, pos = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i] && in[i].count() > Max) {
			Max = in[i].count();
			pos = i;
		}
	for (int i = 1; i <= n; i++)
		if (!vis[i] && (in[pos][i] || i == pos)) p.set(i);
	for (int i = 1; i <= n; i++)
		if (!vis[i] && !p[i]) q.set(i);
	ans += 3 * p.count() * q.count();
	vector <int> tmp;
	for (int i = 1; i <= n; i++)
		if (p[i]) tmp.push_back((in[i] & q).count());
	ans += calc(tmp); tmp.clear();
	for (int i = 1; i <= n; i++)
		if (q[i]) tmp.push_back((in[i] & p).count());
	ans += calc(tmp);
	cout << ans << endl;
	return 0;
}