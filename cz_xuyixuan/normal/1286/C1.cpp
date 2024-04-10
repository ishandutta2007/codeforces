#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
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
int n; char ans[MAXN];
char mp[MAXN][MAXN][2];
bool ok() {
	for (int i = 1; i <= n; i++)
		if (ans[i] == 0) return false;
	return true;
}
vector <string> a[MAXN];
void work(int l, int r) {
	int len = r - l + 1, cnt = len * (len + 1) / 2;
	if (len <= 0) return;
	cout << '?' << ' ' << l << ' ' << r << endl;
	for (int i = 1; i <= len; i++)
		a[i].clear();
	for (int i = 1; i <= cnt; i++) {
		string s; cin >> s;
		a[s.size()].push_back(s);
	}
	int now[256]; memset(now, 0, sizeof(now));
	for (auto x : a[len].back()) now[x]++;
	for (int i = l, j = r, k = 2; i <= j; i++, j--, k++) {
		char x = 0, y = 0;
		int tmp[256]; memcpy(tmp, now, sizeof(now));
		for (int c = 'a'; c <= 'z'; c++)
			tmp[c] *= k;
		for (int ti = l, tj = r, t = 1; ti < i; ti++, tj--, t++) {
			tmp[mp[ti][tj][0]] -= k - t;
			tmp[mp[ti][tj][1]] -= k - t;
		}
		for (auto s : a[len - k + 1])
		for (auto x : s) tmp[x]--;
		for (int c = 'a'; c <= 'z'; c++) {
			while (tmp[c]--) {
				if (x == 0) x = c;
				else {
					assert(y == 0);
					y = c;
				}
			}
		}
		mp[i][j][0] = mp[j][i][0] = x;
		mp[i][j][1] = mp[j][i][1] = y;
	}
}
int main() {
	read(n);
	work(1, n - (n + 1) % 2);
	work(1, n / 2), work(n / 2 + 1, n);
	while (!ok()) {
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (mp[i][j][0] != 0 && mp[i][j][0] == mp[i][j][1]) {
				ans[i] = ans[j] = mp[i][j][0];
			} else if (ans[i] == 0 && ans[j] != 0 && mp[i][j][0] != 0) {
				if (ans[j] == mp[i][j][0]) ans[i] = mp[i][j][1];
				else ans[i] = mp[i][j][0];
			}
		}
	}
	printf("! %s", ans + 1); cout << endl;
	return 0;
}