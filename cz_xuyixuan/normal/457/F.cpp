#include<bits/stdc++.h>
using namespace std;
const int MAXN = 255;
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
int n, mid, size[MAXN], val[MAXN], l[MAXN], r[MAXN];
bool dp[MAXN][2][3], vis[MAXN][2][3];
bool merge(bool x, bool y, bool who) {
	if (x == who || y == who) return who;
	else return !who;
}
// who: 0 -> Min, 1 -> Max
// skip: 0 -> none, 1 -> can, 2 -> must
bool getdp(int pos, bool who, int skip) {
	if (val[pos] != -1) {
		return val[pos] > mid;
	} else if (size[pos] == 1) {
		return merge(getdp(l[pos], 0, 0), getdp(r[pos], 0, 0), who ^ (skip == 2));
	} else if (vis[pos][who][skip]) {
		return dp[pos][who][skip];
	} else {
		bool &ans = dp[pos][who][skip];
		vis[pos][who][skip] = true;
		if (skip) {
			ans = getdp(pos, !who, 0);
			if (size[pos] & 1) {
				if (size[l[pos]] & 1) {
					ans = merge(ans, merge(getdp(l[pos], who, 0), getdp(r[pos], !who, 1 + (size[l[pos]] == 1 && skip == 1)), !who), who);
					ans = merge(ans, merge(getdp(r[pos], who, 0), getdp(l[pos], !who, 1 + (size[r[pos]] == 1 && skip == 1)), !who), who);
				} else {
					if (size[l[pos]]) {
						ans = merge(ans, merge(getdp(l[pos], who, 1 + (skip == 1 && size[r[pos]] == 0)), getdp(r[pos], !who, 0), !who), who);
					}
					if (size[r[pos]]) {
						ans = merge(ans, merge(getdp(r[pos], who, 1 + (skip == 1 && size[l[pos]] == 0)), getdp(l[pos], !who, 0), !who), who);
					}
				}
			} else {
				ans = merge(ans, merge(getdp(l[pos], who, 1 + (skip == 1 && size[r[pos]] == 0)), getdp(r[pos], who, 0), who), who);
			}
		} else {
			if (size[pos] & 1) {
				if (size[l[pos]] & 1) {
					ans = merge(getdp(l[pos], who, 1), getdp(r[pos], who, 1), who);
				} else {
					ans = merge(getdp(l[pos], who, 0), getdp(r[pos], who, 0), who);
				}
			} else {
				ans = merge(merge(getdp(l[pos], who, 0), getdp(r[pos], !who, 0), !who), 
				            merge(getdp(r[pos], who, 1), getdp(l[pos], !who, 1), !who), who);
			}
		}
		return ans;
	}
}
void dfs(int pos) {
	size[pos] = 0;
	if (val[pos] != -1) return;
	dfs(l[pos]), dfs(r[pos]);
	size[pos] = 1 + size[l[pos]] + size[r[pos]];
	if (size[r[pos]] & 1) swap(l[pos], r[pos]);
}
void init(int n) {
	for (int i = 0; i <= n - 1; i++) {
		read(val[i]);
		if (val[i] == -1) {
			read(l[i]);
			read(r[i]);
		} else l[i] = r[i] = -1;
	}
	dfs(0);
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), init(n);
		int l = 0, r = 1e3;
		while (l < r) {
			mid = (l + r) / 2;
			memset(vis, false, sizeof(vis));
			if (getdp(0, 1, 0)) l = mid + 1;
			else r = mid;
		}
		writeln(l);
	}
	return 0;
}