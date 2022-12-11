#include <bits/stdc++.h>

const int MAXN = 200010;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
int n;
int A[MAXN], W[MAXN];
LL rt[MAXN];
void mdfc(int x, int v) {
	for (; x <= n; x += x & -x) rt[x] += v;
}
LL qry(int x) {
	LL res = 0; for (; x; x &= x - 1) res += rt[x]; return res;
}
LL qry(int l, int r) { return qry(r) - qry(l - 1); }
int tr[MAXN];
void mdfv(int x, int v) {
	for (v -= mod; x <= n; x += x & -x) reduce(tr[x] += v);
}
int qryv(int x) {
	int res = 0; for (; x; x &= x - 1) reduce(res += tr[x] - mod);
	return res;
}
int qryv(int l, int r) {
	int x = qryv(r) - qryv(l - 1); return x + (x >> 31 & mod);
}
void add(int x, int v) {
	mdfc(x, v), mdfv(x, remod(mul(A[x], v)));
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int T; std::cin >> n >> T;
	for (int i = 1; i <= n; ++i) std::cin >> A[i], A[i] -= i;
	for (int i = 1; i <= n; ++i) std::cin >> W[i], add(i, W[i]);
	while (T --> 0) {
		int x, y;
		std::cin >> x >> y;
		if (x < 0)
			x = -x, add(x, y - W[x]), W[x] = y;
		else {
			int l = x, r = y, at = -1;
			LL sm = qry(l, r);
			while (l <= r) {
				int mid = l + r >> 1;
				if (qry(x, mid) * 2 >= sm) at = mid, r = mid - 1;
				else l = mid + 1;
			}
			l = x, r = y;
			int X = A[at];
			LL ans = qry(l, at) % mod * X - qryv(l, at);
			ans += qryv(at + 1, r) - qry(at + 1, r) % mod * X;
			std::cout << remod(ans) << '\n';
		}
	}
	return 0;
}