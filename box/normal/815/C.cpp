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

vector<int> elist[5005];
int cost[5005], coupon[5005];
int siz[5005];
int b;
int dpA[5005][5005], dpB[5005][5005];
int curA[5005][2], curB[5005][2];

void dfs(int node) {
	siz[node] = 1; int mxp = -1;
	for(int& v:elist[node]) {
		dfs(v);
		siz[node] += siz[v];
		if(mxp == -1 || siz[mxp] < siz[v]) mxp = v;
	}
	if(mxp != -1) {
		iter(i, 1, siz[mxp]+1) curA[i][0] = min(dpA[mxp][i], dpB[mxp][i]), curB[i][0] = dpB[mxp][i];
		iter(i, siz[mxp]+1, siz[node]+1) curA[i][0] = curB[i][0] = 1000000001;
	} else iter(i, 1, siz[node]+1) curA[i][0] = curB[i][0] = 1000000001;
	int uid = 1;
	for(int& v:elist[node]) {
		if(v == mxp) continue;
		rep(i, siz[node]+1) curA[i][uid] = curA[i][uid^1], curB[i][uid] = curB[i][uid^1];
		rep(i, siz[node]+1) {
			rep(j, min(i,siz[v])+1) {
				curA[i][uid] = min(curA[i][uid], curA[i-j][uid^1] + min(dpA[v][j], dpB[v][j]));
				curB[i][uid] = min(curB[i][uid], curB[i-j][uid^1] + dpB[v][j]);
			}
		}
		uid ^= 1;
	}
	rep(i, siz[node]+1) dpA[node][i] = curA[i-1][uid^1]+coupon[node], dpB[node][i] = min(curB[i][uid^1], curB[i-1][uid^1]+cost[node]);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, b; gi(n), gi(b);
	rep1(i, n) {
		gi(cost[i]), gi(coupon[i]);
		coupon[i] = cost[i] - coupon[i];
		if(i != 1) {
			int f; gi(f);
			elist[f].pb(i);
		}
	}
	dfs(1);
	int mx = 0;
	/*
	rep1(i, n) {
		rep1(j, siz[i]) cout << dpA[i][j] << ' ';
		cout << endl;
	}
	rep1(i, n) {
		rep1(j, siz[i]) cout << dpB[i][j] << ' ';
		cout << endl;
	}*/
	rep1(i, n) if(min(dpA[1][i], dpB[1][i]) <= b) mx = i;
	print(mx);
}