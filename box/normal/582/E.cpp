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

vector<int> OrConv(vector<int> a, vector<int> b) {
	rep(i, 16)
		rep(j, 65536)
			if(j & (1<<i)) {
				a[j] = (a[j] + a[j^(1<<i)]) % MOD;
				b[j] = (b[j] + b[j^(1<<i)]) % MOD;
			}
	rep(j, 65536) a[j] = 1ll * a[j] * b[j] % MOD;
	rep(i, 16)
		rep(j, 65536)
			if(j & (1<<i))
				a[j] = (MOD + a[j] - a[j^(1<<i)]) % MOD;
	return a;
}
vector<int> AndConv(const vector<int>& a, const vector<int>& b) {
	int m = a.size()-1;
	vector<int> ap(a.size()), bp(b.size());
	rep(i, a.size()) ap[i] = a[i^m], bp[i] = b[i^m];
	ap = OrConv(ap, bp);
	rep(i, a.size()) bp[i] = ap[i^m];
	return bp;
}

namespace constants {
	int A, B, C, D;
	int a, b, c, d;
}
string s;

vector<int> solve(int l, int r) {
	if(r-l == 1) {
		vector<int> ans(65536);
		using namespace constants;
		if(s[l] == 'A' || s[l] == '?') ans[A]++;
		if(s[l] == 'B' || s[l] == '?') ans[B]++;
		if(s[l] == 'C' || s[l] == '?') ans[C]++;
		if(s[l] == 'D' || s[l] == '?') ans[D]++;
		if(s[l] == 'a' || s[l] == '?') ans[a]++;
		if(s[l] == 'b' || s[l] == '?') ans[b]++;
		if(s[l] == 'c' || s[l] == '?') ans[c]++;
		if(s[l] == 'd' || s[l] == '?') ans[d]++;
		return ans;
	}
	int mid, sp = 0;
	iter(i, l, r) {
		if(s[i] == '(') sp++;
		else if(s[i] == ')') sp--;
		else if(!sp) { mid = i; break; }
	}
	vector<int> lef = solve(l+1, mid-1), rig = solve(mid+2, r-1);
	if(s[mid] == '|') return OrConv(lef, rig);
	else if(s[mid] == '&') return AndConv(lef, rig);
	else {
		vector<int> x = OrConv(lef, rig), y = AndConv(lef, rig);
		rep(i, 65536) x[i] = (x[i] + y[i]) % MOD;
		return x;
	}
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	{
		using namespace constants;
		rep(i, 16) if(i&1) A |= 1<<i;
		rep(i, 16) if(i&2) B |= 1<<i;
		rep(i, 16) if(i&4) C |= 1<<i;
		rep(i, 16) if(i&8) D |= 1<<i;
		a = A ^ 65535;
		b = B ^ 65535;
		c = C ^ 65535;
		d = D ^ 65535;
	}
	cin >> s;
	auto mask = solve(0, s.length());
	vector<pii> tj;
	int n; cin >> n;
	rep(i, n) {
		int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
		tj.pb({a+2*b+4*c+8*d, e});
	}
	int ans = 0;
	rep(i, 65536) {
		bool ok = 1;
		for(auto [bit, val] : tj) ok = ok && ((!!(i&(1<<bit)))==val);
		if(ok) ans = (ans + mask[i]) % MOD;
	}
	cout << ans;
}