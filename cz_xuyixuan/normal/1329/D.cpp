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
struct BinaryIndexTree {
	int n, a[MAXN];
	void init(int x) {
		n = x;
		for (int i = 1; i <= n; i++)
			a[i] = 0;
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
} BIT;
char s[MAXN], t[MAXN];
int cnt[26], ans, f[MAXN], x[MAXN], y[MAXN];
int n, m, pos[MAXN], pre[MAXN], suf[MAXN];
set <pair <int, int>> st[26]; set <int> vis;
void ins(int x, int y) {
	if (x != 0 && y != m + 1 && t[x] != t[y]) {
		st[t[x] - 'a'].insert(make_pair(x, y));
		st[t[y] - 'a'].insert(make_pair(x, y));
	}
}
void del(int x, int y) {
	if (x != 0 && y != m + 1 && t[x] != t[y]) {
		st[t[x] - 'a'].erase(make_pair(x, y));
		st[t[y] - 'a'].erase(make_pair(x, y));
	}
}
void del(int x) {
	vis.erase(x); cnt[t[x] - 'a']--;
	int p = pre[x], q = suf[x];
	del(p, x), del(x, q), ins(p, q);
	suf[p] = q, pre[q] = p;
}
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int main() {
	int T; read(T);
	while (T--) {
		scanf("\n%s", s + 1);
		n = strlen(s + 1), m = 0;
		vis.clear();
		for (int i = 0; i <= 25; i++) {
			cnt[i] = 0;
			st[i].clear();
		}
		for (int i = 1; i <= n - 1; i++)
			if (s[i] == s[i + 1]) {
				pos[++m] = i, t[m] = s[i];
				cnt[s[i] - 'a']++;
				vis.insert(m);
			}
		if (m == 0) {
			puts("1");
			printf("%d %d\n", 1, n);
			continue;
		}
		for (int i = 0; i <= m; i++) {
			suf[i] = i + 1;
			pre[i + 1] = i;
		}
		for (int i = 1; i <= m - 1; i++)
			if (t[i] != t[i + 1]) {
				st[t[i] - 'a'].insert(make_pair(i, i + 1));
				st[t[i + 1] - 'a'].insert(make_pair(i, i + 1));
			}
		ans = 1;
		while (true) {
			int lft = vis.size(), Max = 0, c = 0;
			for (int i = 0; i <= 25; i++)
				if (cnt[i] > Max) {
					Max = cnt[i];
					c = i;
				}
			if (Max == lft) break;
			int a = (*st[c].begin()).first;
			int b = (*st[c].begin()).second;
			x[ans] = pos[a] + 1, del(a);
			y[ans++] = pos[b], del(b);
		}
		for (auto p : vis) {
			x[ans] = 1;
			y[ans++] = pos[p];
		}
		x[ans] = 1, y[ans] = n;
		printf("%d\n", ans);
		BIT.init(n);
		for (int i = 1; i <= n; i++) {
			BIT.modify(i, 1);
			f[i] = i;
		}
		for (int i = 1; i <= ans; i++) {
			printf("%d %d\n", BIT.query(x[i] - 1) + 1, BIT.query(y[i]));
			for (int pos = find(y[i]); pos >= x[i]; pos = find(pos)) {
				BIT.modify(pos, -1);
				f[pos] = pos - 1;
			}
		}
	}
	return 0;
}