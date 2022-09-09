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
vector <int> a[MAXN];
void exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	}
	int q = a / b, r = a % b;
	exgcd(b, r, y, x);
	y -= q * x;
}
ll calc(int n, int m, vector <int> a) {
	int x = 0, inv = 0;
	exgcd(n, m, x, inv);
	inv = (inv % n + n) % n;
	static pair <int, int> s[MAXN]; int tot = 0;
	for (auto &x : a) s[++tot] = make_pair(1ll * x * inv % n, x);
	sort(s + 1, s + tot + 1);
	ll ans = 0;
	for (int i = 2; i <= tot; i++) {
		if (s[i].first == s[i - 1].first) chkmin(s[i].second, s[i - 1].second);
		if (s[i].first - s[i - 1].first >= 2) chkmax(ans, (s[i].first - s[i - 1].first - 1ll) * m + s[i - 1].second);
	}
	if (s[1].first + n - s[tot].first >= 2) chkmax(ans, (s[1].first + n - s[tot].first - 1ll) * m + s[tot].second);
	return ans;
}
ll getans(int x, int y, vector <int> a) {
	return max(calc(x, y, a), calc(y, x, a));
}
ll get(vector <int> a, int n) {
	if (a.size() == n) return 0;
	sort(a.begin(), a.end());
	while (a.size() != 0 && a.back() == n - 1) a.pop_back(), n--;
	return n - 1;
}
int main() {
	int n, m; read(n), read(m);
	int g = __gcd(n, m);
	if (g >= MAXN) {
		puts("-1");
		return 0;
	}
	int cnt; read(cnt);
	vector <int> tx, ty;
	while (cnt--) {
		int x; read(x);
		a[x % g].push_back(x / g);
		tx.push_back(x);
	}
	read(cnt);
	while (cnt--) {
		int x; read(x);
		a[x % g].push_back(x / g);
		ty.push_back(x);
	}
	ll ans = max(get(tx, n), get(ty, m));
	for (int i = 0; i <= g - 1; i++)
		if (a[i].empty()) {
			puts("-1");
			return 0;
		} else {
			sort(a[i].begin(), a[i].end());
			a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
			if (a[i].size() < max(n, m) / g) chkmax(ans, 1ll * g * getans(n / g, m / g, a[i]) + i);
		}
	writeln(ans);
	return 0;
}