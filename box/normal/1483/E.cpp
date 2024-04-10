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

ll curbal;
ll curok;
int cnt = 0;
map<ll,bool> mem;
ll x;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

string ask(ll s) {
	cnt++;
	string ret;
	cout << "? " << s << endl; 
	cin >> ret;
	return ret;
}

bool qry(ll v) {
	if(v > 100000000000000) return 0;
	if(v <= curok) return 1;
	if(mem.count(v)) return mem[v];
	while(curbal < v) {
		string s = ask(curok);
		assert(s=="Lucky!");
		curbal += curok;
	}
	string s = ask(v);
	if(s == "Lucky!") {
		curbal += v;
		curok = max(curok, v);
		return mem[v]=1;
	} else {
		curbal -= v;
		return mem[v]=0;
	}
}

const double gq = 1.618;

void run() {
	curbal = 1; curok = 0; cnt = 0; mem.clear();
	ll c=1;
	double q=gq;
	for(;;){
		if(!qry(c))break;
		c=c*2;
	}
	if(c!=1) {
		long long low = curok+1, high = c-1;
		while(low <= high) {
			if(high-low<200000)q=gq;
			ll mid = (low*q+high)/(1+q);
			mid=max(mid,low);mid=min(mid,high);
			if(qry(mid)) { low=mid+1; q-=0.105; }
			else { high=mid-1; q+=0.12; }
		}
	}
	cout << "! " << curok << endl;
}

signed main() {
    int t; cin >> t;
	while(t--) run();
}