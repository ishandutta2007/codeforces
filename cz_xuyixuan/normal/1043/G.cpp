#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXC = 26;
const int MAXLOG = 20;
typedef long long ll;
typedef long double ld;
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
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct SuffixArray {
	int sa[MAXN], rnk[MAXN], height[MAXN];
	int Min[MAXN][MAXLOG], bit[MAXN], N;
	void init(char *a, int n) {
		N = n;
		static int x[MAXN], y[MAXN], cnt[MAXN], rk[MAXN];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++)
			cnt[(int) a[i]]++;
		for (int i = 1; i <= 256; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--)
			sa[cnt[(int) a[i]]--] = i;
		rnk[sa[1]] = 1;
		for (int i = 2; i <= n; i++)
			rnk[sa[i]] = rnk[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]]);
		for (int k = 1; rnk[sa[n]] != n; k <<= 1) {
			for (int i = 1; i <= n; i++) {
				x[i] = rnk[i];
				y[i] = (i + k <= n) ? rnk[i + k] : 0;
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
			rnk[sa[1]] = 1;
			for (int i = 2; i <= n; i++)
				rnk[sa[i]] = rnk[sa[i - 1]] + (x[sa[i]] != x[sa[i - 1]] || y[sa[i]] != y[sa[i - 1]]);		
		}
		int now = 0;
		for (int i = 1; i <= n; i++) {
			if (now) now--;
			while (a[i + now] == a[sa[rnk[i] + 1] + now]) now++;
			height[rnk[i]] = now;
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
		x = rnk[x], y = rnk[y];
		if (x > y) swap(x, y);
		int tmp = bit[y - x];
		return min(Min[x][tmp], Min[y - (1 << tmp)][tmp]);
	}
} SuffixArray[2];
char s[MAXN];
bool ans[MAXN][4];
int n, q, cnt[MAXN][MAXC];
pair <pair <int, int>, int> a[MAXN];
void Check() {
	for (int i = 1; i <= n; i++) {
		memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i]));
		cnt[i][s[i] - 'a']++;
	}
	for (int i = 1; i <= q; i++) {
		ans[i][0] = true;
		for (int j = 0; j <= 25; j++)
			if (cnt[a[i].first.second][j] - cnt[a[i].first.first - 1][j] >= 2) {
				ans[i][0] = false;
			}
	}
}
void CheckOne() {
	static vector <int> d[MAXN];
	for (int i = 1; i <= n; i++)
	for (int j = 2 * i; j <= n; j += i)
		d[j].push_back(i);
	for (int i = 1; i <= q; i++) {
		int l = a[i].first.first;
		int r = a[i].first.second;
		int len = r - l + 1;
		for (auto x : d[len]) {
			if (SuffixArray[0].lcp(l, l + x) >= len - x) {
				ans[i][1] = true;
				break;
			}
		}
	}
}
struct Heap {
	priority_queue <int, vector <int>, greater <int>> Heap, Delt;
	void clear() {
		while (!Heap.empty()) Heap.pop();
		while (!Delt.empty()) Delt.pop();
	}
	void ins(int x) {
		Heap.push(x);
	}
	void del(int x) {
		Delt.push(x);
	}
	int query() {
		while (!Heap.empty() && !Delt.empty() && Heap.top() == Delt.top()) {
			Heap.pop();
			Delt.pop();
		}
		if (Heap.empty()) return -1;
		else return Heap.top();
	}
} Heap;
int b[MAXN], f[MAXN];
void Calcbf() {
	static vector <int> a[MAXN];
	for (int i = 1; i <= n; i++)
	for (int j = i, k = 2 * i; k <= n; j += i, k += i) {
		int l = SuffixArray[1].lcp(n - j + 1, n - k + 1);
		int r = SuffixArray[0].lcp(j, k);
		int ql = j - l + 1, qr = j;
		chkmax(ql, j - i + 1);
		chkmin(qr, j - (i - r));
		if (ql <= qr) {
			a[ql].push_back(2 * i);
			a[qr + 1].push_back(-2 * i);
		}
	}
	Heap.clear();
	for (int i = 1; i <= n; i++) {
		for (auto x : a[i]) {
			if (x >= 0) Heap.ins(x);
			else Heap.del(-x);
		}
		a[i].clear();
		if (Heap.query() == -1) f[i] = n + 1;
		else f[i] = Heap.query();
	}
	for (int i = 1; i <= n; i++)
	for (int j = i, k = 2 * i; k <= n; j += i, k += i) {
		int l = SuffixArray[1].lcp(n - j + 1, n - k + 1);
		int r = SuffixArray[0].lcp(j, k);
		int ql = k, qr = min(n, k + r - 1);
		chkmax(ql, k + (i - l));
		chkmin(qr, k + i - 1);
		if (ql <= qr) {
			a[ql].push_back(2 * i);
			a[qr + 1].push_back(-2 * i);
		}
	}
	Heap.clear();
	for (int i = 1; i <= n; i++) {
		for (auto x : a[i]) {
			if (x >= 0) Heap.ins(x);
			else Heap.del(-x);
		}
		a[i].clear();
		if (Heap.query() == -1) b[i] = n + 1;
		else b[i] = Heap.query();
	}
}
struct SegmentTree {
	struct Node {
		int lc, rc, tag;
		int ans, val;
		int Max, Min;
	} a[MAXN * 4];
	int n, root, size;
	void update(int root) {
		a[root].ans = max(a[a[root].lc].ans, a[a[root].rc].ans);
		a[root].Min = min(a[a[root].lc].Min, a[a[root].rc].Min);
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
	}
	void build(int &root, int l, int r, int *val) {
		root = ++size;
		if (l == r) {
			a[root].val = val[l];
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, val);
		build(a[root].rc, mid + 1, r, val);
		a[root].val = max(a[a[root].lc].val, a[a[root].rc].val);
	}
	void init(int x, int *val) {
		n = x, root = size = 0;
		build(root, 1, n, val);
	}
	void pushdown(int root) {
		if (a[root].tag) {
			a[a[root].lc].ans = a[a[root].lc].val + a[root].tag;
			a[a[root].lc].tag = a[root].tag;
			a[a[root].lc].Min = a[root].tag;
			a[a[root].lc].Max = a[root].tag;
			a[a[root].rc].ans = a[a[root].rc].val + a[root].tag;
			a[a[root].rc].tag = a[root].tag;
			a[a[root].rc].Min = a[root].tag;
			a[a[root].rc].Max = a[root].tag;
			a[root].tag = 0;
		}
	}
	void modify(int root, int l, int r, int ql, int qr, int val) {
		if (l == ql && r == qr) {
			a[root].ans = a[root].val + val;
			a[root].tag = val;
			a[root].Min = val;
			a[root].Max = val;
			return;
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) modify(a[root].lc, l, mid, ql, min(mid, qr), val);
		if (mid + 1 <= qr) modify(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, val);
		update(root);
	}
	void modify(int l, int r, int val) {
		modify(root, 1, n, l, r, val);
	}
	void query(int root, int l, int r, int ql, int qr, int lim, int &ans) {
		if (l == ql && r == qr) {
			if (lim >= a[root].Max) return;
			if (lim < a[root].Min) {
				chkmax(ans, a[root].ans);
				return;
			}
			int mid = (l + r) / 2;
			query(a[root].lc, l, mid, l, mid, lim, ans);
			query(a[root].rc, mid + 1, r, mid + 1, r, lim, ans);
		}
		pushdown(root);
		int mid = (l + r) / 2;
		if (mid >= ql) query(a[root].lc, l, mid, ql, min(mid, qr), lim, ans);
		if (mid + 1 <= qr) query(a[root].rc, mid + 1, r, max(mid + 1, ql), qr, lim, ans);
	}
	void query(int l, int r, int lim, int &ans) {
		query(root, 1, n, l, r, lim, ans);
	}
} ST;
namespace SuffixAutomaton {
	const int MAXN = 4e5 + 5;
	int root, tot, last;
	int home[MAXN], child[MAXN][MAXC];
	int fail[MAXN], depth[MAXN], cnt[MAXN];
	int newnode(int dep) {
		fail[tot] = 0;
		depth[tot] = dep;
		memset(child[tot], 0, sizeof(child[tot]));
		return tot++;
	}
	void extend(int ch, int from) {
		int p = last, np = newnode(depth[last] + 1);
		while (child[p][ch] == 0) {
			child[p][ch] = np;
			p = fail[p];
		}
		if (child[p][ch] == np) fail[np] = root;
		else {
			int q = child[p][ch];
			if (depth[q] == depth[p] + 1) fail[np] = q;
			else {
				int nq = newnode(depth[p] + 1);
				fail[nq] = fail[q];
				fail[q] = fail[np] = nq;
				memcpy(child[nq], child[q], sizeof(child[q]));
				while (child[p][ch] == q) {
					child[p][ch] = nq;
					p = fail[p];
				}
			}
		}
		cnt[last = np]++;
		home[from] = np;
	}
	vector <int> a[MAXN];
	int son[MAXN], size[MAXN], value[MAXN];
	int timer, up[MAXN], dfn[MAXN], rit[MAXN];
	void dfs(int pos) {
		size[pos] = 1;
		for (auto x : a[pos]) {
			dfs(x);
			size[pos] += size[x];
			if (son[pos] == 0 || size[x] > size[son[pos]]) {
				son[pos] = x;
			}
		}
	}
	void efs(int pos, int from) {
		up[pos] = from;
		dfn[pos] = ++timer;
		value[timer] = depth[pos];
		if (son[pos]) efs(son[pos], from);
		for (auto x : a[pos])
			if (x != son[pos]) efs(x, x);
		rit[pos] = timer;
	}
	void init(char *s) {
		tot = 0;
		root = last = newnode(0);
		int len = strlen(s + 1);
		for (int i = len; i >= 1; i--)
			extend(s[i] - 'a', i);
		for (int i = 1; i <= tot - 1; i++)
			a[fail[i]].push_back(i);
		fail[0] = -1;
		dfs(0), efs(0, 0);
		ST.init(timer, value);
	}
	void modify(int pos) {
		int tmp = pos;
		pos = home[pos];
		while (pos != -1) {
			ST.modify(dfn[up[pos]], dfn[pos], tmp);
			pos = fail[up[pos]];
		}
	}
	int query(int pos) {
		int tmp = pos, ans = 0;
		pos = home[pos];
		while (pos != -1) {
			ST.query(dfn[up[pos]], dfn[pos], tmp, ans);
			pos = fail[up[pos]];
		}
		return ans;
	}
}
bool cmp(pair <pair <int, int>, int> x, pair <pair <int, int>, int> y) {
	return x.first.second < y.first.second;
}
void CheckTwo() {
	SuffixAutomaton :: init(s); 
	sort(a + 1, a + q + 1, cmp);
	int pos = 1;
	for (int i = 1; i <= q; i++) {
		int l = a[i].first.first;
		int r = a[i].first.second;
		int home = a[i].second;
		while (pos <= r) SuffixAutomaton :: modify(pos++);
		ans[home][2] = SuffixAutomaton :: query(l) >= r + 1;
		ans[home][2] |= l + f[l] - 1 <= r;
		ans[home][2] |= r - b[r] + 1 >= l;
	}
}
namespace rmq {
	const int MAXN = 2e5 + 5;
	const int MAXLOG = 18;
	int Max[MAXN][MAXLOG], Min[MAXN][MAXLOG], Log[MAXN];
	int queryMax(int l, int r) {
		int len = r - l + 1, tmp = Log[len];
		return max(Max[l][tmp], Max[r - (1 << tmp) + 1][tmp]);
	}
	int queryMin(int l, int r) {
		int len = r - l + 1, tmp = Log[len];
		return min(Min[l][tmp], Min[r - (1 << tmp) + 1][tmp]);
	}
	void init(int *a, int n) {
		for (int i = 1; i <= n; i++) {
			Min[i][0] = a[i];
			Max[i][0] = a[i];
			Log[i] = Log[i - 1];
			if ((1 << (Log[i] + 1)) <= i) Log[i]++;
		}
		for (int t = 1; t < MAXLOG; t++)
		for (int i = 1, j = (1 << (t - 1)) + 1; j <= n; i++, j++) {
			Max[i][t] = max(Max[i][t - 1], Max[j][t - 1]);
			Min[i][t] = min(Min[i][t - 1], Min[j][t - 1]);
		}
	}
}
void CheckThree() {
	static int rp[MAXN];
	for (int i = 1; i <= n; i++)
		rp[i] = i + f[i] - 1;
	rmq :: init(rp, n);
	for (int i = 1; i <= q; i++) {
		int l = a[i].first.first;
		int r = a[i].first.second;
		int home = a[i].second;
		ans[home][3] = rmq :: queryMin(l, r) <= r;
		ans[home][3] |= cnt[r][s[l] - 'a'] - cnt[l - 1][s[l] - 'a'] >= 2;
		ans[home][3] |= cnt[r][s[r] - 'a'] - cnt[l - 1][s[r] - 'a'] >= 2;
	}
}
int main() {
	read(n), scanf("\n%s", s + 1), read(q);
	SuffixArray[0].init(s, n);
	reverse(s + 1, s + n + 1);
	SuffixArray[1].init(s, n);
	reverse(s + 1, s + n + 1);
	for (int i = 1; i <= q; i++) {
		read(a[i].first.first);
		read(a[i].first.second);
		a[i].second = i;
	}
	Check();
	Calcbf();
	CheckOne();
	CheckTwo();
	CheckThree();
	for (int i = 1; i <= q; i++) {
		if (ans[i][0]) puts("-1");
		else if (ans[i][1]) puts("1");
		else if (ans[i][2]) puts("2");
		else if (ans[i][3]) puts("3");
		else puts("4");
	}
	return 0;
}