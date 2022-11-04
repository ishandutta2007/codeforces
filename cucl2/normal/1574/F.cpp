#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

template <int jt> struct ModInt {
	int x;
	ModInt(int v = 0) { x = v; fix(); }
	template <class T> ModInt(const T &v) { x = v % jt; fix(); }
	void inline fix() { if (x < -jt || x >= jt) x %= jt; if (x < 0) x += jt; }
	operator int() const { return x; }
	ModInt inline operator - () { return -x; }
	ModInt inline &operator += (const ModInt &b) { x += b.x - jt; return x += (x >> 31) & jt, *this; }
	ModInt inline &operator -= (const ModInt &b) { x -= b.x; return x += (x >> 31) & jt, *this; }
	ModInt inline &operator *= (const ModInt &b) { return x = (ll)x * b.x % jt, *this; }
	ModInt inline &operator /= (const ModInt &b) { return *this *= b.inv(); }
	#define MakeOper(P) friend ModInt inline operator P (ModInt a, const ModInt &b) { return a P## = b; } \
	template <class T> friend ModInt inline operator P (ModInt a, const T &b) { return a P## = b; } \
	template <class T> friend ModInt inline operator P (const T &a, const ModInt &b) { return ModInt(a) P## = b; }
	MakeOper(+) MakeOper(-) MakeOper(*) MakeOper(/)
	#undef MakeOper
	friend ModInt inline ksmii(ModInt a, int b) { ModInt res = 1; for (; b; a *= a, b >>= 1) if (b & 1) res *= a; return res; }
	ModInt inline inv() const { return ksmii(*this, jt - 2); }
};
const int jt = 998244353;
typedef ModInt<jt> mint;

int N, M, K;
int nxt[300005], deg[300005];
bool ban[300005], lgl[300005];
vector<vector<int> > ls;
map<int, int> cln;
vector<pair<int, int> > tran;
mint dp[300005];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	repi(i, N) {
		int cs; scanf("%d", &cs);
		int lst = -1;
		vector<int> cc;
		rep(i, cs) {
			int x; scanf("%d", &x);
			cc.push_back(x);
			if (~lst) nxt[lst] = x;
			lst = x;
		}
		ls.push_back(cc);
	}
	rep(i, N) rep(j, SZ(ls[i]) - 1) if (nxt[ls[i][j]] != ls[i][j + 1]) {
		ban[ls[i][j]] = 1;
		ban[ls[i][j + 1]] = 1;
	}
	repi(i, K) ++deg[nxt[i]];
	repi(i, K) if (!deg[i]) {
		for (int j = i; j; j = nxt[j]) {
			if (lgl[j]) {
				ban[j] = 1;
				break;
			}
			lgl[j] = 1;
		}
	}
	repi(i, K) if (!deg[i]) {
		bool ok = 1;
		int len = 0;
		for (int j = i; j; j = nxt[j]) {
			if (ban[j]) {
				ok = 0;
				break;
			}
			++len;
		}
		if (ok) ++cln[len];
	}
	for (auto &it : cln) tran.push_back(it);
	dp[0] = 1;
	repi(i, M) {
		for (auto &j : tran) if (j.first <= i) dp[i] += dp[i - j.first] * j.second;
	}
	printf("%d\n", dp[M]);
	return 0;
}