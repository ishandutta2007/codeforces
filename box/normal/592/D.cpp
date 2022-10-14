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
#define int ll
const int MOD = 1000000007;

int R[500005], D[500005], _D[500005], cnt[500005];
bool has[500005];
vector<pii> elist[500005];

void link(int fa, int ch, int w) {
	if(cnt[ch]) {
		cnt[fa] += cnt[ch];
		int c = D[ch]-w;
		if(c < D[fa]) {
			_D[fa] = D[fa];
			D[fa] = c;
		} else _D[fa] = min(_D[fa], c);
		R[fa] += R[ch] + 2*w;
	}
}

void cut(int fa, int ch, int w) {
	if(cnt[ch]) {
		cnt[fa] -= cnt[ch];
		int c = D[ch]-w;
		if(c == D[fa]) D[fa] = _D[fa];
		R[fa] -= R[ch] + 2 * w;
	}
}

void dfs(int u, int fa) {
	cnt[u] = has[u]; R[u] = D[u] = _D[u] = 0;
	for(pii& v:elist[u]) {
		if(v.fi == fa) continue;
		dfs(v.fi, u);
		link(u, v.fi, v.se);
	}
}

int ans[500005];

void reroot(int u, int fa) {
	int pr = R[u], pd = D[u], p_d = _D[u], pcnt = cnt[u];
	ans[u] = R[u] + D[u];
	for(pii& v:elist[u]) {
		if(v.fi == fa) continue;
		cut(u, v.fi, v.se);
		link(v.fi, u, v.se);
		reroot(v.fi, u);
		R[u] = pr, D[u] = pd, _D[u] = p_d, cnt[u] = pcnt;
	}
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, K; gi(N), gi(K);
	rep(i, N-1) {
		int u, v; gi(u), gi(v);
		elist[u].pb({v, 1});
		elist[v].pb({u, 1});
	}
	rep(i, K) {
		int v; gi(v);
		has[v] = 1;
	}
	dfs(1, -1);
	reroot(1, -1);
	int stest = 0xFFFFFFF, at = 0;
	rep1(i, N) {
		if(ans[i] < stest) {
			stest = ans[i];
			at = i;
		}
	}
	print(at); pc('\n'); print(stest);
}