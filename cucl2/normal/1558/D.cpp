#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int jt = 998244353;
void inline add(int &a, int b) { a += b - jt; a += (a >> 31) & jt; }
void inline sub(int &a, int b) { a -= b; a += (a >> 31) & jt; }
void inline mul(int &a, int b) { a = (ll)a * b % jt; }
int inline Add(int a, int b) { return a + b >= jt ? a + b - jt : a + b; }
int inline Sub(int a, int b) { return a - b < 0 ? a - b + jt : a - b; }
int inline Mul(int a, int b) { return (ll)a * b % jt; }

int inline ksmii(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) mul(res, a);
		mul(a, a); b >>= 1;
	}
	return res;
}

int N, M;
int a[200005], b[200005], ai[200005];
int jc[400005], fjc[400005];

struct Fenwick {
	int dt[200005];
	void inline add(int a, int x) {
		while (a <= N) dt[a] += x, a += a & -a;
	}
	int inline sum(int a) {
		int res = 0;
		while (a) res += dt[a], a -= a & -a;
		return res;
	}
} bit;

void solve() {
	scanf("%d%d", &N, &M);
	repi(i, M) scanf("%d%d", a + i, b + i);
	int ch = N * 2 - 1;
	vector<int> ss;
	for (int i = M; i; --i) {
		int l = 0, r = N;
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if ((m - bit.sum(m)) < b[i]) l = m;
			else r = m;
		}
		ai[i] = r;
		if ((r + 1 - bit.sum(r + 1)) != (r - bit.sum(r))) --ch;
		bit.add(r, 1);
		ss.push_back(r);
	}
	for (int i : ss) bit.add(i, -1);
	printf("%d\n", Mul(jc[ch], Mul(fjc[N], fjc[ch - N])));
}

int main() {
	jc[0] = 1;
	repi(i, 400000) jc[i] = Mul(jc[i - 1], i);
	fjc[400000] = ksmii(jc[400000], jt - 2);
	for (int i = 400000; i; --i) fjc[i - 1] = Mul(fjc[i], i);
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}