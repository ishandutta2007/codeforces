#include<bits/stdc++.h>
using namespace std;
const int MAXK = 405;
const int MAXN = 1e5 + 5;
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
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int timer, a[MAXN], l[MAXN], r[MAXN];
namespace MultipleSuffixAutomaton {
	const int MAXN = 2 * 100005;
	const int MAXC = 26;
	int root, size, last;
	int child[MAXN][MAXC];
	int fail[MAXN], depth[MAXN];
	vector <int> col[MAXN], fin[MAXN], e[MAXN];
	int newnode(int dep) {
		fail[size] = 0;
		depth[size] = dep;
		memset(child[size], 0, sizeof(child[size]));
		return size++;
	}
	void extend(int ch, int colour) {
		int p = last;
		if (child[p][ch]) {
			int q = child[p][ch];
			if (depth[p] + 1 == depth[q]) col[last = q].push_back(colour);
			else {
				int np = newnode(depth[p] + 1);
				while (child[p][ch] == q) {
					child[p][ch] = np;
					p = fail[p];
				}
				fail[np] = fail[q]; fail[q] = np;
				memcpy(child[np], child[q], sizeof(child[q]));
				col[last = np].push_back(colour);
			}
		} else {
			int np = newnode(depth[p] + 1);
			while (child[p][ch] == 0) {
				child[p][ch] = np;
				p = fail[p];
			}
			if (child[p][ch] == np) fail[np] = root;
			else {
				int q = child[p][ch];
				if (depth[p] + 1 == depth[q]) fail[np] = q;
				else {
					int nq = newnode(depth[p] + 1);
					memcpy(child[nq], child[q], sizeof(child[q]));
					fail[nq] = fail[q];
					fail[q] = fail[np] = nq;
					while (child[p][ch] == q) {
						child[p][ch] = nq;
						p = fail[p];
					}
				}
			}
			col[last = np].push_back(colour);
		}
	}
	void init() {
		size = 0;
		root = newnode(0);
	}
	void insert(char *s, int colour) {
		last = root;
		int len = strlen(s + 1);
		for (int i = 1; i <= len; i++)
			extend(s[i] - 'a', colour);
		fin[last].push_back(colour);
	}
	void dfs(int pos) {
		int dfn = timer + 1;
		for (auto x : col[pos]) a[++timer] = x;
		for (auto x : e[pos]) dfs(x);
		int rit = timer;
		for (auto x : fin[pos]) l[x] = dfn, r[x] = rit;
	}
	void work() {
		for (int i = 1; i < size; i++)
			e[fail[i]].push_back(i);
		dfs(0);
	}
}
char s[MAXN]; int ans[MAXN], bns[MAXN], cnt[MAXK][MAXN];
int n, m, tot, block, belong[MAXN], ql[MAXN], qr[MAXN];
ll res[MAXN]; vector <pair <int, int>> qry[MAXN];
ll query(int x) {
	ll res = ans[x];
	for (int i = 1; i <= tot; i++)
		res += 1ll * cnt[i][x] * bns[i];
	return res;
}
void modify(int l, int r) {
	if (belong[l] == belong[r]) {
		for (int i = l; i <= r; i++)
			ans[a[i]]++;
	} else {
		for (int i = l; i <= qr[belong[l]]; i++)
			ans[a[i]]++;
		for (int i = belong[l] + 1; i <= belong[r] - 1; i++)
			bns[i]++;
		for (int i = ql[belong[r]]; i <= r; i++)
			ans[a[i]]++;
	}
}
int main() {
	read(n), read(m);
	MultipleSuffixAutomaton :: init();
	for (int i = 1; i <= n; i++) {
		scanf("\n%s", s + 1);
		MultipleSuffixAutomaton :: insert(s, i);
	}
	MultipleSuffixAutomaton :: work();
	block = sqrt(timer);
	for (int i = 1; i <= timer; i++) {
		if (i % block == 1 % block) ql[++tot] = i;
		belong[i] = tot, qr[tot] = i;
	}
	for (int i = 1; i <= tot; i++)
	for (int j = ql[i]; j <= qr[i]; j++)
		cnt[i][a[j]]++;
	for (int i = 1; i <= m; i++) {
		int l, r, x; read(l), read(r), read(x);
		qry[r].emplace_back(x, i);
		qry[l - 1].emplace_back(x, -i);
	}
	for (int i = 1; i <= n; i++) {
		modify(l[i], r[i]);
		for (auto x : qry[i]) {
			if (x.second < 0) res[-x.second] -= query(x.first);
			else res[x.second] += query(x.first);
		}
	}
	for (int i = 1; i <= m; i++)
		writeln(res[i]);
	return 0;
}