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

vector<pii> elist[1<<20];
int id1[1<<19], id2[1<<19], ok;

void build1(int idx, int fa, int l, int r) {
	id1[idx] = ok++;
	if(fa != -1) elist[fa].pb({id1[idx],0});
	if(r-l == 1) {
		elist[id1[idx]].pb({l,0});
		return;
	}
	build1(idx*2, id1[idx], l, (l+r)/2);
	build1(idx*2+1, id1[idx], (l+r)/2, r);
}

void build2(int idx, int fa, int l, int r) {
	id2[idx] = ok++;
	if(fa != -1) elist[id2[idx]].pb({fa,0});
	if(r-l == 1) {
		elist[l].pb({id2[idx],0});
		return;
	}
	build2(idx*2, id2[idx], l, (l+r)/2);
	build2(idx*2+1, id2[idx], (l+r)/2, r);
}

void link1(int idx, int l, int r, int L, int R, int fro, int wt) {
	if(L <= l && r <= R) {
		elist[fro].pb({id1[idx],wt});
		return;
	}
	if(R <= l || r <= L) return;
	link1(idx*2, l, (l+r)/2, L, R, fro, wt);
	link1(idx*2+1, (l+r)/2, r, L, R, fro, wt);
}

void link2(int idx, int l, int r, int L, int R, int to, int wt) {
	if(L <= l && r <= R) {
		elist[id2[idx]].pb({to,wt});
		return;
	}
	if(R <= l || r <= L) return;
	link2(idx*2, l, (l+r)/2, L, R, to, wt);
	link2(idx*2+1, (l+r)/2, r, L, R, to, wt);
}

ll dis[1<<20];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, s; gi(n), gi(q), gi(s);
	ok = n+1;
	build1(1, -1, 1, n+1);
	build2(1, -1, 1, n+1);
	rep(i, q) {
		int t; gi(t);
		if(t == 1) {
			int v, u, w; gi(v), gi(u), gi(w);
			elist[v].pb({u, w});
		} else {
			int v, l, r, w; gi(v), gi(l), gi(r), gi(w);
			if(t==2) link1(1, 1, n+1, l, r+1, v, w);
			else link2(1, 1, n+1, l, r+1, v, w);
		}
	}
	memset(dis, -1, sizeof dis);
	pq.push({0, s}); dis[s] = 0;
	while(!pq.empty()) {
		auto [dst, node] = pq.top(); pq.pop();
		if(dis[node] < dst) continue;
		for(auto [nxt, edgl] : elist[node])
			if(dis[nxt] == -1 || dst + edgl < dis[nxt]) {
				dis[nxt] = dst + edgl;
				pq.push({dis[nxt], nxt});
			}
	}
	rep1(i, n) print(dis[i]), pc(' ');
}