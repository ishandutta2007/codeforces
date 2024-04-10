// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

// begin fast read template by CYJian (source: https://www.luogu.com.cn/paste/i11c3ppx)

namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

// end fast read template by CYJian

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const ll MOD = 2305843009213693951;

using td=pair<int, ll>;

td v[400020];

td mer(td a, td b) {
	if(a.fi == b.fi) {
		ll k = a.se + b.se;
		k -= (k >= MOD) ? MOD : 0;
		return {a.fi, k};
	} return max(a, b);
}

// [l, r)

void init(int idx, int l, int r) {
	if(r - l == 0) return;
	if(r - l == 1) {
		v[idx] = {0, 0};
		return;
	}
	init(2*idx, l, (l+r)/2);
	init(2*idx+1, (l+r)/2, r);
	v[idx] = {0, 0};
}

void make(int idx, int l, int r, int i, const td& p) {
	if(r - l == 0) return;
	if(i < l || r <= i) return;
	if(r - l == 1) {
		v[idx] = mer(v[idx], p);
		return;
	}
	make(2*idx, l, (l+r)/2, i, p);
	make(2*idx+1, (l+r)/2, r, i, p);
	v[idx] = mer(v[2*idx], v[2*idx+1]);
}

td quer(int idx, int l, int r, int L, int R) {
	if(R <= l || r <= L || r - l == 0) return {0, 0};
	if(L <= l && r <= R) return v[idx];
	return mer(quer(2*idx, l, (l+r)/2, L, R), quer(2*idx+1, (l+r)/2, r, L, R));
}

int a[100005];
td PrefixWay[100005];
td SuffixWay[100005];

typedef int64_t ll;
typedef uint64_t ull;
ull mod_mul(ull a, ull b, ull c) {
    ll ret = a * b - c * ull(1.L / c * a * b);
    return ret + c * (ret < 0) - c * (ret >= (ll)c);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; gi(n);
	rep(i, n) gi(a[i]);
	init(1, 0, 100002);
	make(1, 0, 100002, 0, {0, 1});
	int tma = 0;
	rep(i, n) {
		PrefixWay[i] = quer(1, 0, 100002, 0, a[i]);
		make(1, 0, 100002, a[i], {PrefixWay[i].fi+1, PrefixWay[i].se});
		tma = max(tma, PrefixWay[i].fi+1);
	}
	ll tot = 0;
	rep(i, n) {
		if(PrefixWay[i].fi+1 != tma) continue;
		tot += PrefixWay[i].se;
		tot -= (tot >= MOD) ? MOD : 0;
	}
	init(1, 0, 100002);
	make(1, 0, 100002, 100001, {0, 1});
	for(int i=n-1; i>=0; i--) {
		SuffixWay[i] = quer(1, 0, 100002, a[i]+1, 100002);
		make(1, 0, 100002, a[i], {SuffixWay[i].fi+1, SuffixWay[i].se});
	}
	rep(i, n) {
		if(PrefixWay[i].fi + SuffixWay[i].fi + 1 != tma) pc('1');
		else if(mod_mul(PrefixWay[i].se, SuffixWay[i].se, MOD) != tot) pc('2');
		else pc('3');
	}
}