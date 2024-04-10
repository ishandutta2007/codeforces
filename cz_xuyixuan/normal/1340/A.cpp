#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
struct BinaryIndexTree {
	int n, a[MAXN];
	void init(int x) {
		n = x;
		for (int i = 1; i <= n; i++)
			a[i] = 0;
	}
	void modify(int x, int d) {
		for (int i = x; i <= n; i += i & -i)
			a[i] += d;
	}
	int query(int x) {
		int ans = 0;
		for (int i = x; i >= 1; i -= i & -i)
			ans += a[i];
		return ans;
	}
	int query(int l, int r) {
		int ans = 0;
		for (int i = r; i >= 1; i -= i & -i)
			ans += a[i];
		for (int i = l - 1; i >= 1; i -= i & -i)
			ans -= a[i];
		return ans;
	}
} BIT;
int n, a[MAXN], home[MAXN];
int f[MAXN], cnt[MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int main() {
	int T; read(T);
	while (T--) {
		read(n), BIT.init(n);
		for (int i = 1; i <= n; i++)
			read(a[i]), home[a[i]] = i;
		for (int i = 1; i <= n + 1; i++) {
			cnt[i] = 1, f[i] = i;
			BIT.modify(1, 1);
		}
		f[n + 1] = n + 1, cnt[n + 1] = 0;
		bool ans = true;
		for (int i = 1; i <= n; i++) {
			int pos = home[i], value = cnt[pos];
			ans &= BIT.query(value + 1, n) == 0;
			BIT.modify(value, -1);
			int fa = find(pos + 1);
			if (fa != n + 1) {
				BIT.modify(cnt[fa], -1);
				cnt[fa] += cnt[pos];
				BIT.modify(cnt[fa], 1);
			}
			f[pos] = fa;
		}
		if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}