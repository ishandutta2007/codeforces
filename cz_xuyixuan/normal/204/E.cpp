#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
namespace MultipleSuffixAutomaton {
	const int MAXN = 2 * 100005;
	const int MAXC = 26;
	int root, size, last;
	int child[MAXN][MAXC];
	int fail[MAXN], depth[MAXN];
	vector <int> col[MAXN];
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
	}
	struct BinaryIndexTree {
		int n, a[MAXN];
		void init(int x) {
			n = x;
			memset(a, 0, sizeof(a));
		}
		void modify(int pos, int d) {
			for (int i = pos; i <= n; i += i & -i)
				a[i] += d;
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
	int timer, dfn[MAXN], rit[MAXN], cnt[MAXN], Last[MAXN];
	vector <int> a[MAXN], r[MAXN], home[MAXN], p[MAXN], d[MAXN];
	long long ans[MAXN];
	void work(int pos) {
		dfn[pos] = ++timer;
		for (unsigned i = 0; i < col[pos].size(); i++) {
			int tmp = col[pos][i];
			p[Last[tmp] + 1].push_back(timer);
			d[Last[tmp] + 1].push_back(1);
			p[timer + 1].push_back(timer);
			d[timer + 1].push_back(-1);
			Last[tmp] = timer;
		}
		for (unsigned i = 0; i < a[pos].size(); i++)
			work(a[pos][i]);
		rit[pos] = timer;
		r[dfn[pos]].push_back(rit[pos]);
		home[dfn[pos]].push_back(pos);
	}
	void dfs(int pos) {
		for (unsigned i = 0; i < a[pos].size(); i++) {
			cnt[a[pos][i]] += cnt[pos];
			dfs(a[pos][i]);
		}
		for (unsigned i = 0; i < col[pos].size(); i++)
			ans[col[pos][i]] += cnt[pos];
	}
	void calc(int n, int k) {
		for (int i = 1; i < size; i++)
			a[fail[i]].push_back(i);
		work(0);
		BIT.init(timer);
		for (int i = 1; i <= timer; i++) {
			for (unsigned j = 0; j < p[i].size(); j++)
				BIT.modify(p[i][j], d[i][j]);
			for (unsigned j = 0; j < r[i].size(); j++)
				if (BIT.query(i, r[i][j]) >= k) cnt[home[i][j]] = depth[home[i][j]] - depth[fail[home[i][j]]];
		}
		dfs(0);
		for (int i = 1; i <= n; i++)
			write(ans[i]), putchar(' ');
	}
}
char s[MAXN];
int main() {
	int n, k; read(n), read(k);
	MultipleSuffixAutomaton::init();
	for (int i = 1; i <= n; i++) {
		scanf("\n%s", s + 1);
		MultipleSuffixAutomaton::insert(s, i);
	}
	MultipleSuffixAutomaton::calc(n, k);
	return 0;
}