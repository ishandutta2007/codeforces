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

int ex[1000006];
int pha[1000006];

int gha(int l, int r) {
	if(!l) return pha[r];
	else return (1ll*MOD+pha[r]-(1ll*ex[r-l+1]*pha[l-1])%MOD)%MOD;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
	char c;
	int m = 0;
	while(cin >> c) {
		int t = c - 'a' + 1;
		if(!m) {
			ex[0] = 1;
			pha[0] = t;
		} else {
			ex[m] = 29ll*ex[m-1]%MOD;
			pha[m] = ((29ll*pha[m-1])+t)%MOD;
		}
		m++;
	}
	int n = s.length();
	int zc = 0, oc = 0;
	rep(i, n) {
		if(s[i] == '0') zc++;
		else oc++;
	}
	int ans = 0;
	rep1(zl, m-1) {
		if(zl * zc > m) break;
		if(m - zl*zc <= 0) break;
		if((m - zl*zc)%oc) continue;
		int ol = (m-zl*zc)/oc;
		int zh = -1, oh = -1, at = 0;
		bool ok = true;
		rep(i, n) {
			int hsh = gha(at, at+(s[i]=='0'?zl:ol)-1);
			at += (s[i]=='0'?zl:ol);
			if(s[i]=='0') {
				if(zh==-1) zh=hsh;
				else if(zh!=hsh) {
					ok=0;
					break;
				}
			} else {
				if(oh==-1) oh=hsh;
				else if(oh!=hsh) {
					ok=0;
					break;
				}
			}
		}
		ans += (ok && (zh != oh));
	}
	cout << ans << endl;
}