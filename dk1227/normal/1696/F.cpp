// sir u r right, but plz supot Botswana thx
#pragma GCC optimize(2, 3, "Ofast", "unroll-loops")
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

def(N, int, 105)

int n;
bool d[N][N][N];
int fa[N]; vector<int> e[N];
int dis[N][N];
int f[N];

void init() { rep(i, 1, n) f[i] = i; }
int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

void dfs(int tp, int u, int Fa) {
	for(int v : e[u]) if(v != Fa) {
		dis[tp][v] = dis[tp][u] + 1;
		dfs(tp, v, u); 
	}
}

bool slv(int x) {
	memset(fa, 0, sizeof fa);
	queue<int> q;
	rep(i, 1, n) if(d[x][i][1]) fa[i] = 1, q.push(i);
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		rep(i, 2, n) if(d[i][fa[u]][u] && i != 1 && i != fa[u]) {
			if(fa[i]) return 0;
			fa[i] = u;
			q.push(i);
		}
	}
	rep(i, 2, n) if(!fa[i]) return 0;
	init();
	rep(i, 2, n) {
		int fx = find(i), fy = find(fa[i]);
		if(fx == fy) return 0;
		f[fy] = fx;
	}
	int c = 0;
	rep(i, 1, n) if(find(i) == i) ++c;
	if(c != 1) return 0;
	rep(i, 1, n) e[i].clear();
	rep(i, 2, n) e[fa[i]].pb(i), e[i].pb(fa[i]);
	rep(i, 1, n) dfs(i, i, 0);
	rep(i, 1, n) rep(j, 1, n) rep(k, j + 1, n) if((dis[i][j] == dis[i][k]) != d[j][k][i]) return 0;
	return 1;
}

void Main() {
	cin >> n;
	rep(i, 1, n - 1) rep(j, 1, n - i) {
		string s; cin >> s;
		rep(k, 1, n) d[i][i + j][k] = d[i + j][i][k] = s[k - 1] - '0';
	}
	rep(i, 1, n) rep(j, 1, n) d[i][i][j] = 1;
	rep(i, 2, n) if(slv(i)) {
		cout << "Yes\n";
		rep(j, 2, n) cout << fa[j] << ' ' << j << '\n';
		return ;
	}
	cout << "No\n";
}

int main() {
	ios;
	int T = 1;
	cin >> T;
	W(T) Main();
	return 0;
}