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

char buf[100005];
int mrp[256];
int tj[52];

int way[52][52];
int dp[50004], dp2[50004], dp3[50004];
int fac[50004], ifac[50004], inv[50004];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    gstr(buf);
	int n = strlen(buf)/2;
	rep(i, 26) mrp['a'+i] = i;
	rep(i, 26) mrp['A'+i] = 26+i;
	rep(i, 2*n) tj[mrp[buf[i]]]++;
	dp[0] = 1;
	rep(i, 52) {
		if(!tj[i]) continue;
		for(int v=n; tj[i]<=v; v--) dp[v] = (dp[v] + dp[v-tj[i]]) % MOD;
	}
	ifac[0] = fac[0] = 1;
	inv[1] = ifac[1] = fac[1] = 1;
	iter(i, 2, n+1) {
		inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
		fac[i] = 1ll * fac[i-1] * i % MOD;
		ifac[i] = 1ll * ifac[i-1] * inv[i] % MOD;
	}
	ll mult = 1ll * fac[n] * fac[n] % MOD;
	rep(i, 52) mult = mult * ifac[tj[i]] % MOD;
	rep(re, 52) {
		if(!tj[re]) continue;
		rep(v, tj[re]) dp2[v] = dp[v];
		iter(v, tj[re], n+1) dp2[v] = (MOD + dp[v] - dp2[v-tj[re]]) % MOD;
		rep(q, re) {
			if(!tj[q] || tj[re] + tj[q] > n) continue;
			rep(v, tj[q]) dp3[v] = dp2[v];
			iter(v, tj[q], n+1) dp3[v] = (MOD + dp2[v] - dp3[v-tj[q]]) % MOD;
			way[re][q] = 2 * mult * dp3[n - tj[re] - tj[q]] % MOD;
			way[q][re] = way[re][q];
		}
	}
	dp[n] = mult * dp[n] % MOD;
	int q; gi(q);
	while(q--) {
		int x, y; gi(x), gi(y);
		x--; y--;
		if(buf[x] == buf[y]) print(dp[n]), pc('\n');
		else print(way[mrp[buf[x]]][mrp[buf[y]]]), pc('\n');
	}
}