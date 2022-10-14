#pragma GCC optimize("O4")
#pragma GCC target("avx2")
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

int fa[20004], dep[20004]; char fch[20004];
int sz[20004], re[20004], cock;
int n;
vector<pair<int, char>> el[20004];
vector<pair<int, char>> elist[20004];

void sdfs(int u, int f) {
	sz[u] = 1;
	for(auto& v: el[u]) if(v.fi != f) {
		sdfs(v.fi, u);
		sz[u] += sz[v.fi];
	}
}

void relabel(int u, int f) {
	re[u] = cock++;
	int bs = 0;
	for(auto& v: el[u]) if(v.fi != f) bs = max(bs, sz[v.fi]);
	for(auto& v: el[u]) if(v.fi != f && sz[v.fi] == bs) {
		bs = -v.fi;
		relabel(v.fi, u);
	}
	for(auto& v:el[u]) if(v.fi != f && v.fi != -bs) relabel(v.fi, u);
	for(auto& v:el[u]) elist[re[u]].pb({re[v.fi],v.se});
}

void dfs(int u, int f, char cc) {
	fa[u] = f; fch[u] = cc;
	if(f != -1) dep[u] = dep[f]+1;
	else dep[u] = 1;
	sz[u] = 1;
	for(auto& v: elist[u]) if(v.fi != f) {
		dfs(v.fi, u, v.se);
		sz[u] += sz[v.fi];
	}
}

char mein[20004];
int s = 0;
void get(int u, int v) {
	int U = u, V = v;
	while(dep[U] > dep[V]) U = fa[U];
	int cnt2 = 0;
	while(dep[U] < dep[V]) V = fa[V], cnt2++;
	while(U != V) U = fa[U], V = fa[V], cnt2++;
	int pt = 0;
	while(u != U) {
		mein[pt++] = fch[u];
		u = fa[u];
	}
	s = pt + cnt2;
	while(v != V) {
		pt--;
		mein[pt+cnt2] = fch[v];
		v = fa[v];
	}
}

int u, v, ans;

void dfs2(int u, int f, int dep, bool greater) {
	if(!greater && dep == s) return;
	if(dep == s || greater) {
		ans += (f == fa[u] ? sz[u] : n - sz[f]);
		return;
	}
	ans++;
	for(auto& v: elist[u]) {
		if(v.fi == f || v.se > mein[dep]) continue;
		dfs2(v.fi, u, dep+1, greater || (v.se < mein[dep]));
	}
}

char bf[4];
map<pii, int> cache;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int q; gi(n), gi(q);
	rep(i, n-1) {
		int u, v; gi(u), gi(v); gstr(bf);
		el[u].pb({v, bf[0]});
		el[v].pb({u, bf[0]});
	}
	sdfs(1, -1);
	relabel(1, -1);
	dfs(0, -1, 0);
	while(q--) {
		gi(u), gi(v);
		u = re[u], v = re[v];
		if(cache.count({u, v})) cout << cache[{u, v}] << endl;
		else {
			get(u, v);
			ans = -1;
			dfs2(u, -1, 0, 0);
			cout << (cache[{u,v}] = ans) << endl;
		}
	}
}