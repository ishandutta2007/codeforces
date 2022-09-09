#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
struct query {int l, r, home, timer; };
struct change {int pos, val, timer; };
map <int, int> num;
query q[MAXN];
change c[MAXN];
int cntq, cntc, ans[MAXN];
int n, m, cnt, a[MAXN], b[MAXN];
int len, blk, idx[MAXN];
struct DataStructure {
	int a[MAXN], c[MAXN];
	void clear() {
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
	}
	void insert(int x) {
		a[c[x]]--;
		c[x]++;
		a[c[x]]++;
	}
	void del(int x) {
		a[c[x]]--;
		c[x]--;
		a[c[x]]++;
	}
	int query() {
		int ans = 1;
		while (a[ans]) ans++;
		return ans;
	}
} DS;
int get(int x) {
	if (num.count(x)) return num[x];
	else return num[x] = ++cnt;
}
bool cmp(query a, query b) {
	if (idx[a.l] == idx[b.l]) {
		if (idx[a.r] == idx[b.r]) return a.timer < b.timer;
		else return idx[a.r] < idx[b.r];
	} else return idx[a.l] < idx[b.l];
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]), a[i] = get(a[i]);
	for (int i = 1; i <= m; i++) {
		int opt, l, r;
		read(opt), read(l), read(r);
		if (opt == 1) q[++cntq] = (query) {l, r, cntq, cntc};
		else c[++cntc] = (change) {l, get(r), cntc};
	}
	len = pow(n, 2.1 / 3.0);
	for (int i = 1; i <= n; i++) {
		if (i % len == 1 % len) blk++;
		idx[i] = blk;
	}
	sort(q + 1, q + cntq + 1, cmp);
	int l, r, nowc;
	for (int i = 1; i <= cntq; i++)
		if (idx[q[i].l] == idx[q[i - 1].l] && idx[q[i].r] == idx[q[i - 1].r]) {
			while (nowc <= cntc && c[nowc].timer <= q[i].timer) {
				int tmp = c[nowc].pos;
				if (tmp >= l && tmp <= r) DS.del(b[tmp]);
				b[tmp] = c[nowc].val;
				if (tmp >= l && tmp <= r) DS.insert(b[tmp]);
				nowc++;
			}
			while (l > q[i].l) DS.insert(b[--l]);
			while (r < q[i].r) DS.insert(b[++r]);
			while (l < q[i].l) DS.del(b[l++]);
			while (r > q[i].r) DS.del(b[r--]);
			ans[q[i].home] = DS.query();
		} else {
			DS.clear();
			for (int j = 1; j <= n; j++)
				b[j] = a[j];
			nowc = 1;
			while (nowc <= cntc && c[nowc].timer <= q[i].timer) {
				b[c[nowc].pos] = c[nowc].val;
				nowc++;
			}
			l = q[i].l, r = q[i].r;
			for (int j = l; j <= r; j++)
				DS.insert(b[j]);
			ans[q[i].home] = DS.query();
		}
	for (int i = 1; i <= cntq; i++)
		writeln(ans[i]);
	return 0;
}