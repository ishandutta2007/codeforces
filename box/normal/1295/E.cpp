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
const int MOD = 1000000007;

ll allNo[800005], allYes[800005], minCostPrefix[800005];
ll av[200005];

// [l, r)

void init(int idx, int l, int r) {
	if(r - l == 0) return;
	if(r - l == 1) {
		allYes[idx] = av[l];
		return;
	}
	init(2*idx, l, (l+r)/2);
	init(2*idx+1, (l+r)/2, r);
	allYes[idx] = allYes[2*idx] + allYes[2*idx+1];
}

void forceYes(int idx, int l, int r, int i) {
	if(r - l == 0) return;
	if(i < l || r <= i) return;
	if(r - l == 1) {
		allNo[idx] = av[l];
		allYes[idx] = 0;
		return;
	}
	forceYes(2*idx, l, (l+r)/2, i);
	forceYes(2*idx+1, (l+r)/2, r, i);
	allNo[idx] = allNo[2*idx] + allNo[2*idx+1];
	allYes[idx] = allYes[2*idx] + allYes[2*idx+1];
	minCostPrefix[idx] = min(minCostPrefix[2*idx] + allNo[2*idx+1], allYes[2*idx] + minCostPrefix[2*idx+1]);
}

int p[200005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; gi(n);
	rep(i, n) {
		gi(p[i]);
		p[i]--;
	}
	rep(i, n) gi(av[p[i]]);
	init(1, 0, n);
	ll ans = 1000000000000000000;
	rep(i, n-1) {
		forceYes(1, 0, n, p[i]);
		ans = min(ans, minCostPrefix[1]);
	}
	print(ans);
}