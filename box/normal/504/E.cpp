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
const int bas = 108616, ibas = 358262137;
const int mxn = 3e5+5;

vector<int> elist[mxn];
int sz[mxn], hvc[mxn], hvp[mxn], o2n[mxn], dep[mxn], fa[mxn], cl = 1; 
char s[mxn], nws[mxn];

int dfs1(int u, int f) { 
	sz[u] = 1; for(int& v:elist[u]) if(v != f) sz[u] += dfs1(v, u); 
	return sz[u];
}
void dfs2(int u, int f, int hp) {
	o2n[u] = cl; nws[cl] = s[u]; cl++; hvp[u] = hp; dep[u] = dep[f] + 1; fa[u] = f;
	pii bs = {0, 0}; for(int& v:elist[u]) if(v != f) bs = max(bs, {sz[v], v});
	if(!bs.se) return;
	dfs2(bs.se, u, hp);
	for(int& v:elist[u]) if(v != f && v != bs.se) dfs2(v, u, v);
}
vector<pii> order(int u, int v) {
	vector<pii> fromU, fromV;
	while(hvp[u] != hvp[v]) {
		if(dep[hvp[u]] >= dep[hvp[v]]) { fromU.pb({o2n[u], o2n[hvp[u]]}); u = fa[hvp[u]]; }
		else { fromV.pb({o2n[hvp[v]], o2n[v]}); v = fa[hvp[v]]; }
	} fromU.pb({o2n[u], o2n[v]});
	reverse(fromV.begin(), fromV.end()); for(auto& k:fromV) fromU.pb(k);
	return fromU;
}

int ex[mxn], iex[mxn];
pii app(pii a, pii o) { return {a.fi+o.fi, (a.se+1ll*ex[a.fi]*o.se)%MOD}; }
pii rem1(pii a, pii o) { return {a.fi-o.fi, 1ll*(a.se+MOD-o.se)*iex[o.fi]%MOD}; }
pii rem2(pii a, pii o) { return {a.fi-o.fi, (a.se+1ll*ex[a.fi-o.fi]*(MOD-o.se))%MOD}; }
pii fhs[mxn], rhs[mxn];
pii get(int l, int r) { 
	if(l <= r) return rem1(fhs[r], fhs[l-1]); 
	else return rem2(rhs[l], rhs[r-1]);
}
int len(int l,int r){return max(l,r)-min(l,r)+1;}
int tr(int l,int r,int k){return (l<=r)?(l+k-1):(l-k+1);}
int t2(int l,int r,int k){return (l<=r)?(l+k):(l-k);}

int work(int u1, int v1, int u2, int v2) {
	auto a = order(u1, v1), b = order(u2, v2);
	assert(a.size() && b.size());
	int ans = 0;
	pii ac = {-1, 0}, bc = {-1, 0};
	int adx = 0, bdx = 0;
	while(1) {
		if(ac.fi == -1) { if(adx == a.size()) { break; } ac=a[adx++]; }
		if(bc.fi == -1) { if(bdx == b.size()) { break; } bc=b[bdx++]; }
		int le = min(len(ac.fi, ac.se), len(bc.fi, bc.se));
		pii h1 = get(ac.fi,tr(ac.fi,ac.se,le)), h2 = get(bc.fi,tr(bc.fi,bc.se,le));
		if(h1 != h2) {
			int low = 1, high = le, dt = 0;
			while(low <= high) {
				int mid = (low + high) / 2;
				if(get(ac.fi,tr(ac.fi,ac.se,mid)) == get(bc.fi,tr(bc.fi,bc.se,mid))) dt = mid, low = mid+1;
				else high = mid-1;
			} return ans + dt;
		} else ans += le;
		if(len(ac.fi,ac.se) == le) ac.fi = -1; else ac.fi=t2(ac.fi,ac.se,le);
		if(len(bc.fi,bc.se) == le) bc.fi = -1; else bc.fi=t2(bc.fi,bc.se,le);
	}
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; gi(n); ex[0]=iex[0]=1;
	rep1(i,n+1) ex[i]=1ll*ex[i-1]*bas%MOD, iex[i]=1ll*iex[i-1]*ibas%MOD;
	gstr(s+1);
	rep(i, n-1) {
		int u, v; gi(u), gi(v);
		elist[u].pb(v); elist[v].pb(u);
	}
	dfs1(1, 0); dfs2(1, 0, 1);
	fhs[0] = {0, 0}; rep1(i, n) fhs[i] = app(fhs[i-1], {1, nws[i]});
	rhs[0] = {0, 0}; rep1(i, n) rhs[i] = app({1, nws[i]}, rhs[i-1]);
	int m; gi(m); while(m--) { 
		int u1, v1, u2, v2; 
		gi(u1), gi(v1), gi(u2), gi(v2);
		print(work(u1, v1, u2, v2)); pc('\n');
	}
}