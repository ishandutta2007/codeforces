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

struct node {
	int lc, rc, mi;
	bool lazy;
	int lazytag;
} nodes[1<<24];

int cnt;

namespace pRMQ {
	int st[100005][18];
	int st_n;
	int qjzxz;

	void st_create(vector<int> a) {
		memset(st, 0x3f, sizeof st);
		st_n = a.size();
		qjzxz = 0x3f3f3f3f;
		rep(i, st_n) st[i][0] = a[i], qjzxz = min(qjzxz, a[i]);
		for(int bit=1; (1<<bit)<=st_n; bit++)
			rep(i, st_n-(1<<(bit-1)))
				st[i][bit] = min(st[i][bit-1], st[i+(1<<(bit-1))][bit-1]);
		//cerr << "doo doo doo" << endl;
	}

	int st_calc(int l, int r) {
		int sz = r - l; if(!sz) return 1<<30;
		int b = 0; while((1 << (b+1)) <= sz) b++;
		return min(st[l][b], st[r-(1<<b)][b]);
	}

	int prmq(int l, int r) {
		if(l/st_n == r/st_n) return st_calc(l%st_n, r%st_n);
		if(l/st_n + 1 == r/st_n) return min(st_calc(l%st_n,st_n), st_calc(0,r%st_n));
		return qjzxz;
	}
}


int mknew(int l, int r) {
	assert(cnt != (1<<24));
	nodes[cnt] = {-1, -1, pRMQ::prmq(l, r), 0, 0};
	cnt++;
	return cnt-1;
}

void propg(int idx, int l, int r) {
	if(nodes[idx].lc == -1) nodes[idx].lc = mknew(l, (l+r)/2);
	if(nodes[idx].rc == -1) nodes[idx].rc = mknew((l+r)/2, r);
	if(nodes[idx].lazy) {
		nodes[nodes[idx].lc].mi = nodes[nodes[idx].lc].lazytag = nodes[idx].lazytag, nodes[nodes[idx].lc].lazy = 1;
		nodes[nodes[idx].rc].mi = nodes[nodes[idx].rc].lazytag = nodes[idx].lazytag, nodes[nodes[idx].rc].lazy = 1;
		nodes[idx].lazy = 0; nodes[idx].lazytag = 0;
	}
}

void tag(int idx, int l, int r, int L, int R, int v) {
	assert(l <= L && R <= r);
	if(l == L && R == r) {
		nodes[idx].mi = nodes[idx].lazytag = v;
		nodes[idx].lazy = 1;
		return;
	}
	propg(idx, l, r);
	int m = (l+r)/2;
	if(L<m) tag(nodes[idx].lc, l, m, L, min(R,m), v);
	if(m<R) tag(nodes[idx].rc, m, r, max(L,m), R, v);
	nodes[idx].mi = min(nodes[nodes[idx].lc].mi, nodes[nodes[idx].rc].mi);
}

int qry(int idx, int l, int r, int L, int R) {
	assert(l <= L && R <= r);
	if(l == L && R == r) return nodes[idx].mi;
	propg(idx, l, r);
	int m = (l+r)/2;
	int ans = 1<<30;
	if(L<m) ans = min(ans, qry(nodes[idx].lc, l, m, L, min(R,m)));
	if(m<R) ans = min(ans, qry(nodes[idx].rc, m, r, max(L,m), R));
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
	int n, useless; gi(n), gi(useless);
	vector<int> ar;
	rep(i, n) { int t; gi(t); ar.pb(t); }
	pRMQ::st_create(ar);
	int q; gi(q);
	mknew(0, n*useless);
	while(q--) {
		int t, l, r; gi(t), gi(l), gi(r);
		l--;
		if(t == 1) {
			int v; gi(v);
			tag(0, 0, n*useless, l, r, v);
		} else {
			print(qry(0, 0, n*useless, l, r)); pc('\n');
		}
	}
}