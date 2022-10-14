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

struct rect {
	int x, y; ll a;
	const bool operator<(const rect other) const {
		return x < other.x;
	}
} r[1000006];
ll dp[1000006];
int qux[1000006]; ll quy[1000006];
int qh, qt;
inline double slo(const int& ax, const ll& ay, const int& bx, const ll& by) {
	return (double)(ay-by)/(ax-bx);
}

void add(const int& x, const ll& y) {
	while(qh != qt && slo(qux[qh-1], quy[qh-1], qux[qh], quy[qh]) <= slo(qux[qh], quy[qh], x, y)) qh--;
	qux[++qh] = x; quy[qh] = y;
}

ll query(const int& y) {
	while(qh != qt && slo(qux[qt], quy[qt], qux[qt+1], quy[qt+1]) > y) qt++;
	return quy[qt] - 1ll * qux[qt] * y;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; gi(n);
	rep1(i, n) gi(r[i].x), gi(r[i].y), gi(r[i].a);
	sort(r+1, r+n+1);
	dp[0] = 0; ll ans = 0;
	qux[0] = quy[0] = 0;
	rep1(i, n) {
		dp[i] = query(r[i].y) + 1ll*r[i].x*r[i].y - r[i].a;
		add(r[i].x, dp[i]);
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}