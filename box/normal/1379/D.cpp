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

class SST {
public:
    int dep, sum;
    SST* ch[2];
    SST(int dep) : dep(dep), sum(0) {
        ch[0] = nullptr;
        ch[1] = nullptr;
    }
    ~SST() {
        if (ch[0])
            delete ch[0];
        if (ch[1])
            delete ch[1];
    }
    void inc(int val, int diff) {
        sum += diff;
        if (!dep)
            return;
        bool cv = val & (1 << (dep - 1));
        if (!ch[cv])
            ch[cv] = new SST(dep - 1);
        ch[cv]->inc(val, diff);
    }
    int psum(int val) {
        if (!dep)
            return sum;
        int ans = 0;
        bool cv = val & (1 << (dep - 1));
        if (ch[cv])
            ans = ch[cv]->psum(val);
        if (cv && ch[0])
            ans += ch[0]->sum;
        return ans;
    }
    inline int rank(int val) { return psum(val - 1) + 1; }
    int irank(int rank, int pre) {
        if (!dep)
            return pre;
        int left = 0;
        if (ch[0])
            left = ch[0]->sum;
        if (rank <= left)
            return ch[0]->irank(rank, pre);
        else
            return ch[1]->irank(rank - left, pre + (1 << (dep - 1)));
    }
    inline int irank(int rank) { return irank(rank, 0); }
};

int n, h, m, k;
int t[100005];
SST* rrr = new SST(30);
int test(int tm) {
	// get everything between tm+1 and tm+k-1 inclusive
	return rrr->psum(tm+k-1) - rrr->psum(tm);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> h >> m >> k;
	set<int> crucial;
	rep(i, n) {
		int a, b; cin >> a >> b;
		b %= (m / 2);
		t[i] = b;
		rrr->inc(b, 1);
		rrr->inc(b+m/2, 1);
		crucial.insert((b-k+1+m/2)%(m/2));
		crucial.insert((b-k+m/2)%(m/2));
		crucial.insert((b-k-1+m/2)%(m/2));
		crucial.insert((b-1+m/2)%(m/2));
		crucial.insert(b);
		crucial.insert((b+1)%(m/2));
		crucial.insert((b+k-1+m/2)%(m/2));
		crucial.insert((b+k)%(m/2));
		crucial.insert((b+k+1)%(m/2));
	}
	int best = -1, bestv = 10000000;
	for(auto k:crucial) {
		int p = test(k);
		if(p < bestv) {
			bestv = p;
			best = k;
		}
	}
	cout << bestv << ' ' << (best+k)%(m/2) << endl;
	rep(i, n) if((best + 1 <= t[i] && t[i] <= best + k -1) || (best + 1 <= t[i] + (m/2) && t[i] + (m/2) <= best + k -1)) cout << i+1 << ' ';
}