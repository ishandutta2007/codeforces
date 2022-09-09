#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 1205;
const int P = 1e9 + 7;
typedef long long ll;
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
struct info {int l, r, pos; };
int n, k, q, a[MAXN]; ull bit[MAXN];
int tot, belong[MAXN], ql[MAXM], qr[MAXM];
int all[MAXM], cnt[MAXM], b[MAXM][MAXM];
ull pre[MAXM][MAXM], suf[MAXM][MAXM];
bool bad[MAXM];
void rebuild(int t) {
	int l = ql[t], r = qr[t]; all[t] = 0;
	for (int i = l; i <= r; i++)
		if (a[i] >= 0) b[t][++all[t]] = a[i];
		else if (b[t][all[t]] != -a[i]) b[t][++all[t]] = a[i];
		else all[t]--;
	cnt[t] = 0; bad[t] = false;
	for (int i = 1; i <= all[t] - 1; i++)
		if (b[t][i] > 0 && b[t][i + 1] < 0) bad[t] = true;
	while (cnt[t] < all[t] && b[t][cnt[t] + 1] < 0) cnt[t]++;
	for (int i = 0; i <= all[t] + 1; i++)
		pre[t][i] = suf[t][i] = 0;
	for (int i = 1; i <= all[t]; i++)
		pre[t][i] = pre[t][i - 1] * P + b[t][i];
	for (int i = all[t]; i >= 1; i--)
		suf[t][i] = suf[t][i + 1] * P - b[t][i];
}
ull Hashpre(int pos, int l, int r) {
	return pre[pos][r] - pre[pos][l - 1] * bit[r - l + 1];
}
ull Hashsuf(int pos, int l, int r) {
	return suf[pos][l] - suf[pos][r + 1] * bit[r - l + 1];
}
bool query(int l, int r) {
	if ((r - l + 1) & 1) return false;
	if (belong[l] == belong[r]) {
		static int s[MAXN]; int top = 0;
		for (int i = l; i <= r; i++)
			if (a[i] >= 0) s[++top] = a[i];
			else if (s[top--] != -a[i]) return false;
		return top == 0;
	} else {
		static info s[MAXN]; int top = 0;
		for (int i = l; i <= qr[belong[l]]; i++)
			if (a[i] >= 0) s[++top] = (info) {i, i, 0};
			else if (a[s[top--].l] != -a[i]) return false;
		for (int i = belong[l] + 1; i <= belong[r] - 1; i++) {
			int nl = 1, nr = cnt[i];
			if (bad[i]) return false;
			while (nl <= nr && top >= 1) {
				if (s[top].pos == 0) {
					if (a[s[top].l] == -b[i][nl]) top--, nl++;
					else return false;
				} else {
					int len = min(nr - nl + 1, s[top].r - s[top].l + 1);
					if (Hashpre(i, nl, nl + len - 1) == Hashsuf(s[top].pos, s[top].r - len + 1, s[top].r)) {
						nl += len, s[top].r -= len;
						if (s[top].l > s[top].r) top--;
					} else return false;
				}
			}
			if (nl <= nr) return false;
			if (cnt[i] != all[i]) s[++top] = (info) {cnt[i] + 1, all[i], i};
		}
		for (int i = ql[belong[r]]; i <= r; i++) {
			if (a[i] >= 0) s[++top] = (info) {i, i, 0};
			else {
				if (s[top].pos == 0) {
					if (a[s[top--].l] != -a[i]) return false;
				} else {
					if (b[s[top].pos][s[top].r--] != -a[i]) return false;
					if (s[top].l > s[top].r) top--;
				}
			}
		}
		return top == 0;
	}
}
int main() {
	read(n), read(k), bit[0] = 1;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		bit[i] = bit[i - 1] * P;
	}
	int block = sqrt(n);
	for (int i = 1; i <= n; i++) {
		if (i % block == 1 % block) ql[++tot] = i;
		qr[tot] = i, belong[i] = tot;
	}
	for (int t = 1; t <= tot; t++)
		rebuild(t);
	read(q);
	for (int i = 1; i <= q; i++) {
		int opt, x, y;
		read(opt), read(x), read(y);
		if (opt == 1) a[x] = y, rebuild(belong[x]);
		else {
			static int cnt = 0;
			if (query(x, y)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}