#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 998244353;
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
const int Matsize = 2;
struct mat {int a[Matsize][Matsize]; };
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
mat Cipher() {
	mat ans;
	memset(ans.a, 0, sizeof(ans.a));
	return ans;
}
mat Mat(int x) {
	mat ans;
	memset(ans.a, 0, sizeof(ans.a));
	for (int i = 0; i <= Matsize - 1; i++) {
		ans.a[i][i] = 1;
		if (i <= x) update(ans.a[i][x], 1);
	}
	return ans;
}
mat operator * (mat a, mat b) {
	mat ans;
	static ll tmp[Matsize][Matsize];
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i <= Matsize - 1; i++)
	for (int k = 0; k <= Matsize - 1; k++)
		if (a.a[i][k]) {
			for (int j = 0; j <= Matsize - 1; j++)
				tmp[i][j] += 1ll * a.a[i][k] * b.a[k][j];
		}
	for (int i = 0; i <= Matsize - 1; i++)
	for (int j = 0; j <= Matsize - 1; j++)
		ans.a[i][j] = tmp[i][j] % P;
	return ans;
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		mat sum;
	} a[MAXN * 2];
	int n, root, size;
	void update(int root) {
		a[root].sum = a[a[root].lc].sum * a[a[root].rc].sum;
	}
	void build(int &root, int l, int r, mat *v) {
		root = ++size;
		if (l == r) {
			a[root].sum = v[l];
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, v);
		build(a[root].rc, mid + 1, r, v);
		update(root);
	}
	void init(int x, mat *v) {
		n = x, root = size = 0;
		build(root, 1, n, v);
	}
	void modify(int root, int l, int r, int pos, mat d) {
		if (l == r) {
			a[root].sum = d;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= pos) modify(a[root].lc, l, mid, pos, d);
		else modify(a[root].rc, mid + 1, r, pos, d);
		update(root);
	}
	void modify(int pos, mat d) {
		modify(root, 1, n, pos, d);
	}
	mat query() {
		return a[root].sum;
	}
} ST;
struct info {
	int x, y, pos;
	bool a, b;
};
mat a[MAXN]; info b[MAXN];
int n, x[MAXN], v[MAXN], p[MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
bool cmp(info a, info b) {
	return 1ll * a.x * b.y < 1ll * b.x * a.y;
}
int main() {
	read(n);
	if (n == 1) {
		puts("0");
		return 0;
	}
	int tot = 0, inv = power(100, P - 2);
	for (int i = 1; i <= n; i++) {
		read(x[i]), read(v[i]), read(p[i]), p[i] = 100 - p[i];
		int tmp = 1ll * p[i] * inv % P;
		if (i != 1) {
			a[i - 1].a[0][0] = (P + 1 - tmp) % P;
			a[i - 1].a[1][0] = (P + 1 - tmp) % P;
			a[i - 1].a[0][1] = tmp;
			a[i - 1].a[1][1] = tmp;
			b[++tot] = (info) {x[i] - x[i - 1], v[i] + v[i - 1], i - 1, false, true};
			if (v[i] > v[i - 1]) b[++tot] = (info) {x[i] - x[i - 1], v[i] - v[i - 1], i - 1, true, true};
			if (v[i] < v[i - 1]) b[++tot] = (info) {x[i] - x[i - 1], v[i - 1] - v[i], i - 1, false, false};
		}
	}
	ST.init(n - 1, a);
	sort(b + 1, b + tot + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= tot; i++) {
		int pos = b[i].pos, timer = 1ll * b[i].x * power(b[i].y, P - 2) % P;
		mat tmp = a[pos];
		for (int j = 0; j <= 1; j++)
		for (int k = 0; k <= 1; k++)
			if (j != b[i].a || k != b[i].b) a[pos].a[j][k] = 0;
		ST.modify(pos, a[pos]);
		mat res = ST.query();
		int tp = 1ll * p[1] * inv % P, prob = 0;
		for (int j = 0; j <= 1; j++)
		for (int k = 0; k <= 1; k++)
			if (j) update(prob, 1ll * tp * res.a[j][k] % P);
			else update(prob, 1ll * (P + 1 - tp) * res.a[j][k] % P);
		update(ans, 1ll * timer * prob % P);
		a[pos] = tmp, a[pos].a[b[i].a][b[i].b] = 0;
		ST.modify(pos, a[pos]);
	}
	cout << ans << endl;
	return 0;
}