#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, l, r) for (int i = r; l <= i; --i)
 
using ll = long long;
using namespace std;
 
const int MOD = 1e9 + 7;
 
int add(int a, int b) {
	return a + b < MOD ? a + b : a + b - MOD;
} 
 
int sub(int a, int b) {
	return 0 <= a - b ? a - b : a - b + MOD;
}
 
int mul(int a, int b) {
	return 1LL * a * b % MOD;
}
 
int pt(int a, int b) {
	if (b == 0) return 1;
	if (b & 1) return mul(a, pt(a, b - 1));
	return pt(mul(a, a), b / 2);
}
 
int divi(int a, int b) {
	return 1LL * a * pt(b, MOD - 2) % MOD;
}
 
const int N = 2e5 + 100;
const int T = 1 << 18;
const int A = 107;
 
char s[N];
int pw[N];
 
struct nod {
	int len, st, nd, hash;
	nod() : len(0), st(0), nd(0), hash(0) {}
	nod(int _len, int _st, int _nd, int _hash) : len(_len), st(_st), nd(_nd), hash(_hash) {}
} tree[T + T];
 
nod combine(nod a, nod b) {
	if (!a.len) return b;
	if (!b.len) return a;
	if (a.nd && b.st) {
		int x = sub(a.hash, pw[a.len - 1]);
		int y = divi(sub(b.hash, 1), A);
		y = mul(y, pw[a.len - 1]);
		return nod(a.len + b.len - 2, a.len > 1 ? a.st : 0, b.len > 1 ? b.nd : 0, add(x, y));
	}
	return nod(a.len + b.len, a.st, b.nd, add(a.hash, mul(b.hash, pw[a.len])));	
}
 
nod query(int a, int b, int v = 1, int l = 0, int r = T - 1) {
	if (b < l || r < a) return nod();
	if (a <= l && r <= b) return tree[v];
	int m = (l + r) / 2;
	return combine(query(a, b, 2 * v, l, m), query(a, b, 2 * v + 1, m + 1, r));
}
 
int main() {
	pw[0] = 1;
	rep(i, 1, N - 1) pw[i] = mul(pw[i - 1], A);
	int n, q;
	scanf ("%d%s%d", &n, s + 1, &q);
	rep(i, 1, n) {
		if (s[i] == '0') tree[T + i] = nod(1, 0, 0, 0);
		if (s[i] == '1') tree[T + i] = nod(1, 1, 1, 1);
	}
	per(i, 1, T - 1) tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
	while (q--) {
		int a, b, l;
		scanf ("%d%d%d", &a, &b, &l);
		l--;
		nod x = query(a, a + l);
		nod y = query(b, b + l);
		if (x.len == y.len && x.hash == y.hash) puts("Yes");
		else puts("No");
	}
		
	return 0;
}