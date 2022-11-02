#include <bits/stdc++.h>

#define fi first
#define se second
#define il inline
#define Ld double
#define pc putchar
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
#define def(N, K, b) const K N = b;
#define FOR(i, b, s) for(int i = (b); i < (s); ++i) 
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)
#define FOR_(i, b, s) for(int i = (b); i > (s); --i) 
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

il ll qpow(ll n, ll base, ll mod = 1e18) {
	ll ret = 1;
	while(n) {
		if(n & 1) ret = ret * base % mod;
		base = base * base % mod;
		n >>= 1;
	}
	return ret % mod;
}

namespace strHash {
	def(SIZ, int, 1e6 + 5);
	def(bs, int, 131);
	def(p, int, 1e9 + 7);

	int n;
	ll hp[SIZ];
	ll pw[SIZ];
	
	void init(const string &s) {
		n = s.size() - 1;
		pw[0] = 1;
		rep(i, 1, n) pw[i] = pw[i - 1] * bs % p, hp[i] = (hp[i - 1] * bs % p + s[i] - 'a' + 1) % p;	
	} 
	
	void Init(const char s[]) {
		n = strlen(s + 1);
		pw[0] = 1;
		rep(i, 1, n) pw[i] = pw[i - 1] * bs % p, hp[i] = (hp[i - 1] * bs % p + s[i] - 'a' + 1) % p;	
	}
	
	ll get(int l, int r) {
		ll ret = hp[r];
		ret = (ret - hp[l - 1] * pw[r - l + 1] % p + p) % p;
		return ret;
	}
}

namespace Comb {
	def(SIZ, int, 1e6 + 5);
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
T1 Min(const T1 x, const T2 y) { return x > y ? y : x; }
template<class T1, class T2>
T1 Max(const T1 x, const T2 y) { return x > y ? x : y; }

template<class T1, class T2>
void To_max(T1 &x, const T2 y) { x < y ? x = y : x = x; }
template<class T1, class T2>
void To_min(T1 &x, const T2 y) { x > y ? x = y : x = x; }

il ll qmul(ll x, ll y, ll p) {
	ll l = x * (y >> 25) % p * (1 << 25) % p;
	ll r = x * (y & ((1 << 25) - 1)) % p;
	return (l + r) % p;
}

il ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }
il ll lcm(ll x, ll y) { return x / gcd(x, y) * y; } 

void InitHash(ull &base, int &prime, ull &mod) { base = 131, prime = 233317, mod = 212370440130137957ll; } 
//header

def(N, int, 1e5 + 5)

int n, k;
int a[N];
int las[N];
map<int, int> cnt;
priority_queue<int> q;

int main() {
	int T = 1;
	cin >> T;
	W(T) {
		while(!q.empty()) q.pop();
		int allcnt = 0;
		qread(n, k);
		cnt.clear();
		rep(i, 1, n) {
			qread(a[i]), ++cnt[a[i]];
			allcnt += (cnt[a[i]] == 1);
		}
		int nd = 0, sum = 0;
		rep(i, 0, n) if(cnt.find(i) == cnt.end()) ++nd;
		int ans = 0x3f3f3f3f, sz = cnt.size();
		for(pii x : cnt) if(x.fi > n) q.push(x.se), sum += x.se;
		per(mex, n, 0) {
			if(cnt.find(mex) == cnt.end()) --nd;
			else {
				auto it = cnt.find(mex);
				q.push(it -> se);
				sum += it -> se;
			}
			while(!q.empty() && sum > k) {
				sum -= q.top();
				q.pop();
			}
			if(k >= nd) To_min(ans, (int)(nd + cnt.size() - q.size() - mex));
		}
		cout << min(ans, sz) << '\n';
	}
	return 0;
}