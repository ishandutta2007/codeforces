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
int n, tot, father[MAXN], p[MAXN], ans[MAXN];
void work(int pos, int fa) {
	father[pos] = fa;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) work(a[pos][i], pos);
	p[++tot] = pos;
}
int f(int x) {
	if (ans[x] != -1) return ans[x];
	static int res[MAXN]; int tans = 0;
	for (int i = 1; i <= n; i++) {
		int Max = 1, Nax = 1, pos = p[i];
		for (unsigned i = 0; i < a[pos].size(); i++)
			if (a[pos][i] != father[pos]) {
				int tmp = res[a[pos][i]] + 1;
				if (tmp > Max) {
					Nax = Max;
					Max = tmp;
				} else chkmax(Nax, tmp);
			}
		if (Max + Nax - 1 >= x) tans++, res[pos] = 0;
		else res[pos] = Max;
	}
	return ans[x] = tans;
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	work(1, 0);
	memset(ans, -1, sizeof(ans));
	for (int i = 1, nxt; i <= n; i = nxt + 1) {
		int now = f(i);
		if (now >= 65 || f(i + 1) != now) {
			ans[nxt = i] = now;
			continue;
		}
		int l = i + 1, r = n;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (f(mid) == now) l = mid;
			else r = mid - 1;
		}
		nxt = l;
		for (int j = i; j <= nxt; j++)
			ans[j] = now;
	}
	for (int i = 1; i <= n; i++)
		writeln(ans[i]);
	return 0;
}