#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MAXP = 2.5e7 + 5;
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
struct SegmentTree {
	struct Node {
		int lc, rc;
		int Max;
	} a[MAXP];
	int size, n;
	void init(int x) {
		n = x;
		size = 0;
	}
	void update(int root) {
		a[root].Max = max(a[a[root].lc].Max, a[a[root].rc].Max);
	}
	int modify(int root, int l, int r, int val) {
		int ans = ++size;
		a[ans] = a[root];
		if (l == r) {
			a[ans].Max++;
			return ans;
		}
		int mid = (l + r) / 2;
		if (mid >= val) a[ans].lc = modify(a[root].lc, l, mid, val);
		else a[ans].rc = modify(a[root].rc, mid + 1, r, val);
		update(ans);
		return ans;
	}
	int modify(int root, int val) {
		return modify(root, 1, n, val);
	}
	int merge(int ra, int rb, int l, int r) {
		if (ra == 0 || rb == 0) return ra + rb;
		if (l == r) {
			a[ra].Max += a[rb].Max;
			return ra;
		}
		int mid = (l + r) / 2;
		a[ra].lc = merge(a[ra].lc, a[rb].lc, l, mid);
		a[ra].rc = merge(a[ra].rc, a[rb].rc, mid + 1, r);
		update(ra);
		return ra;
	}
	int merge(int ra, int rb) {
		return merge(ra, rb, 1, n);
	}
	int query(int root, int l, int r) {
		if (l == r) return l;
		int mid = (l + r) / 2;
		if (a[root].Max == a[a[root].lc].Max) return query(a[root].lc, l, mid);
		else return query(a[root].rc, mid + 1, r);
	}
	int query(int root) {
		return query(root, 1, n);
	}
} ST;
int n, ans[MAXN], root[MAXN];
vector <int> a[MAXN];
void dfs(int pos, int fa, int depth) {
	root[pos] = ST.modify(root[pos], depth);
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			dfs(a[pos][i], pos, depth + 1);
			root[pos] = ST.merge(root[pos], root[a[pos][i]]);
		}
	ans[pos] = ST.query(root[pos]) - depth;
}
int main() {
	read(n);
	ST.init(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0, 1);
	for (int i = 1; i <= n; i++)
		writeln(ans[i]);
	return 0;
}