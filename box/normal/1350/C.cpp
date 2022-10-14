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
} using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

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

bool prime[200005];
int primes[300000]; int cnt;
int ex[4000006], bs[4000006], tot[4000006];
ll g[4000006];
void sve(int n) {
	g[1] = 1;
	iter(i, 2, n+1) {
		if(!bs[i]) {
			prime[i] = 1;
			primes[cnt++] = i;
			ex[i] = 1; bs[i] = tot[i] = i;
			g[i] = 2*i-1;
		}
		for(int j=0; j<cnt && i*primes[j]<=n; j++) {
			int v = i*primes[j];
			if(i%primes[j]) {
				bs[v] = tot[v] = primes[j]; ex[v] = 1;
				g[v] = g[i]*(2*primes[j]-1);
			} else {
				bs[v] = primes[j];
				tot[v] = tot[i]*primes[j];
				ex[v] = ex[i]+1;
				g[v] = g[v/tot[v]]*(ex[v]*(tot[v]-tot[v]/bs[v])+tot[v]);
				break;
			}
		}
	}
}

int mr[200005];
int mr2[200005];
int buf[200005];

ll qpow(int b, int e) {
	ll ans = 1;
	while(e) {
		if(e & 1) ans = 1ll * ans * b;
		b = 1ll * b * b;
		e >>= 1;
	}
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    sve(200001);
	int n; gi(n);
	memset(mr, 0x3f, sizeof mr);
	memset(mr2, 0x3f, sizeof mr2);
	rep(i, 200001) buf[i] = n;
	rep(i, n) {
		int v; gi(v);
		map<int, int> pf;
		while(v != 1) {
			pf[bs[v]]++;
			v /= bs[v];
		}
		for(auto& k:pf) {
			buf[k.fi]--;
			if(mr[k.fi] >= k.se) {
				mr2[k.fi] = mr[k.fi];
				mr[k.fi] = k.se;
			} else mr2[k.fi] = min(mr2[k.fi], k.se);
		}
	}
	ll ans = 1;
	rep(i, 200001) {
		if(buf[i] == 1) mr2[i] = mr[i];
		else if(buf[i] > 1) continue;
		ans = ans * qpow(i, mr2[i]);
	}
	print(ans);
}