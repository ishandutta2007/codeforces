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

template<typename T, int S>
struct mat {
	T dat[S][S];
	void init() { rep(i, S) rep(j, S) dat[i][j] = 0; }
	T* operator[](int a) { return dat[a]; }
	T const* operator[](int a) const { return dat[a]; }
	mat mult(const mat&b) const {
		mat ans; ans.init(); rep(i, S) rep(j, S) rep(k, S) ans[i][k]=(ans[i][k]+dat[i][j]*b[j][k])%MOD;
		return ans;
	}
};

using matt=mat<ll, 83>;

matt qpow(const matt& b, const ll&e) {
	if(e==1) return b;
	if(!(e&1)) return qpow(b.mult(b),e>>1);
	return qpow(b,e-1).mult(b);
}

int p2[42];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n; int k; gi(n), gi(k);
	if(n==1) {
		pc('1');
		return 0;
	}
	matt v; v.init();
	p2[0] = 1;
	rep1(i, k+1) p2[i] = (p2[i-1]<<1)%MOD;
	v[0][0] = 1;
	rep(i, k+1) v[i+1][k+i+2] = 1;
	rep(i, k+1)
		rep(j, i+1) {
			if(!(i|j)) v[k+2][k+2] = 1;
			else v[k+i+2][k+j+2] = (v[k+i+1][k+j+1]+v[k+i+1][k+j+2])%MOD;
			v[k+i+2][j+1] = 1ll*v[k+i+2][k+j+2]*p2[i-j]%MOD;
		}
	rep1(i, 2*k+2) v[0][i] = v[2*k+2][i];
	matt i; i.init();
	i[0][0] = i[1][0] = 1;
	rep(r, k+1) i[k+r+2][0] = 1;
	print(qpow(v,n-1).mult(i)[0][0]);
}