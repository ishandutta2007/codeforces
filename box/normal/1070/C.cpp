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

class SST {
public:
	int dep; ll sum, price; // sum: # cores in segement, price: price to buy all cores in segement
	SST* ch[2];
	SST(int dep) : dep(dep), sum(0), price(0) {
		ch[0] = nullptr;
		ch[1] = nullptr;
	}
	void inc(int val, int diff) {
		sum += diff;
		price += 1ll*val*diff;
		if (!dep) return;
		bool cv = val & (1 << (dep - 1));
		if (!ch[cv]) ch[cv] = new SST(dep - 1);
		ch[cv]->inc(val, diff);
	}
	ll irank(int rem, ll curp) {
		if (!rem || !dep) return curp+min(1ll*rem,sum)*price/sum;
		ll left = 0;
		if (ch[0]) left = ch[0]->sum;
		if (rem <= left) return ch[0]->irank(rem, curp);
		else return (ch[1] ? (ch[1]->irank(rem - left, curp + (ch[0]?(ch[0]->price):0))) : (curp + (ch[0]?(ch[0]->price):0)));
	}
	inline ll irank(int cores) { return irank(cores, 0); }
};

SST* v;

struct event {
	int day, cores, price;
	const bool operator<(const event o) const {
		return day < o.day;
	} 
} ev[400005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    v = new SST(22);
	int n, k, m; gi(n), gi(k), gi(m);
	rep(i, m) {
		int l, r, c, p; gi(ev[2*i].day), gi(ev[2*i+1].day), gi(ev[2*i].cores), gi(ev[2*i].price);
		ev[2*i+1].day++; ev[2*i+1].cores = -ev[2*i].cores; ev[2*i+1].price = ev[2*i].price;
	}
	sort(ev, ev+2*m);
	int pt = 0; ll tco = 0;
	rep1(i, n) {
		while(pt != 2*m && ev[pt].day == i) {
			v->inc(ev[pt].price, ev[pt].cores);
			pt++;
		}
		tco += v->irank(k);
	}
	print(tco);
}