#pragma GCC optimize("O3,Ofast")
#pragma GCC target("avx2,popcnt")
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
	inline int gstr (char *s) { int r = 0; for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c, r++; *s = 0; return r; }
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

uint64_t asuf[200070];
uint64_t bsuf[200070];
char buf[200001];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int l1 = gstr(buf);
	asuf[0]=buf[0]-'0';
	rep1(i, l1-1) asuf[i]=(asuf[i-1]<<1)|(buf[i]-'0');
	iter(i, l1, l1+65) asuf[i]=asuf[i-1]<<1;
	int l2 = gstr(buf);
	bsuf[0]=buf[0]-'0';
	rep1(i, l2-1) bsuf[i]=(bsuf[i-1]<<1)|(buf[i]-'0');
	iter(i, l2, l2+65) bsuf[i]=bsuf[i-1]<<1;
	int q; gi(q);
	while(q--) {
		int p1, p2, l; gi(p1), gi(p2), gi(l);
		int ans = 0; p1--; p2--;
		while(l >= 64) {
			p1 += 64, p2 += 64; l -= 64;
			ans += __builtin_popcountll(asuf[p1]^bsuf[p2]);
		}
		p1 += 64; p2 += 64; 
		if(l) ans += __builtin_popcountll((asuf[p1]^bsuf[p2]) >> (64 - l));
		print(ans); pc('\n');
	}
}