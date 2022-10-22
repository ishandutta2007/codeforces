#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <chrono>
#include <random>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define fi first
#define se second
#define il inline
#define Ld double
#define rg register
#define ll long long
#define lll __int128
#define pb push_back
#define mp make_pair
#define It ::iterator
#define W(p) while(p--)
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pii pair<int, int>
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define def(N, b) const int N = b;
#define FOR(i, b, s) for(int i = b; i < s; ++i) 
#define rep(i, b, s) for(int i = b; i <= s; ++i)
#define per(i, b, s) for(int i = b; i >= s; --i)
#define FOR_(i, b, s) for(int i = b; i > s; --i) 
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

namespace IO {
    const int SIZE = (1 << 20) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE],*oS = obuf, *oT = obuf + SIZE - 1;
    char _st[55];
    int _qr = 0;
    inline char gc() {
        return (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++) : *iS++);
    }
    inline void qread() {}
    template<class T1, class ...T2>
    inline void qread(T1 &IEE, T2&... ls) {
        register T1 __ = 0, ___ = 1;
        register char ch;
        while(!isdigit(ch = gc())) ___ = (ch == '-') ? -___ : ___;
        do {
            __ = (__ << 1) + (__ << 3) + (ch ^ 48);
        }while(isdigit(ch = gc()));
        __ *= ___;
        IEE = __;
        qread(ls...);
        return ;
    }
    template<class T>
	inline void QreadArr(T Begin, T End) {
		while(Begin != End) {
			qread(*Begin);
			++Begin;
		}
	}
    inline void flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
        return ;
    }
    inline void putc_(char _x) {
        *oS++ = _x;
        if(oS == oT) flush();
    }
    inline void qwrite() {}
    template<class T1, class ...T2>
    inline void qwrite(T1 IEE, T2... ls) {
        if(!IEE) putc_('0');
        if(IEE < 0) putc_('-'), IEE = -IEE;
        while(IEE) _st[++_qr] = IEE % 10 + '0', IEE /= 10;
        while(_qr) putc_(_st[_qr--]);
        qwrite(ls...);
        return ;
    }
    template<class T>
    inline void WriteArr(T Begin, T End) {
    	const char Kg = ' ', Edl = '\n';
    	while(Begin != End) {
    		qwrite(*Begin);
    		++Begin;
    		putc_(Kg);
		}
		putc_(Edl);
	}
    struct Flusher_{ ~Flusher_() { flush(); } } io_flusher;
}

using namespace IO;
using namespace std;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll My_Rand(ll Mod) { return (ull)(rnd()) % Mod; }

template<class T1, class T2>
void Min(const T1 x, const T2 y) { return x > y ? y : x; }
template<class T1, class T2>
void Max(const T1 x, const T2 y) { return x > y ? x : y; }

template<class T1, class T2>
void To_max(T1 &x, const T2 y) { x < y ? x = y : x = x; }
template<class T1, class T2>
void To_min(T1 &x, const T2 y) { x > y ? x = y : x = x; }

il ll qpow(ll n, ll base, ll mod = 1e18) {
	ll ret = 1;
	while(n) {
		if(n & 1) ret = ret * base % mod;
		base = base * base % mod;
		n >>= 1;
	}
	return ret % mod;
}

il ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }
il ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
//header

def(N, 2.5e5 + 5)
def(M, 405)

ll n, m, ans;
ll a[N], s[N], t[N], c[N], r[N];
ll dp[M][M][2];
vector<int> v[N];
 
int main() {
	qread(n, m);
	rep(i, 1, n) qread(a[i]);
	rep(i, 1, m) {
		qread(s[i], t[i], c[i], r[i]);
		++r[i];
		To_min(r[i], t[i] - s[i]);
		v[r[i]].pb(i);
	}
	memset(dp, 0x3f, sizeof dp);
	rep(i, 1, n) rep(j, i, n) dp[i][j][1] = a[j] - a[i];
	rep(l, 2, n) {
		for(auto i : v[l - 1]) To_max(ans, dp[s[i]][t[i]][(l - 1) & 1] * c[i]);
		rep(i, 1, n) {
			dp[i][i][l & 1] = 0;
			int k = i;
			rep(j, i + 1, n) {
				while(dp[i][k][(l - 1) & 1] < a[j] - a[k]) ++k;
				dp[i][j][l & 1] = min(dp[i][k][(l - 1) & 1], a[j] - a[k - 1]);
			}
		}
	}
	printf("%lld\n", ans);
 	return 0;
}