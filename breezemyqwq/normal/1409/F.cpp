// tou xi
#include <bits/stdc++.h>

#define fi first
#define se second
#define pc putchar
#define ll long long
#define pb push_back
#define mp make_pair
#define W(p) while(p--)
#define pii pair<int, int>
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define def(N, K, b) const K N = b;
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

namespace IO {
    const int SIZE = (1 << 20) + 1;
    char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = obuf + SIZE - 1;
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
    struct Flusher_{ ~Flusher_() { flush(); } } io_flusher;
}

using namespace IO;
using namespace std;

namespace Comb {
	def(SIZ, int, 1.1e6 + 5);
	int p;
	
	ll inv[SIZ], fac[SIZ], Inv[SIZ];
	
	void init(int mod) {
		p = mod;
		inv[0] = fac[0] = Inv[0] = inv[1] = fac[1] = Inv[1] = 1;
		rep(i, 2, SIZ - 1) {
			fac[i] = fac[i - 1] * i % p;
			inv[i] = p - (p / i) * inv[p % i] % p;
			Inv[i] = Inv[i - 1] * inv[i] % p;
		}
	}
	
	ll C(int n, int m) {
		if(n < m || m < 0) return 0;
		return ((fac[n] * Inv[n - m]) % p) * Inv[m] % p;
	}
} using Comb::C;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
ll My_Rand(ll Mod) { return (ull)(rnd()) % Mod; }

template<class T1, class T2>
void To_max(T1 &x, const T2 y) { x < y ? x = y : x = x; }
template<class T1, class T2>
void To_min(T1 &x, const T2 y) { x > y ? x = y : x = x; }

ll qmul(ll x, ll y, ll p) {
	ll l = x * (y >> 25) % p * (1 << 25) % p;
	ll r = x * (y & ((1 << 25) - 1)) % p;
	return (l + r) % p;
}

ll qpow(ll n, ll base, ll mod = 1e18) {
	ll ret = 1;
	while(n) {
		if(n & 1) ret = ret * base % mod;
		base = base * base % mod;
		n >>= 1;
	}
	return ret % mod;
}

ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

void InitHash(ull &base, int &prime, ull &mod) { base = 131, prime = 233317, mod = 212370440130137957ll; } 
//header

const int N = 205;

int n, k;
string s, t;
int dp[N][N][N];

int main() {
	cin >> n >> k;
	cin >> s >> t; s = ' ' + s;
	memset(dp, -0x3f, sizeof dp);
	dp[0][0][0] = 0;
	rep(i, 1, n) rep(j, 0, k) rep(l, 0, n) {
		if(s[i] == t[0]) {
			if(l) To_max(dp[i][j][l], dp[i - 1][j][l - 1] + (t[0] == t[1] ? l - 1 : 0));
		}
		else {
			if(j && l) To_max(dp[i][j][l], dp[i - 1][j - 1][l - 1] + (t[0] == t[1] ? l - 1 : 0));
			To_max(dp[i][j][l], dp[i - 1][j][l] + (s[i] == t[1] ? l : 0));
		}
		
		if(s[i] == t[1]) {
			if(t[0] == t[1] && l) To_max(dp[i][j][l], dp[i - 1][j][l - 1] + l - 1);
			else To_max(dp[i][j][l], dp[i - 1][j][l] + l);
		}
		else {
			if(j) {
				if(t[0] == t[1] && l) To_max(dp[i][j][l], dp[i - 1][j - 1][l - 1] + l - 1);
				else To_max(dp[i][j][l], dp[i - 1][j - 1][l] + l);
			}
			if(s[i] != t[0] || l) To_max(dp[i][j][l], dp[i - 1][j][l - (t[0] == s[i])]);
		}
	}
	// cout << dp[12][0][1] << '\n';
	int ans = 0;
	rep(i, 0, k) rep(j, 0, n) To_max(ans, dp[n][i][j]);
	cout << ans << '\n'; 
	return 0;
}