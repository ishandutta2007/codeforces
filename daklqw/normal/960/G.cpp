#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 800010
#define int long long
const int Dollar1 = 998244353, G = 3, Ginv = (Dollar1 + 1) / G;
int lim, dig, rev[MAXN];
void init(int sz) {
	lim = 1; dig = 0;
	while (lim <= sz) lim <<= 1, ++dig;
	for (int i = 0; i != lim; ++i)
		rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (dig - 1);
}
inline int fastpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % Dollar1;
		a = a * a % Dollar1;
		b >>= 1;
	}
	return res;
}
void NTT(int * A, int type) {
	for (int i = 0; i != lim; ++i)
		if (i < rev[i])
			swap(A[i], A[rev[i]]);
	for (int mid = 1; mid != lim; mid <<= 1) {
		int Wn = fastpow(type == 1 ? G : Ginv, (Dollar1 - 1) / mid / 2);
		for (int k = 0; k != lim; k += (mid << 1)) {
			int W = 1;
			for (int l = 0; l != mid; ++l, W = W * Wn % Dollar1) {
				int X = A[l + k], Y = A[l + k + mid] * W % Dollar1;
				A[l + k] = (X + Y) % Dollar1;
				A[l + k + mid] = (X - Y + Dollar1) % Dollar1;
			}
		}
	}
	if (type == -1) {
		const int liminv = fastpow(lim, Dollar1 - 2);
		for (int i = 0; i != lim; ++i)
			(A[i] *= liminv) %= Dollar1;
	}
}
int A[MAXN], B[MAXN];
vector<int> solve(int l, int r) {
	if (l == r) {
		vector<int> res;
		res.push_back(l);
		res.push_back(1);
		return res;
	}
	int mid = l + r >> 1;
	vector<int> va = solve(l, mid), vb = solve(mid + 1, r);
	int sz = va.size() + vb.size() - 1;
	init(sz);
	for (int i = 0; i != lim; ++i) {
		if (i < va.size()) A[i] = va[i]; else A[i] = 0;
		if (i < vb.size()) B[i] = vb[i]; else B[i] = 0;
	}
	NTT(A, 1); NTT(B, 1);
	for (int i = 0; i != lim; ++i)
		(A[i] *= B[i]) %= Dollar1;
	NTT(A, -1);
	vector<int> res;
	for (int i = 0; i != sz; ++i)
		res.push_back(A[i]);
	return res;
}
int n, a, b;
signed main() {
	cin >> n >> a >> b;
	if (n == 1) {if (a == 1 && b == 1) puts("1"); else puts("0"); return 0;}
	vector<int> res = solve(0, n - 2);
	if (a + b - 2 > res.size()) { cout << 0 << endl; return 0; }
	int ans = res[a + b - 2];
	if (a < 1 || b < 1) { puts("0"); return 0; }
	for (int i = 2; i <= a + b - 2; ++i) (ans *= i) %= Dollar1;
	for (int i = 2; i <= a - 1; ++i) (ans *= fastpow(i, Dollar1 - 2)) %= Dollar1;
	for (int i = 2; i <= b - 1; ++i) (ans *= fastpow(i, Dollar1 - 2)) %= Dollar1;
	cout << ans << endl;
	return 0;
}