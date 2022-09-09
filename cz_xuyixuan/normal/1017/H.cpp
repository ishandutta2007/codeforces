#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int P = 998244353;
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
struct querys {int l, r, k, home; } qry[MAXN];
int prod[MAXN], inv[MAXN];
int n, m, q, size, blocks, block[MAXN];
int now, nowk, a[MAXN], b[MAXN], e[MAXN], ans[MAXN];
bool cmp(querys a, querys b) {
	return a.k < b.k;
}
bool cnp(querys a, querys b) {
	if (block[a.l] == block[b.l]) return a.r < b.r;
	else return block[a.l] < block[b.l];
}
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void add(int col) {
	b[col]++;
	int tmp = a[col] + nowk - b[col] + 1;
	now = 1ll * now * tmp % P;
}
void del(int col) {
	int tmp = a[col] + nowk - b[col] + 1;
	now = 1ll * now * inv[tmp] % P;
	b[col]--;
}
int main() {
	read(n), read(m), read(q);
	for (int i = 1; i <= n; i++)
		read(e[i]), a[e[i]]++;
	for (int i = 1; i <= q; i++)
		read(qry[i].l), read(qry[i].r), read(qry[i].k), qry[i].home = i;
	for (int i = 1; i < MAXN; i++)
		inv[i] = power(i, P - 2);
	sort(qry + 1, qry + q + 1, cmp);
	for (int i = 1, nxt; i <= q; i = nxt) {
		nxt = i; while (nxt <= q && qry[nxt].k == qry[i].k) nxt++;
		int cntq = nxt - i, tmp = 1ll * qry[i].k * m % P;
		size = max(n / sqrt(cntq), 1.0), blocks = 0;
		prod[0] = 1;
		for (int j = 1; j <= n; j++) {
			prod[j] = 1ll * prod[j - 1] * (tmp + j) % P;
			if (j % size == 1 % size) blocks++;
			block[j] = blocks;
		}
		sort(qry + i, qry + nxt, cnp);
		int l = qry[i].l, r = qry[i].l - 1;
		now = 1, nowk = qry[i].k;
		memset(b, 0, sizeof(b));
		for (int j = i; j < nxt; j++) {
			while (r < qry[j].r) add(e[++r]);
			while (l > qry[j].l) add(e[--l]);
			while (r > qry[j].r) del(e[r--]);
			while (l < qry[j].l) del(e[l++]);
			ans[qry[j].home] = 1ll * now * prod[n - (qry[j].r - qry[j].l + 1)] % P;
		}
	}
	for (int i = 1; i <= q; i++)
		writeln(ans[i]);
	return 0;
}