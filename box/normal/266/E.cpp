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

#define data MY_FUCKING_DATA

int binom[7][7];
int ps[100005][7];

struct data {
	int d[6];
	int& operator[](const int id) { return d[id]; }
	const int& operator[](const int id) const { return d[id]; }
	data() { d[0] = d[1] = d[2] = d[3] = d[4] = d[5] = 0; }
};

data shif(const data& dat, int x) {
	data ans;
	rep(k, 6) {
		int cur = 0, cx = 1;
		rep(v, k+1) {
			cur = (cur + 1ll * cx * dat[k-v] % MOD * binom[k][v]) % MOD;
			cx = 1ll * cx * x % MOD;
		}
		ans[k] = cur;
	}
	return ans;
}

data ad(const data& d1, const data& d2) {
	data ans;
	rep(k, 6) ans[k] = (d1[k] + d2[k]) % MOD;
	return ans;
}

int a[100005], tag[100005<<2];
data segt[100005<<2];

void put(int idx, int l, int r, int tg) {
	if(r - l == 0) return;
	rep(k, 6) segt[idx][k] = 1ll * tg * ps[r-l][k] % MOD;
	tag[idx] = tg;
}

void propg(int idx, int l, int r) {
	if(r-l == 0 || r-l == 1 || tag[idx] == -1) return;
	put(idx*2, l, (l+r)/2, tag[idx]);
	put(idx*2+1, (l+r)/2, r, tag[idx]);
	tag[idx] = -1;
}

void build(int idx, int l, int r) {
	tag[idx] = -1;
	if(r - l == 0) return;
	if(r - l == 1) {
		rep(k, 6) segt[idx][k] = a[l];
		return;
	}
	build(idx*2, l, (l+r)/2);
	build(idx*2+1, (l+r)/2,r);
	segt[idx] = ad(segt[idx*2], shif(segt[idx*2+1], (l+r)/2-l));
}

data qry(int idx, int l, int r, int L, int R) {
	propg(idx, l, r);
	if(L == l && r == R) return segt[idx];
	assert(l <= L && R <= r);
	if(R <= (l+r)/2) return qry(idx*2, l, (l+r)/2, L, R);
	if((l+r)/2 <= L) return qry(idx*2+1, (l+r)/2, r, L, R);
	auto a = qry(idx*2, l, (l+r)/2, L, (l+r)/2);
	auto b = qry(idx*2+1, (l+r)/2, r, (l+r)/2, R);
	return ad(a, shif(b, (l+r)/2-L));
}

void make(int idx, int l, int r, int L, int R, int t) {
	propg(idx, l, r);
	if(L == l && r == R) return put(idx, l, r, t);
	assert(l <= L && R <= r);
	if(R <= (l+r)/2) make(idx*2, l, (l+r)/2, L, R, t);
	else if((l+r)/2 <= L) make(idx*2+1, (l+r)/2, r, L, R, t);
	else make(idx*2, l, (l+r)/2, L, (l+r)/2, t), make(idx*2+1, (l+r)/2, r, (l+r)/2, R, t);
	segt[idx] = ad(segt[idx*2], shif(segt[idx*2+1], (l+r)/2-l));
}

char tb[3];

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	binom[0][0] = 1;
	rep1(i, 5) rep(j, 6) binom[i][j] = binom[i-1][j] + (j ? binom[i-1][j-1] : 0);
	rep1(i, 100000) {
		int k = 1;
		rep(j, 6) {
			ps[i][j] = (ps[i-1][j] + k) % MOD;
			k = (1ll * k * i) % MOD;
		}
	}
	int n, m; gi(n), gi(m);
	rep1(i, n) gi(a[i]);
	build(1, 1, n+2);
	while(m--) {
		gstr(tb); int x, y, z; gi(x), gi(y), gi(z);
		if(tb[0] == '=') make(1, 1, n+2, x, y+1, z);
		else print(qry(1, 1, n+2, x, y+1)[z]), pc('\n');
	}
}