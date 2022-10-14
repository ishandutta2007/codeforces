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

typedef vector<int> vl;

namespace simonMTT {
	typedef complex<double> C;
	typedef vector<double> vd;
	typedef vector<int> vi;
	#define sz(x) (x.size())

	void fft(vector<C>& a) {
		int n = sz(a), L = 31 - __builtin_clz(n);
		static vector<complex<double>> R(2, 1);
		static vector<C> rt(2, 1);  // (^ 10% faster if double)
		for (static int k = 2; k < n; k *= 2) {
			R.resize(n); rt.resize(n);
			auto x = polar(1.0, acos(-1.0) / k);
			iter(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
		}
		vi rev(n);
		iter(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
		iter(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int k = 1; k < n; k *= 2)
			for (int i = 0; i < n; i += 2 * k) iter(j,0,k) {
				// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
				auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
				C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
				a[i + j + k] = a[i + j] - z;
				a[i + j] += z;
			}
	}

	template<int M>
	vl convMod(const vl &a, const vl &b) {
		if (a.empty() || b.empty()) return {};
		vl res(sz(a) + sz(b) - 1);
		int B=32-__builtin_clz(sz(res)), n=1<<B, cut=(1<<15);
		vector<C> L(n), R(n), outs(n), outl(n);
		iter(i,0,sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
		iter(i,0,sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
		fft(L), fft(R);
		iter(i,0,n) {
			int j = -i & (n - 1);
			outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
			outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
		}
		fft(outl), fft(outs);
		iter(i,0,sz(res)) {
			ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
			ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
			res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
		}
		return res;
	}
}

namespace poly {
	const int MOD = 1000000007;
	const int NTTG = 3;
	
	int qpow(int b, int e) {
		int re=1;
		while(e){
			if(e&1)re=1ll*re*b%MOD;
			b=1ll*b*b%MOD;e>>=1;
		}
		return re;
	}

	vl cfn(const vl& a) {
		if(a.size() == 1) return vl({qpow(a[0], MOD-2)});
		vl cpy = a; cpy.resize((a.size()+1)/2);
		vl res = cfn(cpy);
		vl tmp = simonMTT::convMod<MOD>(a, res); tmp.resize(a.size());
		for(int&i:tmp) i = (MOD - i) % MOD;
		tmp[0] = (tmp[0] + 2) % MOD;
		tmp = simonMTT::convMod<MOD>(tmp, res); tmp.resize(a.size());
		return tmp;
	}

	vl deriv(const vl& a) {
		vl ans(a.size()-1);
		rep1(i, a.size()-1) ans[i-1] = 1ll * i * a[i] % MOD;
		return ans;
	}

	vl integr(const vl& a) {
		vl ans(a.size()+1);
		rep(i, a.size()) ans[i+1] = 1ll * qpow(i+1, MOD-2) * a[i] % MOD;
		return ans;
	}

	vl ln(const vl& a) {
		vl iv = cfn(a); 
		vl o = simonMTT::convMod<MOD>(iv, deriv(a));
		o.resize(a.size());
		return integr(o);
	}

	vl pow(const vl& a, int k) {
		vl b = a;
		vl ans(a.size()); ans[0] = 1;
		while(k) {
			if(k & 1) {
				ans = simonMTT::convMod<MOD>(ans, b);
				ans.resize(a.size());
			}
			b = simonMTT::convMod<MOD>(b, b);
			b.resize(a.size());
			k >>= 1;
		}
		return ans;
	}
}

int fac[524320];

vl solve(int l, int r) {
	if(l == r) return vl({1, poly::MOD-l});
	return simonMTT::convMod<poly::MOD>(solve(l, (l+r)/2), solve((l+r)/2+1, r));
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; gi(n), gi(k);
	k--;
	fac[0] = 1; rep1(i, max(n,k)+1) fac[i] = 1ll * fac[i-1] * i % poly::MOD;
	vl ans(n+1);
	if(k == 0) {
		ans[0] = 1;
	}
	else if(n-k+1>0) {
		vl q = solve(1, k); q.resize(n-k+1);
		q = poly::cfn(q);
		rep(i, n-k+1) ans[i+k] = q[i];
	}
	int sum = 0;
	rep1(s, n) {
		ll st = ans[n-s];
		st = st * s % poly::MOD;
		st = st * fac[n-1] % poly::MOD;
		st = st * poly::qpow(1ll * fac[s-1] * fac[n-s] % poly::MOD, poly::MOD-2) % poly::MOD;
		sum = (sum + st) % poly::MOD;
	}
	int s2 = 0;
	rep(i, n) {
		int w; gi(w);
		s2 = (s2 + w) % poly::MOD;
	}
	print(1ll * s2 * sum % poly::MOD);
}