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
#define it iterator

using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;
vector<vector<int>> xw = 
{{337, 149, 47, 293, 11, 409, 79, 89, 23},
 {271, 457, 347, 577, 163, 157, 433},
 {613, 547, 241, 239, 331, 617, 101},
 {41, 229, 487, 179, 31, 431, 181, 191},
 {311, 131, 227, 17, 97, 13, 167, 601},
 {233, 607, 443, 193, 439, 313, 401},
 {349, 19, 83, 113, 73, 283, 449, 151},
 {419, 379, 467, 61, 173, 103, 569}, 
 {503, 593, 397, 359, 277, 7, 257},
 {139, 461, 491, 353, 5, 251, 37, 29},
 {499, 389, 373, 263, 269, 599, 197},
 {521, 109, 2, 619, 67, 421, 317, 587},
 {541, 557, 523, 281, 367, 53, 479},
 {307, 199, 211, 383, 59, 571, 563},
 {463, 509, 3, 71, 43, 127, 223, 137, 107}};
ll ask(ll x) {
	cout << "? " << x << endl;
	ll v; cin >> v; return v;
	//return __gcd(x, 1ll<<22);
}
signed main() {
    int t; cin >> t;
    while(t--) {
    	vector<int> prbpr;
    	for(const vector<int>& t:xw) {
    		ll pr = 1;
    		for(const int& j:t) pr *= j;
    		ll ans = ask(pr);
    		for(const int& j:t) if(ans % j == 0) prbpr.pb(j);
    	}
    	int ans = 1;
    	vector<pair<ll,ll>> jj;
    	for(const int& v:prbpr) {
    		int d = 1;
    		while(1ll * d * v < 1000000000) d *= v;
    		jj.pb({d,v});
    	}
    	while(jj.size()) {
    		if(jj.size() >= 2) {
    			auto x=jj.back();
    			jj.pop_back();
    			auto y=jj.back();
    			jj.pop_back();
    			ll res = ask(x.fi*y.fi);
    			int cn1=0; while(res%x.se==0) cn1++,res/=x.se;
    			int cn2=0; while(res%y.se==0) cn2++,res/=y.se;
    			ans *= cn1+1; ans *= cn2+1;
    		} else {
    			auto x=jj.back();
    			jj.pop_back();
    			ll res = ask(x.fi);
    			int cn1=0; while(res%x.se==0) cn1++,res/=x.se;
    			ans *= cn1+1;
    		}
    	}
    	cout << "! " << max(ans*2,ans+7) << endl;
    }
}