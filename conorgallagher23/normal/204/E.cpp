#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 200005, inf = 1e9;

int n, k, m, a[N], nn, lim, bel[N];
int rr[N], buc[N], pos[N], len[N];
char str[N]; ll ans[N];

struct SuffixArray {
	int buc[N], sa[N], rk[N], fir[N], sec[N];
	int lg[N], hei[N], mn[N][21];
	
	int LCP(int x, int y) {
		if (x == y) return nn - sa[x] + 1;
		if (x > y) swap(x, y); y--;
		int tt = lg[y - x + 1];
		return min(mn[x][tt], mn[y - (1 << tt) + 1][tt]);
	}
	void suffix_sort() {
		for (int i = 1; i <= nn; i++) buc[a[i]]++;
		for (int i = 1; i <= lim; i++) buc[i] += buc[i - 1];
		for (int i = 1; i <= nn; i++) sa[buc[a[i]]--] = i;
		rk[sa[1]] = 1;
		for (int i = 2; i <= nn; i++) rk[sa[i]] = rk[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]]);
		for (int k = 1; k <= nn; k <<= 1) {
			for (int i = 1; i <= nn; i++) fir[i] = rk[i], sec[i] = i + k <= nn ? rk[i + k] : 0;
			memset(buc, 0, sizeof(buc));
			for (int i = 1; i <= nn; i++) buc[sec[i]]++;
			for (int i = 1; i <= nn; i++) buc[i] += buc[i - 1];
			for (int i = nn; i >= 1; i--) rk[buc[sec[i]]--] = i;
			memset(buc, 0, sizeof(buc));
			for (int i = 1; i <= nn; i++) buc[fir[i]]++;
			for (int i = 1; i <= nn; i++) buc[i] += buc[i - 1];
			for (int i = nn; i >= 1; i--) sa[buc[fir[rk[i]]]--] = rk[i];
			rk[sa[1]] = 1;
			for (int i = 2; i <= nn; i++) rk[sa[i]] = rk[sa[i - 1]] + (fir[sa[i]] != fir[sa[i - 1]] || sec[sa[i]] != sec[sa[i - 1]]);
		}
	}
	void get_height() {
		int len = 0;
		for (int i = 1; i <= nn; i++) {
			if (len) len--; int pos = sa[rk[i] + 1];
			if (rk[i] == nn) continue;
			else {
				while (a[i + len] == a[pos + len]) len++;
				hei[rk[i]] = len;
			}
		}
		lg[0] = -1; for (int i = 1; i < nn; i++) lg[i] = lg[i >> 1] + 1;
		for (int i = 1; i < nn; i++) mn[i][0] = hei[i];
		for (int k = 1; k <= 20; k++)
			for (int i = 1; i + (1 << k) - 1 <= nn; i++) mn[i][k] = min(mn[i][k - 1], mn[i + (1 << k - 1)][k - 1]); 
	}
} SA;

void getL() {
	memset(buc, 0, sizeof(buc));
	int pos = 1, res = 0;
	for (int i = 1; i <= m; i++) {
		int si = SA.sa[i]; if (bel[si] == -1) continue;
		while (res < k && pos <= m) {
			int sp = SA.sa[pos]; pos++;
			if (bel[sp] == -1) continue;
			buc[bel[sp]]++; if (buc[bel[sp]] == 1) res++;
		}
		if (res != k) rr[i] = inf; else rr[i] = pos - 1;
		buc[bel[si]]--; if (!buc[bel[si]]) res--;
	}
}
bool check_lcp(int cur, int lcp) {
	int pl = cur, pr = cur;
	for (int i = 20; i >= 0; i--) {
		int now = pr + (1 << i);
		if (now <= m && SA.LCP(cur, now) >= lcp) pr = now;
	}
	for (int i = 20; i >= 0; i--) {
		int now = pl - (1 << i);
		if (now >= 1 && SA.LCP(now, cur) >= lcp) pl = now;
	}
	return rr[pl] <= pr;
}
int calc(int l, int r, int cur) {
	int pos = l;
	for (int i = 20; i >= 0; i--) {
		int now = pos + (1 << i);
		if (now <= r && check_lcp(cur, now)) pos = now;
	}
	return pos;
}

int main() {
	n = read(); k = read();
	for (int i = 1; i <= n; i++) {
		scanf("%s", str + 1); int l = strlen(str + 1);
		for (int j = 1; j <= l; j++) {
			bel[++nn] = i, pos[nn] = j, a[nn] = str[j] - 'a' + 1;
		}
		bel[++nn] = -1, a[nn] = i + 26, len[i] = l;
	}
	lim = n + 26, SA.suffix_sort(), SA.get_height();
	m = nn - n, getL();
	for (int i = 1; i <= nn; i++) {
		int si = SA.sa[i]; if (bel[si] == -1) continue;
		int tb = bel[si], L = 0, R = len[tb] - pos[si] + 1;
		ans[tb] += (ll)calc(L, R, i);
	}
	for (int i = 1; i <= n; i++) printf("%lld%c", ans[i], " \n" [i == n]);
	return 0;
}