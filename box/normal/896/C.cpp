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
#define int ll
using ll=long long;
using pii=pair<int, int>;
//#define int ll

int qpow(ll b, int e, const int& MOD) {
	b %= MOD; int ans = 1;
	while(e) {
		if(e & 1) ans = ans * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	}
	return ans;
}

struct val {
	int l;
	mutable int r;
	mutable ll v;
	val(int L=-1, int R=-1, int V=0) : l(L), r(R), v(V) { }
	const bool operator<(const val& o) const { return l < o.l; }
};

set<val> stt;
using it = set<val>::iterator;

it split(int l) { // split between l-1 and l, returns chunk containing l
	it v = stt.lower_bound(val(l));
	if(v != stt.end() && v->l == l) return v;
	--v;
	int L = v->l, R = v->r; ll V = v->v;
	v->r = l-1;
	return stt.insert(val(l, R, V)).fi;
}

void assign(int l, int r, int v) { // [l, r] = v
	it a = split(l), b = split(r+1);
	stt.erase(a, b);
	stt.insert(val(l, r, v));
}

void add(int l, int r, int v) { // [l, r] += v
	it a = split(l), b = split(r+1);
	for(; a != b; ++a) a->v += v;
}

int pws(int l, int r, int k, int MOD) {
	it a = split(l), b = split(r+1);
	int ans = 0;
	for(; a != b; ++a) ans = (ans + 1ll * (a->r - a->l + 1) * qpow(a->v, k, MOD)) % MOD;
	return ans;
}

ll kth(int l, int r, int k) { 
	static pair<ll, int> ar[100005]; int cnt = 0;
	it a = split(l), b = split(r+1);
	for(; a != b; ++a) {
		ar[cnt].fi = a->v;
		ar[cnt].se = a->r - a->l + 1;
		cnt++;
	}
	sort(ar, ar+cnt);
	rep(i, cnt) {
		k -= ar[i].se;
		if(k <= 0) return ar[i].fi;
	}
	return -1;
}

int seed;

int rnd() {
	int ret = seed;
	seed = (seed * 7ll + 13) % 1000000007;
	return ret;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, vmax; gi(n), gi(m), gi(seed), gi(vmax);
	int last = -1, lastv = -1;
	rep1(i, n) {
		int v = rnd() % vmax + 1;
		if(v != lastv) {
			if(lastv != -1) stt.insert(val(last, i-1, lastv));
			last = i; lastv = v;
		}
	}
	stt.insert(val(last, n, lastv));
	stt.insert(val(n+1, n+1, 0));
	int op, l, r, x;
	int cnt = 0;
	while(m--) {
		op = rnd() % 4 + 1;
		l = rnd() % n + 1;
		r = rnd() % n + 1;
		if(l > r) swap(l, r);
		if(op == 1) add(l, r, rnd() % vmax + 1);
		else if(op == 2) assign(l, r, rnd() % vmax + 1);
		else if(op == 3)
			print(kth(l, r, rnd() % (r - l + 1) + 1)), pc('\n');
		else {
			x = rnd() % vmax + 1;
			print(pws(l, r, x, (rnd() % vmax) + 1)); pc('\n');
		}
	}
}