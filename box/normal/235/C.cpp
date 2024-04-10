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
	inline int gstr (char *s) { int re = 0; for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c, re++; *s = 0; return re; }
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

namespace SAM {
	constexpr int MAXN = 1000006;
	constexpr int MAXT = 26;
	struct state {
		int len, lnk;
		int nxt[MAXT];
	} st[MAXN*2];
	int sz, last;
	int mknode(int fro = -1) {
		int nd = sz++;
		if(fro == -1) memset(st[nd].nxt, -1, sizeof st[nd].nxt);
		else {
			memcpy(st[nd].nxt, st[fro].nxt, sizeof st[fro].nxt);
			st[nd].lnk = st[fro].lnk;
		}
		return nd;
	}
	void init() {
		sz = last = 0;
		mknode(); st[0].len = 0, st[0].lnk = -1;
	}
	int cnt[MAXN*2], nodeat[MAXN*2];
	void ext(int c) {
		int cur = mknode(); cnt[cur] = 1;
		st[cur].len = st[last].len+1;
		int p = last;
		while(p != -1 && st[p].nxt[c] == -1) st[p].nxt[c] = cur, p = st[p].lnk;
		if(p == -1) st[cur].lnk = 0;
		else {
			int q = st[p].nxt[c];
			if(st[p].len + 1 == st[q].len) st[cur].lnk = q;
			else {
				int cl = mknode(q);
				st[cl].len = st[p].len + 1; st[cur].lnk = st[q].lnk = cl;
				while(p != -1 && st[p].nxt[c] == q) st[p].nxt[c] = cl, p = st[p].lnk;
			}
		}
		last = cur;
	}
	int seq[MAXN*2];
	void mkcnt() {
		rep(i, sz-1) seq[i] = i+1;
		sort(seq, seq+sz-1, [&](const int&l,const int&r){return st[l].len>st[r].len;});
		rep(i, sz-1) cnt[st[seq[i]].lnk]+=cnt[seq[i]];
	}
}

char buf[1000006];
int q[1000006];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    SAM::init();
	int l = gstr(buf);
	rep(i, l) SAM::ext(buf[i]-'a');
	SAM::mkcnt();
	int n; gi(n);
	while(n--) {
		ll ans=0; int at=0, l=gstr(buf), cl=0, lef=0, rig=0;
		rep(i, l) q[rig++] = buf[i]-'a';
		rep(i, l) {
			while(lef < rig && SAM::st[at].nxt[q[lef]] != -1) { at = SAM::st[at].nxt[q[lef++]]; cl++; }
			if(lef == rig && SAM::nodeat[at] != n+1) ans += SAM::cnt[at], SAM::nodeat[at] = n+1;
			int be = SAM::st[at].lnk;
			if(SAM::st[be].len == cl-1) at = be;
			cl--; q[rig++] = buf[i]-'a';
		}
		print(ans);pc('\n');
	}
}