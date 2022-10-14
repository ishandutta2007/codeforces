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
#define int ll
using pii=pair<int, int>;
const int MOD = 1000000007;

pii run(vector<pii> cost, int thr) {
	if(cost.size() == 0) return {-1000000000, -1000000000};
	sort(all(cost));
	while(cost.back().fi > thr) {
		cost.pop_back();
		if(cost.size() == 0) return {-1000000000, -1000000000};
	}
	vector<int> pmax(cost.size());
	rep(i, cost.size()) {
		pmax[i] = cost[i].se;
		if(i) pmax[i] = max(pmax[i], pmax[i-1]);
	}
	if(cost.size() == 1) return {pmax.back(), -1000000000};
	int curind = 0, b2 = 0;
	for(int i=cost.size()-1; i>=1; i--) {
		curind = min(curind, i-1);
		while(curind+1 < i && cost[curind+1].fi + cost[i].fi <= thr) curind++;
		if(curind < i && cost[curind].fi + cost[i].fi <= thr)
			b2 = max(b2, pmax[curind] + cost[i].se);
	}
	return {pmax.back(), b2};
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<pii> coin, diamond;
	int n, c, d; cin >> n >> c >> d;
	rep(i, n) {
		string s;
		int be, cs; cin >> be >> cs >> s;
		if(s == "C") coin.pb({cs, be});
		else diamond.pb({cs, be});
	}
	auto [x1, x2] = run(coin, c);
	auto [y1, y2] = run(diamond, d);
	cout << max(max(max(x2, y2), x1+y1), 0ll) << endl;
}