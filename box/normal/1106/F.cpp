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
const int MOD = 998244353;

template<typename T, int S>
struct mat {
	T dat[S][S];
	void init() { rep(i, S) rep(j, S) dat[i][j] = 0; }
	T* operator[](int a) { return dat[a]; }
	T const* operator[](int a) const { return dat[a]; }
	mat mult(const mat&b) const {
		mat ans; ans.init(); rep(i, S) rep(j, S) rep(k, S) ans[i][k]=(ans[i][k]+dat[i][j]*b[j][k])%998244352;
		return ans;
	}
};

void exgcd(ll a, ll b, ll&x, ll&y) {
	if(!b) x=1,y=0;
	else exgcd(b, a%b, y, x), y-=a/b*x;
}
ll sv(ll p, ll q) { ll x,y; exgcd(p,q,x,y); return (x%q+q)%q; }

using matt=mat<ll, 100>;

matt qpow(const matt& b, const ll&e) {
	if(e==1) return b;
	if(!(e&1)) return qpow(b.mult(b),e>>1);
	return qpow(b,e-1).mult(b);
}

int qpow(int b, int e) {
	int ans = 1;
	while(e) {
		if(e & 1) ans = 1ll * ans * b % MOD;
		b = 1ll * b * b % MOD;
		e >>= 1;
	}
	return ans;
}

ll bsgs(int base, int val) { // returns log_a(b)
	int t = sqrt(MOD)+1;
	map<int, int> ati;
	int cur = qpow(base, t), cv = cur;
	rep1(i, t-1) {
		ati[cur] = i;
		cur = 1ll*cur*cv%MOD;
	}
	cur = val;
	ll ans = MOD+1;
	rep(i, t) {
		if(ati.count(cur)) ans = min(ans, 1ll*t*ati[cur]-i);
		cur = 1ll*cur*base%MOD;
	}
	if(ans == MOD+1) return -1; 
	return ans;
}

ll discreteroot(ll k, ll a) {
	if(a == 0) return 0;
	ll t = qpow(3, k);
	ll y = bsgs(t, a);
	if(y == -1) return -1;
	return qpow(3, y);
} 

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k; cin >> k;
	matt tr; tr.init();
	rep(i, k-1) tr[i+1][i] = 1;
	rep(i, k) cin >> tr[0][i];
	matt v; v.init(); v[0][0] = 1;
	int n, m; cin >> n >> m;
	int ex = v.mult(qpow(tr, n - k))[0][0];
	cout << discreteroot(ex, m) << endl;
}