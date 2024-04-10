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

map<int, int> oc;
int ar[500005];
int pre[500005], nxt[500005];
constexpr int csize = 716;

int cnk[705][705];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; gi(n), gi(m);
	rep(i, n) gi(ar[i]);
	rep(i, n) {
		if(oc.count(ar[i])) pre[i] = oc[ar[i]];
		else pre[i] = -1000000000;
		oc[ar[i]] = i;
	}
	oc.clear();
	for(int i=n-1; i>=0; i--) {
		if(oc.count(ar[i])) nxt[i] = oc[ar[i]];
		else nxt[i] = 1000000000;
		oc[ar[i]] = i;
	}
	for(int i=0,c=0; i<n; i+=csize,c++) {
		int cur = 0x3f3f3f3f;
		for(int j=i; j<n; j++) {
			if(i <= pre[j]) cur = min(cur, j-pre[j]);	
			if(j%csize == csize-1) cnk[c][j/csize] = cur;
		}
	}
	while(m--) {
		int l, r; gi(l), gi(r); l--, r--;
		int cl = l/csize, cr = r/csize;
		if(cl == cr) {
			if(l % csize == 0 && r % csize == csize - 1) 
				print(cnk[cl][cr] == 0x3f3f3f3f ? -1 : cnk[cl][cr]);
			else {
				int cur = 0x3f3f3f3f;
				iter(i, l, r+1) if(l <= pre[i]) cur = min(cur, i-pre[i]);
				print(cur == 0x3f3f3f3f ? -1 : cur);
			}
		} else {
			int cl1 = cl+1, cr1 = cr-1;
			if(l % csize == 0) cl1--;
			if(r % csize == (csize-1)) cr1++;
			assert(l <= cl1*csize);
			assert((cr1+1)*csize-1 <= r);
			int cur = (cl1 <= cr1) ? cnk[cl1][cr1] : 0x3f3f3f3f;
			iter(i, l, cl1*csize) {
				if(l <= pre[i]) cur = min(cur, i-pre[i]);
				if(nxt[i] <= r) cur = min(cur, nxt[i]-i);
			}
			iter(i, (cr1+1)*csize, r+1) {
				if(l <= pre[i]) cur = min(cur, i-pre[i]);
				if(nxt[i] <= r) cur = min(cur, nxt[i]-i);
			}
			print(cur == 0x3f3f3f3f ? -1 : cur);
		}
		pc('\n');
	}
}