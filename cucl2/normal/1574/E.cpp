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
int hfuck, lfuck;
int hemp, lemp;
int cnth[1000005][2], cntl[1000005][2];
int cntd[2];
map<pair<int, int>, int> val;
mint mii[1000005];

void inline updh(int x, int c) {
	if (!cnth[x][0] && !cnth[x][1]) hemp += c;
	if (cnth[x][0] && cnth[x][1]) hfuck += c;
}

void inline updl(int x, int c) {
	if (!cntl[x][0] && !cntl[x][1]) lemp += c;
	if (cntl[x][0] && cntl[x][1]) lfuck += c;
}

void inline clear(int x, int y) {
	updh(x, -1); updl(y, -1);
	--cnth[x][(y + val[make_pair(x, y)]) & 1];
	--cntl[y][(x + val[make_pair(x, y)]) & 1];
	--cntd[(x + y + val[make_pair(x, y)]) & 1];
	val.erase(make_pair(x, y));
	updh(x, 1); updl(y, 1);
}

void inline make(int x, int y, int d) {
	updh(x, -1); updl(y, -1);
	++cnth[x][(y + d) & 1];
	++cntl[y][(x + d) & 1];
	++cntd[(x + y + d) & 1];
	val[make_pair(x, y)] = d;
	updh(x, 1); updl(y, 1);
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	mii[0] = 1;
	repi(i, 1000000) mii[i] = mii[i - 1] * 2;
	hemp = N; lemp = M;
	int lims = 0;
	repi(i, K) {
		int x, y, t; scanf("%d%d%d", &x, &y, &t);
		if (val.count(make_pair(x, y))) clear(x, y), --lims;
		if (~t) make(x, y, t), ++lims;
		mint ans = 0;
		if (!hfuck) ans += mii[hemp];
		if (!lfuck) ans += mii[lemp];
		if (!cntd[0]) ans -= 1;
		if (!cntd[1]) ans -= 1;
		printf("%d\n", ans);
	}
	return 0;
}