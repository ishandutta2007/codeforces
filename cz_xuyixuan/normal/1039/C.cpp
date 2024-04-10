#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int P = 1e9 + 7;
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
struct info {int l, r; ll delta; } a[MAXN];
int n, m, k, bit[MAXN], f[MAXN];
bool vis[MAXN]; ll x[MAXN];
bool cmp(info a, info b) {
	return a.delta < b.delta;
}
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
int main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i++)
		read(x[i]);
	bit[0] = 1;
	for (int i = 1; i <= n; i++)
		bit[i] = bit[i - 1] * 2 % P;
	for (int i = 1; i <= m; i++) {
		read(a[i].l), read(a[i].r);
		a[i].delta = x[a[i].l] ^ x[a[i].r];
	}
	sort(a + 1, a + m + 1, cmp);
	int cnt = 0, ans = 0;
	for (int i = 1, nxt; i <= m; i = nxt + 1) {
		for (nxt = i; nxt < m && a[nxt + 1].delta == a[i].delta; nxt++);
		int comp = n; cnt++;
		for (int j = i; j <= nxt; j++) {
			f[a[j].l] = a[j].l;
			f[a[j].r] = a[j].r;
			comp -= !vis[a[j].l];
			vis[a[j].l] = true;
			comp -= !vis[a[j].r];
			vis[a[j].r] = true;
		}
		for (int j = i; j <= nxt; j++)
			f[F(a[j].l)] = F(a[j].r);
		for (int j = i; j <= nxt; j++) {
			if (vis[a[j].l]) comp += F(a[j].l) == a[j].l;
			vis[a[j].l] = false;
			if (vis[a[j].r]) comp += F(a[j].r) == a[j].r;
			vis[a[j].r] = false;
		}
		ans = (ans + bit[comp]) % P;
	}
	ans = (ans + ((1ll << k) - cnt) % P * bit[n]) % P;
	writeln(ans);
	return 0;
}