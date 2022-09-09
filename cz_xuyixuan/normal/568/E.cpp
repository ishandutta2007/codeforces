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
namespace Blocks {
	const int MAXN = 2e5 + 5;
	int n, block, tot, l[MAXN], r[MAXN], belong[MAXN];
	pair <int, int> pre[MAXN], part[MAXN];
	void init(int x) {
		n = x, block = sqrt(x);
		for (int i = 1; i <= n; i++) {
			if (i % block == 1 % block) l[++tot] = i;
			r[tot] = i, belong[i] = tot;
		}
	}
	void modify(int x, pair <int, int> val) {
		for (int i = x; i <= r[belong[x]]; i++)
			chkmax(part[i], val);
		for (int i = belong[x]; i <= tot; i++)
			chkmax(pre[i], val);
	}
	pair <int, int> query(int x) {
		return max(pre[belong[x] - 1], part[x]);
	}
}
set <int> st;
map <int, int> rnk, home;
int dp[MAXN], from[MAXN], type[MAXN], lft[MAXN];
int n, m, k, tot, a[MAXN], b[MAXN], c[MAXN], bak[MAXN];
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (a[i] != -1) st.insert(a[i]);
	}
	read(m);
	for (int i = 1; i <= m; i++) {
		read(b[i]);
		st.insert(b[i]);
	}
	sort(b + 1, b + m + 1);
	for (auto x : st) {
		rnk[x] = ++tot;
		home[tot] = x;
	}
	for (int i = 1; i <= n; i++)
		if (a[i] != -1) a[i] = rnk[a[i]];
	for (int i = 1; i <= m; i++) {
		b[i] = rnk[b[i]], lft[b[i]]++;
		if (b[i] != c[k]) c[++k] = b[i];
	}
	a[n + 1] = tot + 1;
	for (int i = 1; i <= n + 1; i++)
		if (a[i] != -1) bak[i] = lower_bound(c + 1, c + k + 1, a[i]) - c;
	Blocks :: init(tot);
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] == -1) {
			int cnt = 0;
			for (int j = i; j <= n + 1; j++)
				if (a[j] == -1) cnt++;
				else if (bak[j] > cnt) {
					pair <int, int> tmp = Blocks :: query(c[bak[j] - cnt] - 1);
					if (tmp.first + cnt + 1 > dp[j]) {
						dp[j] = tmp.first + cnt + 1;
						from[j] = tmp.second;
						type[j] = cnt;
					}
				}
		} else {
			pair <int, int> tmp = Blocks :: query(a[i] - 1);
			if (tmp.first + 1 > dp[i]) {
				dp[i] = tmp.first + 1;
				from[i] = tmp.second;
				type[i] = 0;
			}
			Blocks :: modify(a[i], make_pair(dp[i], i));
		}
	}
	int now = n + 1;
	while (now != 0) {
		int cnt = type[now], pos = bak[now];
		for (int i = now; cnt; i--)
			if (a[i] == -1) {
				a[i] = c[--pos];
				lft[c[pos]]--;
				cnt--;
			}
		now = from[now];
	}
	int tmp = 1;
	for (int i = 1; i <= n; i++)
		if (a[i] == -1) {
			while (lft[tmp] == 0) tmp++;
			lft[tmp]--, a[i] = tmp;
		}
	for (int i = 1; i <= n; i++)
		printf("%d ", home[a[i]]);
	return 0;
}