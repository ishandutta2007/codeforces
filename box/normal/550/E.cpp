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

int ar[100005];

string strat1(int n) {
	if(ar[n-1] == 0) {
		if(n == 1 && ar[0] == 0) return "";
		else {
			int zc = 0;
			while(n != zc && ar[n-zc-1] == 0) zc++;
			string sufx;
			if(zc == 1) sufx = "0";
			else if(zc == 2) {
				return "";
				return 0;
			} else {
				rep(i, zc-2) sufx += "(0->";
				sufx += "0";
				rep(i, zc-2) sufx += ")";
				sufx += "->0";
			}
			n -= zc;
			string ans;
			int cz = 0;
			bool first = 1;
			rep(i, n) {
				if(ar[i]) {
					if(cz) {
						if(ans.length()) ans += "->";
						rep(i, cz) ans += "(0->";
						ans += "1";
						rep(i, cz) ans += ")";
						cz = 0;
					}
					else {
						if(ans.length()) ans += "->";
						ans += "1";
					}
				} else cz++;
			}
			if(!ans.length()) return sufx;
			return ans + "->" + sufx;
		}
	} else return "";
}

string strat2(int n) {
	if(ar[n-1] == 0) {
		int tz = 0;
		rep(i, n) tz += (ar[i] == 0);
		if(tz == 2) return "";
		else {
			int oc = 0;
			bool first = 1;
			vector<string> anses;
			rep(i, n) {
				if(ar[i]) oc++;
				else {
					if(oc) {
						string t = "(";
						rep(i, oc) t += "1->";
						t += "0)";
						anses.pb(t);
						oc = 0;
					}
					else {
						anses.pb("0");
					}
				}
			}
			int k = anses.size();
			string ans;
			if(k >= 2) {
				rep(i, k-2) ans += "(" + anses[i] + "->";
				ans += anses[k-2];
				rep(i, k-2) ans += ')';
				ans += "->";
			}
			ans += anses[k-1];
			return ans;
		}
	} else return "";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; gi(n);
	rep(i, n) gi(ar[i]);
	string a = strat1(n);
	string b = strat2(n);
	if(a.length()) pstr("YES\n"), pstr(a.c_str());
	else if(b.length()) pstr("YES\n"), pstr(b.c_str());
	else pstr("NO\n");
}

//