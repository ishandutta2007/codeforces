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

bool co[1000006];
int fa[1000006][21];
int dep[1000006];
vector<int> el[1000006];

void dfs(int u, int f) {
	if(f != -1) dep[u] = dep[f]+1;
	fa[u][0] = f; int i = 0;
	while(fa[u][i] != -1) {
		fa[u][i+1] = fa[fa[u][i]][i];
		i++;
	}
	while(i != 20) fa[u][++i] = -1;
	for(int& v:el[u]) {
		if(v == f) continue;
		dfs(v, u);
	}
}
int rem;

bool st(int v) {
	if(co[v]) return 1;
	int t = v;
	for(int k = 20; k >= 0; k--) if(fa[t][k] != -1 && !co[fa[t][k]]) t = fa[t][k];
	int cnt = dep[v] - dep[t] + 1;
	if(cnt > rem) return 0;
	while(v != -1 && !co[v]) co[v] = 1, v = fa[v][0];
	rem -= cnt;
	return 1;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; gi(n), gi(k); rem = n - k;
	rep(i, n-1) {
		int u, v; gi(u), gi(v);
		el[u].pb(v);
		el[v].pb(u);
	}
	dfs(n, -1);
	for(int i=n; i>=1; i--) st(i);
	rep1(i, n) if(!co[i]) print(i), pc(' ');
	pc('\n');
}