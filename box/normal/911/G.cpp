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

int ar[200001];

class Chunk {
public:
	vector<int> pos[105]; int Bg, S;
	Chunk() { }
	Chunk(int bg, int s) : Bg(bg), S(s) { iter(i, bg, bg+s) pos[ar[i]].pb(i); }
	void merg(int old, int nw) {
		if(old == nw) return;
		int cnt = pos[old].size() + pos[nw].size();
		if(pos[old].size() > pos[nw].size()) swap(pos[old], pos[nw]);
		if(pos[old].size() + pos[nw].size() != cnt) cout << "FUCK -1 (this shouldn't be possible)" << endl;
		for(int& k:pos[old]) pos[nw].pb(k);
		pos[old].clear();
		if(pos[old].size() != 0) cout << "WHATTHEFUCK????" << endl;
		if(pos[nw].size() != cnt) cout << "FUCK 1" << endl;
	}
	void rebuild(int L, int R, int old, int nw) {
		vector<int> ar(S);
		int cnt = 0, cnt2 = 0;
		rep1(i, 100) {
			for(int& k:pos[i]) ar[k-Bg] = i, cnt++;
			pos[i].clear();
		}
		iter(i, Bg, Bg+S) {
			if(L <= i && i <= R && ar[i-Bg] == old) ar[i-Bg] = nw;
			pos[ar[i-Bg]].pb(i); cnt2++;
		}
		if(!(cnt == cnt2)) cout << "FUCK 2" << endl;
	}
};

Chunk chunks[456];

const int csize = 456;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; gi(n);
	rep(i, n) gi(ar[i]);
	for(int idx=0, cid=0; idx<=n; idx+=csize, cid++)
		chunks[cid] = Chunk(idx, min(csize, n-idx));
	int q; gi(q);
	rep(_, q) {
		int l, r, x, y; gi(l), gi(r), gi(x), gi(y);
		l--; r--;
		int cl = l / csize, cr = r / csize;
		if(cl == cr) {
			chunks[cl].rebuild(l, r, x, y);
		} else {
			chunks[cl].rebuild(l, r, x, y);
			chunks[cr].rebuild(l, r, x, y);
			iter(c, cl+1, cr) chunks[c].merg(x, y);
		}
	}
	memset(ar, 0, sizeof ar);
	for(int idx=0, cid=0; idx<=n; idx+=csize, cid++) {
		rep1(i, 100) for(int& k:chunks[cid].pos[i])
			ar[k] = i;
	}
	rep(i, n) print(ar[i]), pc(' ');
}