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
	int n, s[MAXN];
	int sa[MAXN], rk[MAXN], ht[MAXN];
	int Min[MAXLOG][MAXN], bit[MAXN];
	void init(int x, char *y) {
		n = 2 * x + 1;
		s[x + 1] = 0;
		s[n + 1] = -1;
		for (int i = 1; i <= x; i++)
			s[i] = s[n - i + 1] = y[i];
		static int cnt[MAXN];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
			cnt[s[i]]++;
		for (int i = 1; i <= 256; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--)
			sa[cnt[s[i]]--] = i;
		rk[sa[1]] = 1;
		for (int i = 2; i <= n; i++)
			rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
		for (int k = 1; rk[sa[n]] != n; k <<= 1) {
			static int x[MAXN], y[MAXN];
			for (int i = 1; i <= n; i++)
				x[i] = rk[i];
			for (int i = 1; i <= n; i++)
				y[i] = (i + k <= n) ? rk[i + k] : 0;
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[y[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			static int tmp[MAXN];
			for (int i = n; i >= 1; i--)
				tmp[cnt[y[i]]--] = i;
			memset(cnt, 0, sizeof(cnt));
			for (int i = 1; i <= n; i++)
				cnt[x[i]]++;
			for (int i = 1; i <= n; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n; i >= 1; i--)
				sa[cnt[x[tmp[i]]]--] = tmp[i];
			rk[sa[1]] = 1;
			for (int i = 2; i <= n; i++)
				rk[sa[i]] = rk[sa[i - 1]] + (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]);
		}
		sa[n + 1] = 0;
		for (int i = 1; i <= n; i++) {
			int j = sa[rk[i] + 1];
			ht[rk[i]] = ht[rk[i - 1]];
			if (ht[rk[i]]) ht[rk[i]]--;
			while (s[i + ht[rk[i]]] == s[j + ht[rk[i]]]) ht[rk[i]]++;
		}
		for (int i = 1; i <= n; i++) {
			bit[i] = bit[i - 1];
			Min[0][i] = ht[i];
			if (i >= (1 << (bit[i] + 1))) bit[i]++;
		}
		for (int p = 1; p < MAXLOG; p++)
		for (int i = 1, j = (1 << (p - 1)) + 1; i + (1 << p) - 1 <= n; i++, j++)
			Min[p][i] = min(Min[p - 1][i], Min[p - 1][j]);
	}
	int lcp(int x, int y) {
		if (x == y) {
			if (x <= n / 2) return n / 2 - x + 1;
			else return n - x + 1;
		}
		x = rk[x], y = rk[y];
		if (x > y) swap(x, y);
		int len = y - x;
		int tmp = bit[len];
		y -= 1 << tmp;
		return min(Min[tmp][x], Min[tmp][y]);
	}
}
int n, now;
int tag[MAXN];
char s[MAXN];
bool Modify() {
	while (++now <= n) {
		int last = 0;
		for (int i = now, j = 2 * now; j <= n; i += now, j += now) {
			int pre = SuffixArray :: lcp(2 * n + 2 - i, 2 * n + 2 - j);
			int suf = SuffixArray :: lcp(i, j);
			chkmin(pre, now);
			chkmin(suf, now);
			if (pre + suf - 1 >= now) {
				int from = i - pre + 1, to = i + suf - now;
				if (to > last) {
					int pos = max(from, last + 1);
					last = pos + now - 1;
					tag[pos + now - 1] = now;
				}
			}
		}
		if (last) {
			for (int i = n; i >= 1; i--)
				if (tag[i] >= 2) tag[i - 1] = tag[i] - 1;
			int newn = 0;
			for (int i = 1; i <= n; i++)
				if (!tag[i]) s[++newn] = s[i];
				else tag[i] = 0;
			n = newn;
			s[n + 1] = 0;
			return true;
		}
	}
	return false;
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	SuffixArray :: init(n, s);
	while (Modify()) SuffixArray :: init(n, s);
	printf("%s\n", s + 1);
	return 0;
}