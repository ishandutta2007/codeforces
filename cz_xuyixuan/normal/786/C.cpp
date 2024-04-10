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
	int n, a[MAXN];
	void init(int x) {
		n = x;
		memset(a, 0, sizeof(a));
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	int query(int x) {
		int ans = 0;
		for (int i = 20; i >= 0; i--) {
			int tmp = 1 << i;
			if (ans + tmp <= n && a[ans + tmp] <= x) {
				x -= a[ans + tmp];
				ans += tmp;
			}
		}
		return ans;
	}
} BIT;
int n, val[MAXN], last[MAXN], ans[MAXN];
vector <int> a[MAXN], home[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(val[i]);
		a[last[val[i]]].push_back(i);
		last[val[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		home[1].push_back(i);
	BIT.init(n);
	for (int i = 1; i <= n; i++) {
		if (i != 1) BIT.modify(i - 1, -1);
		for (unsigned j = 0; j < a[i - 1].size(); j++)
			BIT.modify(a[i - 1][j], 1);
		for (unsigned j = 0; j < home[i].size(); j++) {
			int tmp = home[i][j];
			ans[tmp]++, home[BIT.query(tmp) + 1].push_back(tmp);
		}
	}
	for (int i = 1; i <= n; i++)
		write(ans[i]), putchar(' ');
	return 0;
}