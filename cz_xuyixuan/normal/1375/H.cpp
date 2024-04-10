#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int MAXQ = 2e5 + 5;
const int Limit = 2.2e6;
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
struct info {
	int l[MAXN], r[MAXN];
	vector <vector <int>> home;
	void init(int x) {
		home.resize(x + 1);
		for (int i = 0; i <= x; i++)
			home[i].resize(x + 1);
	}
	int query(int ql, int qr) {
		if (l[ql] > r[qr]) return 0;
		else return home[l[ql]][r[qr]];
	}
} res[MAXN];
int n, q, size, a[MAXN], b[MAXN], k[MAXQ];
int tot, block, ql[MAXN], qr[MAXN], belong[MAXN];
vector <pair <int, int>> ans;
int merge(int x, int y) {
	if (x == 0 || y == 0) return x + y;
	ans.emplace_back(x, y);
	assert(++size <= Limit);
	return size;
}
info getres(int l, int r) {
	if (l == r) {
		info ans;
		for (int i = 1; i <= n; i++) {
			ans.l[i] = 1 + (i > b[l]);
			ans.r[i] = (i >= b[r]);
		}
		ans.init(1);
		ans.home[1][1] = b[l];
		return ans;
	}
	int mid = (l + r) / 2;
	info ans, ansl, ansr;
	ansl = getres(l, mid);
	ansr = getres(mid + 1, r);
	for (int i = 1, j = 1, k = 0; i <= n; i++) {
		k += (l <= a[i] && a[i] <= r);
		ans.l[i] = j, ans.r[i] = k;
		j += (l <= a[i] && a[i] <= r);
	}
	ans.init(r - l + 1);
	for (int i = 1; i <= n; i++)
		if (l <= a[i] && a[i] <= r) {
			for (int j = i; j <= n; j++)
				if (l <= a[j] && a[j] <= r) {
					ans.home[ans.l[i]][ans.r[j]] = merge(ansl.query(i, j), ansr.query(i, j));
				}
		}
	return ans;
}
int main() {
	read(n), read(q), size = n;
	for (int i = 1; i <= n; i++)
		read(a[i]), b[a[i]] = i;
	block = 1 << 8;
	for (int i = 1; i <= n; i++) {
		if (i % block == 1 % block) ql[++tot] = i;
		qr[tot] = i, belong[i] = tot;
	}
	for (int i = 1; i <= tot; i++)
		res[i] = getres(ql[i], qr[i]);
	for (int i = 1; i <= q; i++) {
		int ql, qr, cur = 0; read(ql), read(qr);
		for (int j = 1; j <= tot; j++)
			cur = merge(cur, res[j].query(ql, qr));
		k[i] = cur;
	}
	printf("%d\n", size);
	for (auto x : ans)
		printf("%d %d\n", x.first, x.second);
	for (int i = 1; i <= q; i++)
		printf("%d ", k[i]);
	printf("\n");
	return 0;
}