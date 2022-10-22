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

def(N, int, 1e4 + 5)

int n, qwq, qaq;
bool ff, f;
int a[N];
int mn[N], mx[N];

il int get(int t, int i, int j, int x) {
	int ret;
    printf("? %lld %lld %lld %lld", t, i, j, x);
    cout << endl;
    cin >> ret;
    return ret;
}

void get1(int i, int j) {
    int ans = get(2, i, j, 1);
    mn[i] = ans;
    if (ans == 1) {
        qaq = i;
        f = 1;
    }
    if (ans == 2) {
        ans = get(2, j, i, 1);
        if (ans == 1) {
            qaq = j;
            f = 1;
        }
    }
}

void get2(int i, int j) {
    int ans = get(1, i, j, n - 1);
    mx[i] = ans;
    if (ans == n) {
        qwq = j;
        ff = 1;
    }
    if (ans == n - 1) {
        ans = get(1, j, i, n - 1);
        if (ans == n) {
            qwq = i;
            ff = 1;
        }
    }
}

void getans(int i, int j) {
    if (j == qaq) {
        a[j] = 1;
        int ans = get(1, j, i, n - 1);
        a[i] = ans;
        return;
    }

	if (i == qwq) {
        a[i] = n;
        int ans = get(2, j, i, 1);
        a[j] = ans;
        return;
    }

	if (j == qwq) {
        a[j] = n;
        int ans = get(2, i, j, 1);
        a[i] = ans;
        return;
    }
    
	if (i == qaq) {
        a[i] = 1;
        int ans = get(1, i, j, n - 1);
        a[j] = ans;
        return;
    }
    
    int ans = get(1, i, j, mn[i]);
    if (ans == mn[i]) a[i] = mx[i], a[j] = mn[i];
    else a[i] = mn[i], a[j] = mx[i];
}

void report() {
	cout << "! ";
	rep(i, 1, n) cout << a[i] << " ";
	cout << endl;
}

signed main() {
    int T; cin >> T;
    W(T) {
    	cin >> n;
    	rep(i, 1, n) a[i] = mn[i] = mx[i] = 0;
	    qwq = qaq = f = ff = 0;
	    for (int i = 1; i < n; i += 2) get2(i, i + 1);
	    get2(n, 1);
	    
	    for (int i = 1; i < n; i += 2) get1(i, i + 1);
	    get1(n, 1);
	
	    for (int i = 1; i < n; i += 2) getans(i, i + 1);
		getans(n, 1);
		
		report();
	}
	return 0;
}