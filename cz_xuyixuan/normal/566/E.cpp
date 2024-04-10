#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
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
int n, cnt[MAXN];
vector <int> adj[MAXN];
bitset <MAXN> a[MAXN], d[MAXN];
bool visa[MAXN], mark[MAXN];
void solve(int lft) {
	bitset <MAXN> lst; lst.set();
	for (int i = 1; i <= n; i++)
		if (!visa[i]) {
			bool flg = false;
			for (auto x : adj[i])
				if ((a[x] & a[i]) == a[i]) {
					flg = true;
					break;
				}
			if (flg && a[i].count() < lst.count()) lst = a[i];
		}
	int Min = n + 1, pos = 0;
	for (int i = 1; i <= n; i++)
		if (!mark[i] && lst[i] && cnt[i] < Min) {
			Min = cnt[i];
			pos = i;
		}
	if (Min == lft) {
		for (int i = 1; i <= n; i++)
			if (!mark[i] && i != pos) printf("%d %d\n", i, pos);
		return;
	}
	bitset <MAXN> tmp; tmp.set();
	for (int i = 1; i <= n; i++)
		if (!visa[i] && a[i][pos]) tmp &= a[i];
	tmp.reset(pos);
	bitset <MAXN> tnp = tmp;
	for (int i = 1; i <= n; i++)
		if (!visa[i] && (tnp & a[i]).count() >= 2) tmp &= a[i];
	assert(tmp.count() == 1 || tmp.count() == 2);
	int res = tmp._Find_first();
	if (tmp.count() == 2) {
		int x = res, y = tmp._Find_next(x); bool flg = false;
		for (int i = 1; i <= n; i++)
			if (!visa[i] && !a[i][pos]) {
				if (a[i][y] ^ a[i][x]) {
					flg = true;
					if (a[i][y]) res = x;
					else res = y;
				}
			}
		if (!flg) {
			printf("%d %d\n", x, y);
			mark[x] = mark[y] = true;
			int val = 0;
			for (int i = 1; i <= n; i++)
				if (!mark[i]) val = i;
			vector <int> s, t;
			for (int i = 1; i <= n; i++)
				if (!visa[i] && a[i].count() < lft && a[i][val]) {
					for (int j = a[i]._Find_first(); j <= n; j = a[i]._Find_next(j)) {
						if (!mark[j]) {
							mark[j] = true;
							s.push_back(j);
						}
					}
					break;
				}
			for (int i = 1; i <= n; i++)
				if (!mark[i]) t.push_back(i);
			for (auto v : s) if (d[v][x]) swap(x, y);
			for (auto v : t) if (d[v][y]) swap(x, y);
			for (auto v : s) printf("%d %d\n", x, v);
			for (auto v : t) printf("%d %d\n", y, v);
			return;
		}
	}
	printf("%d %d\n", pos, res);
	int home = 0;
	mark[pos] = true, cnt[pos] = 0;
	for (int i = 1; i <= n; i++)
		if (!visa[i] && a[i][pos]) {
			a[i].reset(pos);
			if (home == 0 || a[i].count() <= a[home].count()) home = i;
		}
	visa[home] = true;
	for (int i = 1; i <= n; i++)
		if (a[home][i]) cnt[i]--;
	d[res] |= ~a[home];
	solve(lft - 1);
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		while (x--) {
			int y; read(y), cnt[y]++;
			a[i].set(y);
		}
	}
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++) {
		if ((a[i] & a[j]).count() >= 4) {
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		if ((a[i] & a[j]) == a[i]) adj[i].push_back(i);
		if ((a[i] & a[j]) == a[j]) adj[j].push_back(j);
	}
	solve(n);
	return 0;
}