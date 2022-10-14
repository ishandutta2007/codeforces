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

int dep[100005], clck = 1;
int relabeldep[100005], in[100005], out[100005];
int fa[100005][7];
int cnt[100005];
pii elist[100005];
void dfs(int u, int par) {
	int node = u;
	fa[node][0] = par;
    if(!par) dep[node] = 0;
    else dep[node] = dep[par]+1;
    int pt = 0;
    while(fa[node][pt]) {
        fa[node][pt+1] = fa[fa[fa[fa [fa[fa[fa[fa[node][pt]][pt]][pt]][pt]][pt]][pt]][pt]][pt];
        pt++;
    }
	in[u] = clck;
	relabeldep[clck] = dep[u];
	clck++;
	iter(i, elist[u].fi, elist[u+1].fi) dfs(elist[i].se, u);
	out[u] = clck;
}
int ans[100005], qry[100005];
pii lx[200005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; gi(n);
	n++;
	iter(i, 2, n+1) {
		int p; gi(p);
		p++;
		elist[clck++] = {p, i};
	}
	sort(elist+1, elist+clck);
	int prv = 0;
	rep1(i, clck-1) {
		if(elist[i].fi != prv) {
			prv = elist[i].fi;
			elist[i].fi = 0;
			elist[prv].fi = i;
		} else {
			prv = elist[i].fi;
			elist[i].fi = 0;
		}
	}
	elist[n+1].fi = n;
	for(int i=n; i>=1; i--) if(elist[i].fi == 0) elist[i].fi = elist[i+1].fi;
	// rep1(i, n) cout << elist[i].fi << ' ' << elist[i].se << endl;
	// return 0;
	clck = 1;
	dfs(1, 0);
	clck = 0;
	gi(q);
	rep1(i, q) {
		int u, k; gi(u), gi(k);
		u++;
		qry[i] = dep[u];
		int v = k;
		rep(j, 7) {
			rep(___, k%8) u = fa[u][j];
			k >>= 3;
		}
		if(u >= 2) {
			lx[clck++] = {out[u]-1, i};
			lx[clck++] = {in[u]-1, -i};
		}
	}
	sort(lx, lx+clck);
	lx[clck].fi = -1; clck = 0;
	relabeldep[0] = relabeldep[n+1] = 100002;
	rep(i, n+2) {
		cnt[relabeldep[i]]++;
		while(lx[clck].fi == i) {
			if(lx[clck].se < 0) ans[-lx[clck].se] -= cnt[qry[-lx[clck].se]];
			else ans[lx[clck].se] += cnt[qry[lx[clck].se]];
			clck++;
		}
	}
	rep1(i, q) print(max(0,ans[i]-1)), pc(' ');
}