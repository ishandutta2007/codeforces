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

int bcj[300006];
void binit(){memset(bcj,-1,sizeof bcj);}
int bget(int i){return (bcj[i]<0)?i:(bcj[i]=bget(bcj[i]));}
bool bmerge(int i,int j){int ri=bget(i),rj=bget(j);if(ri==rj){return 0;}if(bcj[ri]>bcj[rj]){swap(ri,rj);}bcj[ri]+=bcj[rj];bcj[rj]=ri;return 1;}

vector<int> elist[300006];
int fa[300005];
int dep[300005];
vector<pii> EE;
int ub[300006];
ll ps1[300005];

void dfs(int u, int f) {
	if(f == -1) dep[u] = 1;
	else dep[u] = dep[f]+1;
	fa[u] = f;
	for(int& v:elist[u]) if(v != f) dfs(v, u);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; gi(n), gi(m);
	binit();
	while(m--) {
		int u, v; gi(u), gi(v);
		if(bmerge(u, v)) elist[u].pb(v), elist[v].pb(u);
		else EE.pb({u, v});
	}
	rep1(i, n) if(!dep[i]) dfs(i, -1);
	rep1(i, n) ub[i] = n;
	for(pii& p:EE) {
		int a = p.fi, b = p.se;
		int mi = min(a, b);
		int mx = max(a, b);
		if(dep[a] > dep[b]) swap(a, b);
		while(dep[a] < dep[b]) {
			b = fa[b];
			mi = min(mi, b);
			mx = max(mx, b);
		}
		while(a != b) {
			a = fa[a];
			b = fa[b];
			mi = min(mi, min(a, b));
			mx = max(mx, max(a, b));
		}
		ub[mi] = min(ub[mi], mx-1);
	}
	for(int i=n-1; i>=1; i--)
		ub[i] = min(ub[i], ub[i+1]);
	rep1(i, n) ps1[i] = ps1[i-1] + (ub[i] - i + 1);
	gi(m);
	while(m--) {
		int l, r; gi(l), gi(r);
		int low = l, high = r, ans = r;
		while(low <= high) {
			int mi = (low + high) / 2;
			if(ub[mi] >= r) { ans = mi; high = mi-1; }
			else low = mi+1;
		}
		ll res = ps1[ans-1] - ps1[l-1];
		res += 1ll * (r+1) * (r-ans+1);
		res -= 1ll * r * (r+1) / 2 - 1ll * (ans-1) * ans / 2;
		print(res); pc('\n');
	}
}