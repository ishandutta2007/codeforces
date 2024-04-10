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

pii sp[15][15][15][15][3][3];
pii ind[105];
pii dp[105][3];

int kx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ky[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int rx[4] = {0, 1, 0, -1};
int ry[4] = {1, 0, -1, 0};

int bx[4] = {1, 1, -1, -1};
int by[4] = {1, -1, -1, 1};

inline pii ad(pii& a, pii& b) { return {a.fi + b.fi, a.se + b.se}; }

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; gi(n);
	memset(sp, 0x1f, sizeof sp);
	rep(i, n) rep(j, n) rep(d, 3) rep(d2, 3) sp[i][j][i][j][d][d2] = {1, 1};
	rep(i, n) rep(j, n) rep(d, 3) sp[i][j][i][j][d][d] = {0, 0};
	// knight
	rep(i, n)
		rep(j, n)
			rep(d, 8)
				if(0 <= i+kx[d] && i+kx[d] < n && 0 <= j+ky[d] && j+ky[d] < n) 
					sp[i][j][i+kx[d]][j+ky[d]][0][0] = {1, 0};
	// rook
	rep(i, n)
		rep(j, n)
			rep(d, 4)
				rep(p, 10) 
					if(0 <= i+p*rx[d] && i+p*rx[d] < n && 0 <= j+p*ry[d] && j+p*ry[d] < n) 
						sp[i][j][i+p*rx[d]][j+p*ry[d]][1][1] = {1, 0};
	// bishop
	rep(i, n)
		rep(j, n)
			rep(d, 4)
				rep(p, 10)
					if(0 <= i+p*bx[d] && i+p*bx[d] < n && 0 <= j+p*by[d] && j+p*by[d] < n) 
						sp[i][j][i+p*bx[d]][j+p*by[d]][2][2] = {1, 0};
	rep(ki, n)
		rep(kj, n)
			rep(kd, 3)
				rep(ii, n)
					rep(ij, n)
						rep(id, 3)
							rep(ji, n)
								rep(jj, n)
									rep(jd, 3)
sp[ii][ij][ji][jj][id][jd] = min(sp[ii][ij][ji][jj][id][jd], ad(sp[ii][ij][ki][kj][id][kd], sp[ki][kj][ji][jj][kd][jd]));	
	rep(d, 3) dp[1][d] = {0, 0};
	rep(i, n)
		rep(j, n) {
			int v; gi(v);
			ind[v] = {i, j};
		}
	iter(i, 2, n*n+1) {
		rep(d, 3) dp[i][d] = {0x3f3f3f3f, 0x3f3f3f3f};
		rep(p, 3)
			rep(d, 3)
				dp[i][d] = min(dp[i][d], ad(dp[i-1][p], sp[ind[i-1].fi][ind[i-1].se][ind[i].fi][ind[i].se][p][d]));
	}
	pii b = min(min(dp[n*n][0], dp[n*n][1]), dp[n*n][2]);
	print(b.fi), pc(' '), print(b.se);
}