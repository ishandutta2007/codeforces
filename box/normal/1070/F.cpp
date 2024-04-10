
// Problem : F. Debate
// Contest : Codeforces - 2018-2019 ICPC, NEERC, Southern Subregional Contest (Online Mirror, ACM-ICPC Rules, Teams Preferred)
// URL : https://codeforces.com/problemset/problem/1070/F
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) { *s = __c; } *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) { x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; } return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) { qu[++ qr] = x % 10 + '0',  x /= 10; } while (qr) pc (qu[qr --]); }
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

vector<int> bob, alice, no;
char buf[5];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll ans = 0;
    int tot = 0;
    int n; gi(n);
    rep(i, n) {
    	gstr(buf); int k; gi(k);
    	if(buf[0] == buf[1]) {
    		if(buf[0] == '1') ans += k, tot++;
    		else no.pb(k);
    	}
    	else if(buf[0] == '1') alice.pb(k);
    	else bob.pb(k);
    }
    sort(all(alice), greater<int>());
    sort(all(bob), greater<int>());
    sort(all(no), greater<int>());
    int sa = tot, sb = tot;
    cerr << sa << ' ' << sb << ' ' << ans << endl;
    int k = min(bob.size(), alice.size());
    rep(i, k) {
    	if(2*(sa+1) >= tot+2 && 2*(sb+1) >= tot+2) {
    		sa++; sb++;
    		ans += alice[i] + bob[i];
    		tot += 2;
    	}
    }
    vector<pii> lump;
    iter(i, k, alice.size()) lump.pb({alice[i], 2});
    iter(i, k, bob.size()) lump.pb({bob[i], 1});
    iter(i, 0, no.size()) lump.pb({no[i], 0});
    sort(all(lump), greater<pii>());
    rep(i, lump.size()) {
    	int k = lump[i].fi;
    	int tp = lump[i].se;
    	if(tp == 2 && 2*(sa+1) >= tot+1 && 2*sb >= tot+1) {
    		sa++;
    		ans += k;
    		tot++;
    	}
    	if(tp == 1 && 2*(sa+0) >= tot+1 && 2*(sb+1) >= tot+1) {
    		sb++;
    		ans += k;
    		tot++;
    	}if(tp == 0 && 2*(sa+0) >= tot+1 && 2*(sb+0) >= tot+1) {
    		ans += k;
    		tot++;
    	}
    }
    print(ans);
}