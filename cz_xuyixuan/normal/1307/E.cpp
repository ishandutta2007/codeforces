#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int P = 1e9 + 7;
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
int n, m, s[MAXN]; pair <int, int> ans;
vector <pair <int, int>> a[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void update(pair <int, int> &x, pair <int, int> y) {
	if (y.first > x.first) x = y;
	else if (y.first == x.first) update(x.second, y.second);
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(s[i]);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		pair <int, int> res = make_pair(-1, -1);
		for (int j = 1, k = y; j <= n; j++)
			if (s[j] == x && --k == 0) {
				res.first = j;
				break;
			}
		for (int j = n, k = y; j >= 1; j--)
			if (s[j] == x && --k == 0) {
				res.second = j;
				break;
			}
		if (res.first != -1) a[x].push_back(res);
	}
	pair <int, int> ans = make_pair(0, 1);
	for (int i = 1; i <= n; i++)
		if (a[i].size()) {
			ans.first++;
			ans.second = 1ll * ans.second * a[i].size() % P;
		}
	for (int i = 1; i <= n; i++)
	for (auto x : a[i]) {
		int pos = x.first, cnt = 0;
		pair <int, int> cur = make_pair(1, 1);
		for (auto y : a[i])
			if (y.first != pos && y.second > pos) cnt++;
		if (cnt != 0) {
			cur.first++;
			cur.second = cnt;
		}
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int l = 0, r = 0, m = 0;
			for (auto y : a[j])
				if (y.first < pos && y.second > pos) m++;
				else if (y.first < pos) l++;
				else if (y.second > pos) r++;
			int ways = 0;
			ways += l * r;
			ways += l * m;
			ways += r * m;
			ways += m * (m - 1);
			if (ways) {
				cur.first += 2;
				cur.second = 1ll * cur.second * ways % P;
			} else if (l + r + m) {
				cur.first += 1;
				cur.second = 1ll * cur.second * (l + r + 2 * m) % P;
			}
		}
		update(ans, cur);
	}
	cout << ans.first << ' ' << ans.second << endl;
	return 0;
}