#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
	int n; ll a[MAXN];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	ll query(int x) {
		ll ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
	ll query(int l, int r) {
		ll ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
} BIT[3];
int n, a[MAXN], home[MAXN];
set <int> p, q;
ll queryone(int l, int r, int cnt) {
	cnt = r - l + 1 - cnt;
	ll ans = BIT[1].query(l, r);
	ans -= 1ll * cnt * (cnt - 1) / 2 + 1ll * cnt * l;
	return ans;
}
ll querytwo(int l, int r, int cnt) {
	cnt = r - l + 1 - cnt;
	ll ans = BIT[2].query(l, r);
	ans -= 1ll * cnt * (cnt - 1) / 2 + 1ll * cnt * (n - r + 1);
	return ans;
}
int main() {
	read(n);
	BIT[0].init(n);
	BIT[1].init(n);
	BIT[2].init(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]), home[a[i]] = i;
		BIT[1].modify(i, i);
		BIT[2].modify(i, n - i + 1);
	}
	ll inv = 0;
	for (int i = 1; i <= n; i++) {
		inv += BIT[0].query(home[i], n);
		BIT[0].modify(home[i], 1);
		BIT[1].modify(home[i], -home[i]);
		BIT[2].modify(home[i], -n + home[i] - 1);
		if (i == 1 || (*q.begin()) <= home[i]) q.insert(home[i]);
		else p.insert(home[i]);
		if (p.size() > q.size()) {
			auto x = p.end(); x--;
			q.insert(*x), p.erase(x);
		}
		if (q.size() > p.size() + 1) {
			auto x = q.begin();
			p.insert(*x), q.erase(x);
		}
		ll ans = inv;
		if (i != 1) {
			int l = (*p.begin());
			auto x = q.end(); x--;
			int r = *x, mid = (*q.begin());
			ans += queryone(l, mid - 1, p.size());
			ans += querytwo(mid, r, q.size());
		}
		write(ans), putchar(' ');
	}
	return 0;
}