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

int N;
int ed[1000006];
vector<int> dis[1000006];
vector<ll> psu[1000006];

void dfs1(int u) {
	dis[u].pb(0);
	if(2*u <= N) {
		dfs1(2*u);
		if(2*u+1 <= N) {
			dfs1(2*u+1);
			int lp = 0, rp = 0;
			while(lp != dis[2*u].size() && rp != dis[2*u+1].size()) {
				if(dis[2*u][lp] + ed[2*u] < dis[2*u+1][rp] + ed[2*u+1]) dis[u].pb(dis[2*u][lp++] + ed[2*u]);
				else dis[u].pb(dis[2*u+1][rp++] + ed[2*u+1]);
			}
			while(lp != dis[2*u].size()) dis[u].pb(dis[2*u][lp++] + ed[2*u]);
			while(rp != dis[2*u+1].size()) dis[u].pb(dis[2*u+1][rp++] + ed[2*u+1]);
		} else for(int& k:dis[2*u]) dis[u].pb(k + ed[2*u]);
	}
	for(int& k:dis[u]) {
		if(psu[u].empty()) psu[u].pb(0);
		else psu[u].pb(psu[u].back()+k);
	}
}

ll gt(int u, int H, int pdis) {
	int thr = H - pdis;
	if(thr <= 0 || u > N) return 0;
	int ind = lower_bound(all(dis[u]), thr) - dis[u].begin() - 1;
	return 1ll*H*(ind+1) - psu[u][ind] - 1ll*pdis*(ind+1);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; gi(N), gi(m);
	iter(i, 2, N+1) gi(ed[i]);
	dfs1(1);
	while(m--) {
		int a, h; gi(a), gi(h);
		ll ans = gt(a, h, 0);
		int clen = ed[a];
		int cur = a/2, prev = a;
		while(cur) {
			ans += max(0, h - clen) + gt(2*cur + (2*cur == prev), h, clen + ed[2*cur + (2*cur == prev)]);
			clen += ed[cur];
			prev = cur;
			cur /= 2;
		}
		print(ans), pc('\n');
	}
}