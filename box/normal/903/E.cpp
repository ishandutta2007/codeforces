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

#define set unordered_set

int k, n;
char buf[2505][5005];
bool dup[2505];
bool cot[26];
int differ[2505][7];
int difc[2505];
int bruf[7], bufpt;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    gi(n), gi(k);
	rep(i, n) {
		gstr(buf[i]);
		if(i) {
			memset(cot, 0, sizeof cot);
			rep(j, k) {
				dup[i] = dup[i] || cot[buf[i][j]-'a'];
				cot[buf[i][j]-'a'] = 1;
				if(buf[i][j] != buf[0][j]) {
					differ[i][difc[i]++] = j;
					if(difc[i] > 4) {
						print(-1);
						return 0;
					}
				}
			}
		}
	}
	rep(p1, k)
		iter(p2, p1+1, k) {
			swap(buf[0][p1], buf[0][p2]);
			bool ok = 1;
			iter(i, 1, n) {
				bufpt = 0;
				bool hp1 = 0, hp2 = 0;
				rep(idx, difc[i]) 
					if(buf[0][differ[i][idx]] != buf[i][differ[i][idx]]) {
						bruf[bufpt++] = differ[i][idx];
						hp1 = hp1 || (differ[i][idx] == p1);
						hp2 = hp2 || (differ[i][idx] == p2);
					}
				if(!hp1 && buf[0][p1] != buf[i][p1]) 
					bruf[bufpt++] = p1;
				if(!hp2 && buf[0][p2] != buf[i][p2]) 
					bruf[bufpt++] = p2;
				if(bufpt == 2) {
					int a = bruf[0], b = bruf[1];
					if(buf[0][a] != buf[i][b] || buf[0][b] != buf[i][a]) { ok = 0; break; }
				} else if(bufpt || !dup[i]) { ok = 0; break; }
			}
			if(ok) {
				pstr(buf[0]);
				return 0;
			}
			swap(buf[0][p1], buf[0][p2]);
		}
	print(-1);
}