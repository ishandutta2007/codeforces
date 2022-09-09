#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const long long INF = 1e18;
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
int n, ans, tot, x[MAXN], y[MAXN];
int l, r, q[MAXN * 2], d[MAXN]; bool vis[MAXN];
vector <int> a[MAXN], rem; pair <int, int> v[MAXN];
void work(int pos) {
	vis[pos] = true;
	v[++tot] = make_pair(x[pos], y[pos]);
	if (pos == rem[1]) return;
	for (auto x : a[pos])
		if (!vis[x]) work(x);
}
ll calc(int pos) {
	static pair <int, int> home[MAXN]; int cnt = 0;
	for (int i = 1; i <= tot; i++)
		if (i != pos) {
			home[v[i].first].first = ++cnt;
			home[v[i].second].second = cnt;
		}
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++)
		if (home[i].first) {
			int tx = abs(home[i].first - home[i].second), ty = cnt - tx;
			if (x + y == 0) x = tx, y = ty;
			else if (x != tx && y != tx) return INF;
		}
	return 1ll * min(x, y) * tot;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(x[i]);
	for (int i = 1; i <= n; i++)
		read(y[i]);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	l = 1, r = 0;
	for (int i = 1; i <= n; i++) {
		d[i] = a[i].size();
		if (d[i] == 1) q[++r] = i;
	}
	while (l <= r) {
		int pos = q[l++];
		if (x[pos] == y[pos] && x[pos] != 0) {
			vis[pos] = true;
			for (auto v : a[pos])
				if (!vis[v] && --d[v] == 1) q[++r] = v;
		} else {
			int fa = 0;
			for (auto v : a[pos])
				if (!vis[v]) fa = v;
			if (fa == 0) {
				assert(l > r);
				printf("%d %d\n", 0, ans);
				return 0;
			} else if (x[pos] == 0 && y[pos] == x[fa]) {
				swap(x[pos], x[fa]), ans++;
				vis[pos] = true; if (--d[fa] == 1) q[++r] = fa;
			} else if (y[pos] == 0 && x[pos] == y[fa]) {
				swap(y[pos], y[fa]), ans++;
				vis[pos] = true; if (--d[fa] == 1) q[++r] = fa;
			} else if (x[pos] == y[pos] && x[pos] == 0 && x[fa] == y[fa]) {
				if (rem.size() >= 2 || l > r) {
					swap(x[pos], x[fa]), ans++;
					swap(y[pos], y[fa]), ans++;
					vis[pos] = true; if (--d[fa] == 1) q[++r] = fa;
				} else q[++r] = pos;
			} else rem.push_back(pos);
		}
	}
	if (rem.size() >= 3) {
		puts("-1");
		return 0;
	}
	assert(rem.size() == 2);
	if (rem[0] > rem[1]) swap(rem[0], rem[1]);
	ll res = INF; work(rem[0]);
	int x = 0, y = 0;
	for (int i = 1; i <= tot; i++) {
		if (v[i].first == 0) x = i;
		if (v[i].second == 0) y = i;
	}
	if (x > y) {
		swap(x, y);
		for (int i = 1; i <= tot; i++)
			swap(v[i].first, v[i].second);
	}
	for (int i = x + 1; i <= y; i++)
		swap(v[i].first, v[i - 1].first);
	chkmin(res, y - x + calc(y));
	for (int i = y; i >= x + 1; i--)
		swap(v[i].first, v[i - 1].first);
	
	for (int i = x; i >= 2; i--)
		swap(v[i].first, v[i - 1].first);
	swap(v[1].first, v[tot].first);
	for (int i = tot; i >= y + 1; i--)
		swap(v[i].first, v[i - 1].first);
	chkmin(res, tot - (y - x) + calc(y));
	if (res < INF) printf("%d %d %lld\n", rem[0], rem[1], res + ans);
	else puts("-1");
	return 0;
}