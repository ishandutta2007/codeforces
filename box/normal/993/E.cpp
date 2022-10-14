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

using cd=std::complex<double>;
const double PI=acos(-1.0);

int rev[524288];

void constructrev(int n) {
	for(int i=1, j=0; i < n; i++) {
		int bit = n >> 1;
		for(; j & bit; bit >>= 1) j ^= bit;
		j ^= bit;
		rev[i] = j;
	}
}

void fft(cd* v, int n, bool inv) {
	rep(i, n) if(i < rev[i]) swap(v[i], v[rev[i]]);
	for(int l=1; (1<<l)<=n; l++) {
		cd re(cos((2*inv-1)*2*PI/(1<<l)), sin((2*inv-1)*2*PI/(1<<l)));
		for(int i=0; i<n; i+=(1<<l)) {
			int p = i+(1<<(l-1));
			cd w(1.0);
			iter(j, i, p) {
				cd a = v[j], b = v[j+(1<<(l-1))]*w;
				v[j] = a+b; v[j+(1<<(l-1))] = a-b;
				w *= re;
			}
		}
	}
	if(inv) rep(i, n) v[i] /= n;
}

cd a1[524288], b1[524288];
cd a2[524288], b2[524288];
cd r1[524288], r2[524288], r3[524288];
int Av[200005], Bv[200005];
ll ans[524288];

void mult(const int& as, const int& bs, const int& C, const ll& P) {
	int n = as+bs-1;
	while(n - (n & (-n))) n += (n & (-n));
	constructrev(n);
	rep(i, as) {
		a1[i] = cd(Av[i] % C);
		a2[i] = cd(Av[i] / C);
	}
	rep(i, bs) {
		b1[i] = cd(Bv[i] % C);
		b2[i] = cd(Bv[i] / C);
	}
	fft(a1, n, 0); fft(a2, n, 0); fft(b1, n, 0); fft(b2, n, 0);
	rep(i, n) r1[i] = a1[i]*b1[i];
	rep(i, n) r2[i] = (a1[i]*b2[i]+a2[i]*b1[i]);
	rep(i, n) r3[i] = a2[i]*b2[i];
	fft(r1, n, 1); fft(r2, n, 1); fft(r3, n, 1);
	ll V = C*C%P;
	rep(i, n) ans[i] = (((ll)round(r1[i].real())%P)+C*((ll)round(r2[i].real()))%P+V*((ll)round(r3[i].real())%P))%P;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x; gi(n), gi(x);
	int cur = 0;
	Av[0]++;
	rep(i, n) {
		int v; gi(v);
		cur += (v < x);
		Av[cur]++;
	}
	rep(i, n+1) Bv[i] = Av[n-i];
	ll modu = (1ll*n*(n-1)>>1)+3;
	mult(n+1, n+1, (int)sqrt(modu), modu);
	ll r0 = 0;
	rep(i, n+1) r0 += ((1ll*Av[i]*(Av[i]-1))>>1);
	print(r0);
	rep1(i, n) {
		pc(' ');
		print(ans[n-i]);
	}
}