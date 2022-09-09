#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
int n, cnt;
int v[MAXN], pre[MAXN];
vector <int> q;
int main() {
	read(n), cnt = 0;
	for (int i = 1; i <= n; i++) {
		int m; read(m);
		int Min = 1e6, Max = 0;
		for (int j = 1; j <= m; j++) {
			read(v[j]);
			chkmin(Min, v[j]);
			chkmax(Max, v[j]);
		}
		bool flg = false;
		for (int j = 1; j <= m - 1; j++)
			if (v[j] < v[j + 1]) flg = true;
		if (flg) cnt++;
		else {
			pre[Min]++;
			q.push_back(Max);
		}
	}
	for (int i = 1; i <= 1e6; i++)
		pre[i] += pre[i - 1];
	ll ans = 2ll * cnt * n - 1ll * cnt * cnt;
	for (auto x : q)
		if (x > 0) ans += pre[x - 1];
	cout << ans << endl;
	return 0;
}