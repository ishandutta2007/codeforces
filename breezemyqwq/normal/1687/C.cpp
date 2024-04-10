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

namespace Comb {
	def(SIZ, int, 1e6 + 5);
	int p;
	
	ll fac[SIZ], Inv[SIZ];
	
	void init(int sz, int mod) {
		p = mod;
		fac[0] = Inv[0] = fac[1] = Inv[1] = 1;
		rep(i, 2, sz) fac[i] = fac[i - 1] * i % p; Inv[sz] = qpow(mod - 2, fac[sz], mod);
		per(i, sz - 1, 2) Inv[i] = Inv[i + 1] * (i + 1) % p;
	}
	
	inline ll C(int n, int m) { return (n < m || m < 0) ? 0 : fac[n] * Inv[n - m] % p * Inv[m] % p; }
} using Comb::C;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count() + 1);
ll My_Rand(ll Mod) { return (ull)(rnd()) % Mod; }

template<class T1, class T2>
void To_max(T1 &x, const T2 y) { x < y ? x = y : x = x; }
template<class T1, class T2>
void To_min(T1 &x, const T2 y) { x > y ? x = y : x = x; }

void InitHash(ull &base, int &prime, ull &mod) { base = 131, prime = 233317, mod = 212370440130137957ll; } 
//header

def(N, int, 2e5 + 5)

int t1[N], t2[N];

struct cmp {
	bool operator () (const int &x, const int &y) const {
		if(t1[x] != t1[y]) return t1[x] > t1[y];
		if(t2[x] != t2[y]) return t2[x] > t2[y];
		return x > y;
	}
};

int n, m;
int l[N], r[N];
int a[N], b[N], c[N];
ll pre[N];
set<int, cmp> s;
set<int> s1;
vector<int> v[2][N];

int main() {
	int t; cin >> t;
	W(t) {
		s.clear(); s1.clear();
		qread(n, m);
		rep(i, 0, 1) rep(j, 0, n) v[i][j].clear();
		rep(i, 1, n) qread(a[i]);
		rep(i, 1, n) {
			qread(b[i]);
			c[i] = a[i] - b[i];
			pre[i] = pre[i - 1] + c[i];
		}
		rep(i, 0, n) if(pre[i]) s1.insert(i);
		rep(i, 1, m) {
			qread(l[i], r[i]);
			v[0][l[i] - 1].pb(i); v[1][r[i]].pb(i);
			t1[i] = !pre[l[i] - 1];
			t2[i] = !pre[r[i]];
			s.insert(i);
		}
		while(!s.empty()) {
			int u = *s.begin();
			if(!t1[u] || !t2[u]) break;
			
			auto it = s1.lower_bound(l[u] - 1);
			while(it != s1.end() && *it <= r[u]) {
				int nw = *it;
				for(int x : v[0][nw]) {
					s.erase(x);
					t1[x] = 1;
					s.insert(x);
				}
				for(int x : v[1][nw]) {
					s.erase(x);
					t2[x] = 1;
					s.insert(x);
				}
				it = s1.erase(it);
			}
			
			s.erase(u);
		}
		puts(s1.size() ? "NO" : "YES");
	}
	return 0;
}