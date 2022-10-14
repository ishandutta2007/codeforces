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

int qpow(int b, int e) {
	int ans = 1;
	while(e) {
		if(e & 1) ans = 1ll * ans * b % MOD;
		b = 1ll * b * b % MOD;
		e >>= 1;
	}
	return ans;
}

constexpr int thr = 100000;
int primes[300000]; int cnt;
ll mu[thr+5], phi[thr+5];
void init(int n) {
	mu[1] = phi[1] = 1;
	iter(i, 2, n+1) {
		if(!phi[i]) {
			primes[cnt++] = i;
			mu[i] = -1;
			phi[i] = i - 1;
		}
		for(int j=0; j<cnt && i*primes[j]<=n; j++) {
			int v = i*primes[j];
			if(i%primes[j]) {
				mu[v] = -mu[i];
				phi[v] = phi[i]*phi[primes[j]];
			} else {
				mu[v] = 0;
				phi[v] = phi[i]*primes[j];
				break;
			}
		}
	}
}

vector<int> divisors[100005];
int E[100005], n;

int f(int i, int j) {
	int ans = 0;
	for(int& d:divisors[i/j]) ans = (ans + 1ll * (MOD + mu[d]) * (n / (j * d))) % MOD;
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
	init(n+1);
	rep1(i, n)
		for(int j=i; j<=n; j+=i)
			divisors[j].pb(i);
	E[1] = 1; int s = 1;
	iter(i, 2, n+1) {
		int sm = n;
		for(int& j:divisors[i]) if(j != i) sm = (sm + 1ll * f(i, j) * E[j]) % MOD;
		E[i] = 1ll * sm * qpow(n - n / i, MOD - 2) % MOD;
		s = (s + E[i]) % MOD;
	}
	cout << 1ll * s * qpow(n, MOD - 2) % MOD << endl;
}