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

int qpow(int b, int e, int p) {
    int ans = 1;
    while(e) {
        if(e & 1) ans = 1ll * ans * b % p;
        b = 1ll * b * b % p;
        e >>= 1;
    }
    return ans;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= qpow (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

int cztpol[1<<20];
int ans[1<<20];

namespace mootootoo {
    using cd=std::complex<double>;
    const double PI=acos(-1.0);

    int rev[1<<20];

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
				long double ag = (2*inv-1)*2*PI/(1<<l);
				cd re(cos(ag), sin(ag));
                    for(int i=0; i<n; i+=(1<<l)) {
                            int p = i+(1<<(l-1));
							cd cur(1.0);
                            iter(j, i, p) {
                                    cd a = v[j], b = v[j+(1<<(l-1))]*cur;
                                    v[j] = a+b; v[j+(1<<(l-1))] = a-b;
									cur *= re;
                            }
                    }
            }
            if(inv) rep(i, n) v[i] /= n;
    }

    cd a1[1<<19], b1[1<<19];
    cd a2[1<<19], b2[1<<19];
    cd r1[1<<19], r2[1<<19], r3[1<<19];
    int Av[1<<19], Bv[1<<19];
    ll ans[1<<19];

    void mult(const int& as, const int& bs, const int& C, const int& P) {
            int n = as+bs-1;
			memset(a1, 0, sizeof a1);
			memset(b1, 0, sizeof b1);
			memset(a2, 0, sizeof a2);
			memset(b2, 0, sizeof b2);
			memset(r1, 0, sizeof r1);
			memset(r2, 0, sizeof r2);
			memset(r3, 0, sizeof r3);
			memset(ans, 0, sizeof ans);
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
            int V = C*C%P;
            rep(i, n) ans[i] = (((ll)round(r1[i].real())%P)+C*((ll)round(r2[i].real()))%P+V*((ll)round(r3[i].real())%P))%P;
    }
}

int res[1<<20];
int cpp[1<<20];
int icpp[1<<20];

void czt(int n, int c, int m, int p) {
    int th = max(m, n);
    int ic = qpow(c, p-2, p);
    cpp[0] = icpp[0] = 1;
    rep1(i, 2*th) {
    	cpp[i] = 1ll * cpp[i-1] * c % p;
    	icpp[i] = 1ll * icpp[i-1] * ic % p;
    }
    rep1(i, 2*th) {
    	cpp[i] = 1ll * cpp[i-1] * cpp[i] % p;
    	icpp[i] = 1ll * icpp[i-1] * icpp[i] % p;
    }
	memset(mootootoo::Av, 0, sizeof mootootoo::Av);
	memset(mootootoo::Bv, 0, sizeof mootootoo::Bv);
	memset(mootootoo::ans, 0, sizeof mootootoo::ans);
	rep(i, 2*th) mootootoo::Av[i] = (i == 0 ? 1 : cpp[i-1]);
	rep(i, n) {
		int s = cztpol[i];
		mootootoo::Bv[th-1-i] = 1ll * s * (i == 0 ? 1 : icpp[i-1]) % p;
	}
	mootootoo::mult(2*th, 2*th, 1<<10, p);
	rep(i, m) ans[i] = 1ll * mootootoo::ans[th-1+i] * (i == 0 ? 1 : icpp[i-1]) % p;
}

char s1[1<<20], s2[1<<20];

void attempt(int n, int p) {
	int g = generator(p);
	rep(i, n) cztpol[i] = (p + s1[i] - s2[i]) % p;
	czt(n, g, p, p);
	rep(i, p) {
		int k = qpow(g, i, p);
		if(ans[i] == 0 && k != 1 && k != p-1) {
			cout << p << ' ' << k << endl;
			exit(0);
		}
	}
}

int main() {
	int n, m; gi(n), gi(m);
	gstr(s1); gstr(s2);
	attempt(n, 100003);
	attempt(n, 100019);
	attempt(n, 100043);
    attempt(n, 100049);
    attempt(n, 100057);
    attempt(n, 100069);
}