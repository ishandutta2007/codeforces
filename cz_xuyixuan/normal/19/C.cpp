#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXLOG = 20;
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
namespace SuffixArray {
	int sa[MAXN], rank[MAXN], height[MAXN];
	int Min[MAXN][MAXLOG], bit[MAXN], N;
	void init(int *a, int n) {
		N = n;
		static int x[MAXN], y[MAXN], cnt[MAXN], rk[MAXN];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
			cnt[a[i]]++;
		for (int i = 1; i <= n; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--)
			sa[cnt[a[i]]--] = i;
		rank[sa[1]] = 1;
		for (int i = 2; i <= n; i++)
			rank[sa[i]] = rank[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]]);
		for (int k = 1; rank[sa[n]] != n; k <<= 1) {
			for (int i = 1; i <= n; i++) {
				x[i] = rank[i];
				y[i] = (i + k <= n) ? rank[i + k] : 0;
			}
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[y[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				rk[cnt[y[i]]--] = i;
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[x[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				sa[cnt[x[rk[i]]]--] = rk[i];
			rank[sa[1]] = 1;
			for (int i = 2; i <= n; i++)
				rank[sa[i]] = rank[sa[i - 1]] + (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]);		
		}
		int now = 0;
		for (int i = 1; i <= n; i++) {
			if (now) now--;
			while (a[i + now] == a[sa[rank[i] + 1] + now]) now++;
			height[rank[i]] = now;
		}
		for (int i = 1; i <= n; i++)
			Min[i][0] = height[i];
		for (int p = 1; p < MAXLOG; p++) {
			int tmp = 1 << (p - 1);
			for (int i = 1, j = tmp + 1; j <= n; i++, j++)
				Min[i][p] = min(Min[i][p - 1], Min[i + tmp][p - 1]);
		}
		for (int i = 1; i <= n; i++) {
			bit[i] = bit[i - 1];
			if (i >= 1 << (bit[i] + 1)) bit[i]++;
		}
	}
	int lcp(int x, int y) {
		if (x == y) return N - x + 1;
		x = rank[x], y = rank[y];
		if (x > y) swap(x, y);
		int tmp = bit[y - x];
		return min(Min[x][tmp], Min[y - (1 << tmp)][tmp]);
	}
}
struct info {int pos, len; };
info f[MAXN];
int cnt;
int n, val[MAXN];
int m, tmp[MAXN];
vector <int> a[MAXN];
bool cmp(info a, info b) {
	if (a.len == b.len) return a.pos < b.pos;
	else return a.len < b.len;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(val[i]);
		tmp[++m] = val[i];
	}
	sort(tmp + 1, tmp + n + 1);
	m = unique(tmp + 1, tmp + n + 1) - tmp - 1;
	for (int i = 1; i <= n; i++)
		val[i] = lower_bound(tmp + 1, tmp + m + 1, val[i]) - tmp;
	SuffixArray::init(val, n);
	for (int i = 1; i <= n; i++)
		a[val[i]].push_back(i);
	for (int i = 1; i <= n; i++) {
		int len = 0;
		for (unsigned j = 0; j < a[val[i]].size(); j++) {
			if (a[val[i]][j] <= i) continue;
			int tlen = a[val[i]][j] - i;
			if (i >= tlen && SuffixArray::lcp(i - tlen + 1, a[val[i]][j] - tlen + 1) >= tlen) {
				len = tlen;
				break;
			}
		}
		if (len) f[++cnt] = (info) {i, len};
	}
	sort(f + 1, f + cnt + 1, cmp);
	int lft = 1;
	for (int i = 1; i <= cnt; i++) {
		int lst = f[i].pos - f[i].len + 1;
		if (lst >= lft) lft = f[i].pos + 1;
	}
	writeln(n - lft + 1);
	for (int i = lft; i <= n; i++)
		printf("%d ", tmp[val[i]]);
	return 0;
}