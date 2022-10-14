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

struct iP {
	ll num, den;
	iP(ll Num, ll Den) { 
		num = Num;
		den = Den;
		if(num == 0 && den == 0) {
			cout << -1 << endl;
			exit(0);
		}
		if(den == 0) {
			if(num < 0) num = -100000000000;
			if(num > 0) num =  100000000000;
			den = 1;
		}
		if(den < 0) den = -den, num = -num;
	}
	const bool operator<(const iP& o) const {
		if(den * o.den > 0) return num * o.den < o.num * den;
		return num * o.den > o.num * den;
	}
	const bool operator<=(const iP o) const {
		return num * o.den <= o.num * den;
	}
};

vector<pair<iP, int>> event;
iP zero(0, 1);
bool fail = 0;

#define y1 yyyyyyy1

int x1, y1, x2, y2;
void isc(int rx, int ry, int vx, int vy) {
	iP tX1(x1 - rx, vx), tX2(x2 - rx, vx);
	iP tY1(y1 - ry, vy), tY2(y2 - ry, vy);
	if(tX2 < tX1) swap(tX1, tX2);
	event.pb({tX1, 1});
	event.pb({tX2, -1});
	if(tY2 < tY1) swap(tY1, tY2);
	event.pb({tY1, 1});
	event.pb({tY2, -1});
	//if(x1 == 24) cout << rx << ' ' << ry << ' ' << vx << ' ' << vy << "  " << tX1.num << '/' << tX1.den << "  " << tX2.num << '/' << tX2.den << "  " << tY1.num << '/' << tY1.den << "  " << tY2.num << '/' << tY2.den << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n; gi(n);
	gi(x1), gi(y1), gi(x2), gi(y2);
	rep(i, n) {
		int rx, ry, vx, vy;
		gi(rx), gi(ry), gi(vx), gi(vy);
		isc(rx, ry, vx, vy);
	}
	sort(all(event));
	int tot = 2 * n, cur = 0;
	for(auto& k:event) {
		if(zero < k.fi && cur == tot) {
			cout << "0.0" << endl;
			return 0;
		}
		cur += k.se;
		if(zero <= k.fi && cur == tot) {
			cout << fixed << setprecision(20) << ((long double)(k.fi.num))/(k.fi.den) << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}