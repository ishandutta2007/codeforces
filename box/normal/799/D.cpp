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

ll cdiv(const ll n, const ll d) { return (n+d-1)/d; }

void dfs(int idx, int curpr, const vector<int>& st, int& curbes, const int& thr) {
	if(curpr >= thr) { curbes = min(curbes, curpr); return; }
	if(idx == st.size()) return;
	dfs(idx+1, curpr*st[idx], st, curbes, thr);
	dfs(idx+1, curpr, st, curbes, thr);
}

int fmpswo2(vector<int> st, int thr) {
	sort(all(st)); reverse(all(st));
	int re = 1ll<<30;
	dfs(0, 1, st, re, thr);
	return re;
}

int fmps(const vector<int>& st, int thr) {
	vector<int> no2; int cnt = 0;
	for(int t:st) {
		if(t != 2) no2.push_back(t);
		else cnt++;
	}
	ll ans = 1ll<<30;
	rep(i, cnt+1) {
		if((1ll<<i) >= ans) continue;
		ans = min(ans, fmpswo2(no2, cdiv(thr, 1ll<<i))<<i);
	}
	return ans;
}

bool _chk(int a, int b, int h, int w, const vector<int>& st) {
    int tprod = 1;
	for(int k:st) {
		tprod *= k;
		if(tprod >= ((1ull) << 60)) return 1;
	}
	int x = cdiv(a, h), y = cdiv(b, w);
	if(tprod < x) return 0;
	int abvx = fmps(st, x);
	return tprod/abvx >= y;
}

bool chk(int a, int b, int h, int w, const vector<int>& st) {
	if(st.size() >= 34) return 1;
	return _chk(a, b, h, w, st) ||
	_chk(b, a, h, w, st);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int a, b, h, w, n; cin >> a >> b >> h >> w >> n;
	vector<int> tt(n);
	rep(i, n) cin >> tt[i];
	sort(all(tt)); reverse(all(tt));
	int low = 0, high = n, ans = -1;
	while(low <= high) {
		int mid = (low + high) / 2;
		vector<int> tr; rep(i, mid) tr.pb(tt[i]);
		if(chk(a, b, h, w, tr)) ans = mid, high = mid - 1;
		else low = mid + 1;
	}
	cout << ans << endl;
}