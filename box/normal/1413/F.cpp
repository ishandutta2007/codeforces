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

pii dat[500005<<2];
bool laz[500005<<2];

void push(int idx, int l, int r) {
	if(!laz[idx] || l == r) return;
	dat[idx*2] = {dat[idx*2].se, dat[idx*2].fi}; laz[idx*2] = !laz[idx*2];
	dat[idx*2+1] = {dat[idx*2+1].se, dat[idx*2+1].fi}; laz[idx*2+1] = !laz[idx*2+1];
	laz[idx] = 0;
}

void upd(int idx, int l, int r, int i, pii v) {
	if(!(l <= i && i <= r)) return;
	push(idx, l, r);
	if(l == r) {
		dat[idx] = v;
		return;
	}
	upd(idx*2, l, (l+r)/2, i, v);
	upd(idx*2+1, (l+r)/2+1, r, i, v);
	dat[idx] = {max(dat[idx*2].fi, dat[idx*2+1].fi), max(dat[idx*2].se, dat[idx*2+1].se)};
}

void tag(int idx, int l, int r, int ql, int qr) {
	if(qr < l || r < ql) return;
	push(idx, l, r);
	if(ql <= l && r <= qr) {
		dat[idx] = {dat[idx].se, dat[idx].fi};
		laz[idx] = !laz[idx];
		return;
	}
	tag(idx*2, l, (l+r)/2, ql, qr);
	tag(idx*2+1, (l+r)/2+1, r, ql, qr);
	dat[idx] = {max(dat[idx*2].fi, dat[idx*2+1].fi), max(dat[idx*2].se, dat[idx*2+1].se)};
}

pii el2[500005];
vector<pii> elist[500005];
pii dfsfar(int u, int f) {
	pii ans = {0, u};
	for(pii& v:elist[u]) if(v.fi != f) ans = max(ans, dfsfar(v.fi, u));
	return {ans.fi+1, ans.se};
}
int clck = 1;
int n;
int L[500005], R[500005];
int qr[500005], ans[500005];
void dfs(int u, int f, int dep, int cnt) {
	L[u] = clck++;
	if(cnt % 2 == 0) upd(1, 1, n, L[u], {dep, 0});
	else upd(1, 1, n, L[u], {0, dep});
	for(pii& v:elist[u]) if(v.fi != f) dfs(v.fi, u, dep+1, cnt+v.se);
	R[u] = clck-1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    gi(n);
    rep(i, n-1) {
    	int u, v, w; gi(u), gi(v), gi(w);
    	el2[i] = {u,v};
    	elist[u].pb({v,w});
    	elist[v].pb({u,w});
    }
    int root = dfsfar(1, -1).se;
    dfs(root, -1, 0, 0);
    int q; gi(q);
    rep(i, q) gi(qr[i]);
    rep(i, q) {
    	int par = el2[qr[i]-1].fi, ch = el2[qr[i]-1].se;
    	if(R[par]-L[par] < R[ch]-L[ch]) swap(par, ch);
    	tag(1, 1, n, L[ch], R[ch]);
    	ans[i] = max(ans[i], dat[1].fi);
    }
    root = dfsfar(root, -1).se;
    memset(dat, 0, sizeof dat);
    memset(laz, 0, sizeof laz);
    clck = 1; dfs(root, -1, 0, 0);
    rep(i, q) {
    	int par = el2[qr[i]-1].fi, ch = el2[qr[i]-1].se;
    	if(R[par]-L[par] < R[ch]-L[ch]) swap(par, ch);
    	tag(1, 1, n, L[ch], R[ch]);
    	ans[i] = max(ans[i], dat[1].fi);
    	print(ans[i]), pc('\n');
    }
}