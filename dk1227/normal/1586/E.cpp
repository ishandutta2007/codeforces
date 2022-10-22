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
#include <cassert>
#include <iostream>
#include <algorithm>
#include <unordered_map>

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
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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

namespace Comb {
	def(SIZ, int, 1e6 + 5)
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
	
	ll C(int n, int m) { return ((fac[n] * Inv[n - m]) % p) * Inv[m] % p; }
}

using namespace IO;
using namespace std;

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

void InitHash(ull &base, int &prime, ull &mod) { base = 131, prime = 233317, mod = 212370440130137957ll; } 
//header

def(N, int, 3e5 + 5)

int n, m;
int head[N], cnt;
pii E[N << 1];
bool vis[N];
int dep[N], fa[N][21];
vector<int> e[N];
int x[N], y[N];
int cn[N], ans[N];
int as[N], tot;

void Add(int u, int v) {
	E[++cnt] = mp(v, head[u]);
	head[u]	= cnt;
}

void dfs(int u) {
	vis[u] = 1;
	for(int i = head[u]; i; i = E[i].se) {
		int v = E[i].fi;
		if(!vis[v]) {
			e[u].pb(v), e[v].pb(u);
			dfs(v);
		}
	}
}

void dfs2(int u, int Fa) {
	dep[u] = dep[Fa] + 1;
	fa[u][0] = Fa;
	rep(i, 1, 20) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for(int v : e[u]) {
		if(v != Fa) dfs2(v, u);
	}
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	int t = dep[x] - dep[y];
	rep(i, 0, 20) if(t & (1 << i)) x = fa[x][i];
	if(x == y) return x;
	per(i, 20, 0) if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

void jump(int i, int x, int f) {
	while(x != f) {
		++ans[i];
		++cn[x];
		x = fa[x][0];
	}
}

void jump2(int x, int f) {
	while(x != f) {
		cout << x << ' ';
		x = fa[x][0];
	}
}

void jump3(int x, int f) {
//	puts("qwq");
	tot = 0;
	while(x != f) {
		as[++tot] = x;
		x = fa[x][0];
	}
	as[++tot] = f;
	reverse(as + 1, as + tot + 1);
	rep(i, 1, tot) cout << as[i] << ' ';
}

void solve(int i, int x, int y) {
	int lca = LCA(x, y);
	jump(i, x, lca), jump(i, y, lca);
}

int check() {
	int ret = 0;
	rep(i, 1, n) {
		ll nw = 0;
		for(int v : e[i]) {
			if(fa[v][0] == i) nw += cn[v];
			else nw += cn[i];
		}
		if(nw & 1) ++ret;
	}
	return ret;
}

int main() {
	qread(n, m);
	rep(i, 1, m) {
		int u, v;
		qread(u, v);
		Add(u, v), Add(v, u);
	}
	dfs(1);
	dfs2(1, 0);
	int q; qread(q);
	rep(i, 1, q) {
		qread(x[i], y[i]);
		solve(i, x[i], y[i]);
	}
	int res = check();
	if(!res) {
		puts("YES");
		rep(i, 1, q) {
			cout << ans[i] + 1 << endl;
			int lca = LCA(x[i], y[i]);
			jump2(x[i], lca);
			jump3(y[i], lca);
			cout << endl;
		}
	}
	else {
		puts("NO");
		cout << res / 2 << endl;
	}
	return 0;
}