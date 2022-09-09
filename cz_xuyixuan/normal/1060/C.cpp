#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 5e6 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <int, int> pr;
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
int n, m, a[MAXN], b[MAXN], tot;
int x, sum[MAXM], pre[MAXM];
pr val[MAXM];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++)
		read(b[i]);
	read(x);
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = i; j <= n; j++) {
			sum += a[j];
			val[++tot] = make_pair(sum, j - i + 1);
		}
	}
	sort(val + 1, val + tot + 1);
	for (int i = 1; i <= tot; i++) {
		sum[i] = val[i].first;
		pre[i] = max(pre[i - 1], val[i].second);
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int s = 0;
		for (int j = i; j <= m; j++) {
			s += b[j];
			int tmp = x / s;
			int pos = upper_bound(sum + 1, sum + tot + 1, tmp) - sum - 1;
			chkmax(ans, (j - i + 1) * pre[pos]);
		}
	}
	writeln(ans);
	return 0;
}