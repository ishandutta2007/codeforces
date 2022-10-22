// sir u r right, but plz supot Botswana thx
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
        T1 __ = 0, ___ = 1;
        char ch;
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

def(N, int, 3e5 + 5)
def(inf, int, 0x3f3f3f3f)

struct SegTree {
	#define ls id << 1
	#define rs id << 1 | 1
	#define mid (l + r >> 1)
	
	int s[N << 2];
	
	void build(int id, int l, int r) {
		s[id] = inf;
		if(l == r) return ;
		build(ls, l, mid), build(rs, mid + 1, r);
	}
	
	void upd(int id, int l, int r, int x, int v) {
		if(l == r) {
			s[id] = v;
			return ;
		}
		if(mid >= x) upd(ls, l, mid, x, v);
		else upd(rs, mid + 1, r, x, v);
		s[id] = min(s[ls], s[rs]);
	}
	
	int qry(int id, int l, int r, int x, int y) {
		if(x > y || l > y || r < x) return inf;
		if(x <= l && r <= y) return s[id];
		int res = inf;
		if(mid >= x) To_min(res, qry(ls, l, mid, x, y));
		if(mid < y) To_min(res, qry(rs, mid + 1, r, x, y));
		return res;
	}
} t[2];

int n, m;
int a[N], f[N];

void Main() {
	qread(n);
	rep(i, 1, n) f[i] = inf, qread(a[i]);
	f[1] = 0;
	rep(i, 0, 1) t[i].build(1, 1, n);
	rep(i, 0, 1) t[i].upd(1, 1, n, 1, 0);
	stack<int> s[2];
	rep(i, 1, n) {
		vector<int> v[2];
		while(s[0].size() && a[i] > a[s[0].top()]) v[0].pb(s[0].top()), s[0].pop();
		while(s[1].size() && a[i] < a[s[1].top()]) v[1].pb(s[1].top()), s[1].pop();
		if(i > 1) {
			f[i] = min(t[0].qry(1, 1, n, (s[1].size() ? s[1].top() : 0) + 1, i - 1), t[1].qry(1, 1, n, (s[0].size() ? s[0].top() : 0) + 1, i - 1)) + 1;
			for(int x : v[0]) t[0].upd(1, 1, n, x, inf);
			for(int x : v[1]) t[1].upd(1, 1, n, x, inf);
			rep(j, 0, 1) t[j].upd(1, 1, n, i, f[i]);
		}
		rep(j, 0, 1) s[j].push(i);
	}
	cout << f[n] << '\n';
}

int main() {
	int T = 1;
	cin >> T;
	W(T) Main();
	return 0;
}