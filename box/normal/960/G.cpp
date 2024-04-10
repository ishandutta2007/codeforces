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
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
	const int MOD = 998244353;

namespace poly {
	const int MOD = 998244353;
	const int NTTG = 3;
	
	int rev[524320];
	int minv[524320];
	int w[20][2][524320];
	
	int qpow(int b, int e) {
		int re=1;
		while(e){
			if(e&1)re=1ll*re*b%MOD;
			b=1ll*b*b%MOD;e>>=1;
		}
		return re;
	}
	
	void constructrev(int n) {
		for(int i=1, j=0; i < n; i++) {
			int bit=n>>1;
			for(;j&bit;bit>>=1)j^=bit;
			j^=bit; rev[i] = j;
		}
	}

	void constructroot(int n) {
		minv[1] = 1;
		iter(i, 2, n+1)
			minv[i]=1ll*(MOD-MOD/i)*minv[MOD%i]%MOD;
		for(int l=1; (1<<l)<=n; l++)
			rep(inv, 2) {
				int re = inv?qpow(minv[NTTG],(MOD-1)>>l):qpow(NTTG,(MOD-1)>>l);
				w[l][inv][0] = 1;
				rep1(i,(1<<(l-1))-1) w[l][inv][i] = 1ll*w[l][inv][i-1]*re%MOD;
			}
	}
	
	void ntt(int *v, int n, bool inv) {
		rep(i, n) if(i < rev[i]) swap(v[i], v[rev[i]]);
		for(int l=1;(1<<l)<=n;l++)
			for(int i=0;i<n;i+=(1<<l)) {
				int p=i+(1<<(l-1));
				iter(j, i, p) {
					int a=v[j],b=1ll*v[j+(1<<(l-1))]*w[l][inv][j-i]%MOD;
					v[j]=(a+b>=MOD?a+b-MOD:a+b);
					v[j+(1<<(l-1))]=(a<b?a+MOD-b:a-b);
				}
			}
		if(inv) rep(i, n) v[i] = 1ll*v[i]*minv[n]%MOD;
	}
	
	void mult(int *a, int as, int *b, int bs, int *o, bool construct, bool clean = 0, int th = 100000000) {
		int n = as+bs-1;
		while(n - (n & (-n))) n += (n & (-n));
		if(construct) constructroot(n);
		constructrev(n);
		ntt(a, n, 0); ntt(b, n, 0);
		rep(i, n) o[i] = 1ll*a[i]*b[i]%MOD;
		ntt(o, n, 1);
		iter(i, th, n) o[i] = 0;
		if(clean) rep(i, n) a[i] = b[i] = 0;
	}

	void cfn(int* a, int as, int *o) {
		static int tmp[524320];
		if(as == 1) { tmp[0] = a[0]; o[0] = qpow(a[0], MOD - 2); return; }
		cfn(a, (as+1)/2, o); int le = 0;
		while((1 << le) < (as << 1)) le++;
		constructrev(1 << le);
		rep(i, as) tmp[i] = a[i];
		iter(i, as, 1<<le) tmp[i] = o[i] = 0;
		ntt(tmp, 1<<le, 0); ntt(o, 1<<le, 0);
		rep(i, 1<<le) o[i] = 1ll * (MOD + (2 - 1ll * tmp[i] * o[i]) % MOD) * o[i] % MOD;
		ntt(o, 1<<le, 1);
		iter(i, as, 1<<le) o[i] = 0;
	}

	void deriv(int *a, int as, int *o) { rep1(i, as-1) { o[i-1] = 1ll * i * a[i] % MOD; } o[as-1] = 0; }
	void integ(int *a, int as, int *o) { for(int i=as-2; i>=0; i--) { o[i+1] = 1ll * minv[i+1] * a[i] % MOD; } o[0] = 0; }

	void ln(int *a, int as, int *o) {
		static int iv[524320]; 
		cfn(a, as, iv); 
		deriv(a, as, a);
		mult(iv, as, a, as, o, 0, 1, as);
		integ(o, as, o);
	}
	
	void exp(int *a, int as, int *o) {
		static int tmp[524320], tmp2[524320], tmp3[524320];
		if(as == 1) { o[0] = 1; return; }
		exp(a, (as+1)/2, o);
		rep(i, as) tmp[i] = o[i], tmp3[i] = 0; 
		ln(tmp, as, tmp3);
		rep(i, as) tmp3[i] = (MOD + a[i] - tmp3[i] + (i == 0)) % MOD, tmp2[i] = o[i];
		mult(tmp2, as, tmp3, as, o, 0, 1);
	}
	
	void pow(int *a, int as, int *o, int ex) {
		static int tmp[524320];
		ln(a, as, tmp);
		rep(i, as) tmp[i] = 1ll * tmp[i] * ex % MOD;
		exp(tmp, as, o);
	}
	
	void init(int n) { constructroot(n); }
}

int ones[524320];
int lnones[524320];
int imed[524320];
int imedk[524320];
int ans[524320];
int fac[524320];
int ifac[524320];

vector<int> make(int n, int k) {
     n++;
    int l = 1; while(l < (n << 1)) l <<= 1;
    int p = max(n, k);
    memset(fac, 0, sizeof fac);
    memset(ones, 0, sizeof ones);
    memset(lnones, 0, sizeof ones);
    memset(imed, 0, sizeof ones);
    memset(imedk, 0, sizeof ones);
    memset(ans, 0, sizeof ones);
    fac[0] = 1;
    rep1(i, p) fac[i] = 1ll * fac[i-1] * i % poly::MOD;
    poly::init(l);
    rep(i, n) ones[i] = 1;
    poly::ln(ones, n, lnones);
    rep(i, n) imed[i] = lnones[i+1];
    poly::pow(imed, n-1, imedk, k);
    ll re = poly::qpow(fac[k], poly::MOD-2);
    iter(i, k, n) ans[i] = 1ll * imedk[i-k] * re % poly::MOD;
    vector<int> ee(n);
    rep(i, n) ee[i] = (1ll * ans[i] * fac[i] % poly::MOD);
    return ee;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    auto X = make(n, a-1);
    auto Y = make(n, b-1);
    ifac[0] = 1;
    rep1(i, n+1) ifac[i] = 1ll * ifac[i-1] * poly::minv[i] % MOD;
    int ans = 0;
    rep1(i, n) ans = (ans + 1ll * X[i-1] * Y[n-i] % MOD * ifac[i-1] % MOD * ifac[n-i]) % MOD;
    cout << 1ll * ans * fac[n-1] % MOD << endl;
}