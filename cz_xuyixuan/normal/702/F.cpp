#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
struct Persistent_Treap {
	struct Node {
		int lc, rc, size;
		int home, index, weight, ans;
		int indextag, anstag;
	} a[MAXN];
	int root, size;
	void pushdown(int root) {
		if (a[root].indextag) {
			if (a[root].lc) {
				a[a[root].lc].index += a[root].indextag;
				a[a[root].lc].indextag += a[root].indextag;
			}
			if (a[root].rc) {
				a[a[root].rc].index += a[root].indextag;
				a[a[root].rc].indextag += a[root].indextag;
			}
			a[root].indextag = 0;
		}
		if (a[root].anstag) {
			if (a[root].lc) {
				a[a[root].lc].ans += a[root].anstag;
				a[a[root].lc].anstag += a[root].anstag;
			}
			if (a[root].rc) {
				a[a[root].rc].ans += a[root].anstag;
				a[a[root].rc].anstag += a[root].anstag;
			}
			a[root].anstag = 0;
		}
	}
	int rank(int value) {
		int now = root, ans = 0;
		while (now) {
			pushdown(now);
			if (value < a[now].index) ans++;
			if (value >= a[now].index) now = a[now].lc;
			else {
				ans += a[a[now].lc].size;
				now = a[now].rc;
			}
		}
		return ans;
	}
	int rbnk(int value) {
		int now = root, ans = 0;
		while (now) {
			pushdown(now);
			if (value <= a[now].index) ans++;
			if (value > a[now].index) now = a[now].lc;
			else {
				ans += a[a[now].lc].size;
				now = a[now].rc;
			}
		}
		return ans;
	}
	int rbnk(int now, int value) {
		int ans = 0;
		while (now) {
			pushdown(now);
			if (value <= a[now].index) ans++;
			if (value > a[now].index) now = a[now].lc;
			else {
				ans += a[a[now].lc].size;
				now = a[now].rc;
			}
		}
		return ans;
	}
	int new_node(int home, int value) {
		size++;
		a[size].ans = 0;
		a[size].anstag = 0;
		a[size].index = value;
		a[size].indextag = 0;
		a[size].home = home;
		a[size].weight = rand();
		a[size].size = 1;
		return size;
	}
	void update(int root) {
		a[root].size = 1;
		if (a[root].lc) a[root].size += a[a[root].lc].size;
		if (a[root].rc) a[root].size += a[a[root].rc].size;
	}
	int merge(int x, int y) {
		pushdown(x);
		pushdown(y);
		if (x == 0) return y;
		if (y == 0) return x;
		if (a[x].weight < a[y].weight) {
			a[x].rc = merge(a[x].rc, y);
			update(x);
			return x;
		} else {
			a[y].lc = merge(x, a[y].lc);
			update(y);
			return y;
		}
	}
	pair <int, int> split(int x, int cnt) {
		pushdown(x);
		if (cnt == 0) return make_pair(0, x);
		if (cnt == a[x].size) return make_pair(x, 0);
		if (cnt <= a[a[x].lc].size) {
			pair <int, int> tmp = split(a[x].lc, cnt);
			a[x].lc = tmp.second;
			update(x); tmp.second = x;
			return tmp;
		} else {
			pair <int, int> tmp = split(a[x].rc, cnt - a[a[x].lc].size - 1);
			a[x].rc = tmp.first;
			update(x); tmp.first = x;
			return tmp;
		}
	}
	void insert(int home, int value) {
		int cnt = rank(value);
		int point = new_node(home, value);
		pair <int, int> tmp = split(root, cnt);
		root = merge(merge(tmp.first, point), tmp.second);
	}
	int getmax(int root) {
		if (root == 0) return 0;
		pushdown(root);
		if (a[root].lc) return getmax(a[root].lc);
		else return a[root].index;
	}
	void puttag(int root, int value) {
		a[root].index -= value;
		a[root].indextag -= value;
		a[root].ans += 1;
		a[root].anstag += 1;
	}
	void Merge(int now) {
		if (now == 0) return;
		pushdown(now);
		if (a[now].lc) Merge(a[now].lc);
		if (a[now].rc) Merge(a[now].rc);
		a[now].lc = a[now].rc = 0;
		update(now);
		pair <int, int> tmp = split(root, rank(a[now].index));
		root = merge(merge(tmp.first, now), tmp.second);
	}
	void modify(int value) {
		pair <int, int> tmp = split(root, rbnk(value));
		int Max = getmax(tmp.second);
		puttag(tmp.first, value);
		pair <int, int> tnp = split(tmp.first, rbnk(tmp.first, Max));
		root = tmp.second;
		Merge(tnp.second);
		root = merge(tnp.first, root);
	}
	void getans(int root, int *ans) {
		pushdown(root);
		ans[a[root].home] = a[root].ans;
		if (a[root].lc) getans(a[root].lc, ans);
		if (a[root].rc) getans(a[root].rc, ans);
	}
	void getans(int *ans) {
		getans(root, ans);
	}
} PT;
pair <int, int> q[MAXN];
int ans[MAXN];
bool cmp(pair <int, int> x, pair <int, int> y) {
	if (x.second == y.second) return x.first < y.first;
	else return x.second > y.second;
}
int main() {
	//freopen("702F.in", "r", stdin);
	//freopen("702F.out", "w", stdout);
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(q[i].first), read(q[i].second);
	sort(q + 1, q + n + 1, cmp);
	int m; read(m);
	for (int i = 1; i <= m; i++) {
		int x; read(x);
		PT.insert(i, x);
	}
	for (int i = 1; i <= n; i++)
		PT.modify(q[i].first);
	PT.getans(ans);
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}