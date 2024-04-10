#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
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
struct vec {int a[2]; };
struct mat {int a[2][2]; };
int n, m, P; ll k;
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
vec operator * (vec x, mat y) {
	vec ans;
	ans.a[0] = (1ll * x.a[0] * y.a[0][0] + 1ll * x.a[1] * y.a[1][0]) % P;
	ans.a[1] = (1ll * x.a[0] * y.a[0][1] + 1ll * x.a[1] * y.a[1][1]) % P;
	return ans;
}
mat operator * (mat x, mat y) {
	mat ans;
	ans.a[0][0] = (1ll * x.a[0][0] * y.a[0][0] + 1ll * x.a[0][1] * y.a[1][0]) % P;
	ans.a[0][1] = (1ll * x.a[0][0] * y.a[0][1] + 1ll * x.a[0][1] * y.a[1][1]) % P;
	ans.a[1][0] = (1ll * x.a[1][0] * y.a[0][0] + 1ll * x.a[1][1] * y.a[1][0]) % P;
	ans.a[1][1] = (1ll * x.a[1][0] * y.a[0][1] + 1ll * x.a[1][1] * y.a[1][1]) % P;
	return ans;
}
mat make(int x, int y) {
	mat ans;
	ans.a[0][0] = 0, ans.a[0][1] = x;
	ans.a[1][0] = 1, ans.a[1][1] = y;
	return ans;
}
mat unit() {
	mat ans;
	ans.a[0][0] = ans.a[1][1] = 1;
	ans.a[1][0] = ans.a[0][1] = 0;
	return ans;
}
mat power(mat a, ll x) {
	if (x == 0) return unit();
	mat tmp = power(a, x / 2);
	if (x % 2 == 0) return tmp * tmp;
	else return tmp * tmp * a;
}
struct SegmentTree {
	struct Node {
		int lc, rc;
		mat sum;
	} a[MAXN * 2];
	int n, root, size;
	void build(int &root, int l, int r, int *c) {
		root = ++size;
		if (l == r) {
			a[root].sum = make(c[l - 1], c[l]);
			return;
		}
		int mid = (l + r) / 2;
		build(a[root].lc, l, mid, c);
		build(a[root].rc, mid + 1, r, c);
		a[root].sum = a[a[root].lc].sum * a[a[root].rc].sum;
	}
	void init(int x, int *c) {
		n = x;
		build(root, 1, n, c);
	}
	mat query(int root, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return a[root].sum;
		int mid = (l + r) / 2;
		if (mid >= qr) return query(a[root].lc, l, mid, ql, qr);
		else if (mid + 1 <= ql) return query(a[root].rc, mid + 1, r, ql, qr);
		else return query(a[root].lc, l, mid, ql, mid) * query(a[root].rc, mid + 1, r, mid + 1, qr);
	}
	mat query(int l, int r) {
		return query(root, 1, n, l, r);
	}
} ST;
int a[MAXN];
pair <ll, int> b[MAXN];
int query(ll x) {
	return a[(x - 1) % n];
}
mat query(ll l, ll r) {
	mat ans = unit();
	if (l > r) return ans; l--, r--;
	r -= (l - 1) / n * n;
	l -= (l - 1) / n * n;
	if (r <= n) return ST.query(l, r);
	int x = r % n; if (x == 0) x = n;
	ans = ans * ST.query(l, n) * power(ST.query(1, n), (r - x) / n - 1) * ST.query(1, x);
	return ans;
}
int main() {
	read(k), read(P), read(n);
	if (k <= 1) {
		cout << k % P << endl;
		return 0;
	}
	for (int i = 0; i <= n - 1; i++)
		read(a[i]); a[n] = a[0];
	ST.init(n, a);
	read(m);
	for (int i = 1; i <= m; i++)
		read(b[i].first), read(b[i].second), b[i].first++;
	b[++m] = make_pair(2e18, 0);
	sort(b + 1, b + m + 1);
	b[0] = make_pair(1, a[0]);
	vec ans = (vec) {0, 1};
	for (int i = 1; i <= m; i++) {
		if (k < b[i].first) {
			if (k == b[i - 1].first) {
				cout << ans.a[1] << endl;
				return 0;
			}
			ans = ans * make(b[i - 1].second, query(b[i - 1].first + 1)) * query(b[i - 1].first + 2, k);
			cout << ans.a[1] << endl;
			return 0;
		}
		if (b[i].first == b[i - 1].first + 1) ans = ans * make(b[i - 1].second, b[i].second);
		else ans = ans * make(b[i - 1].second, query(b[i - 1].first + 1))
				* query(b[i - 1].first + 2, b[i].first - 1)
				* make(query(b[i].first - 1), b[i].second);
	}
	return 0;
}