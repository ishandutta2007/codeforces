#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define FORalld(it, a) for (__typeof((a).rbegin()) it = (a).rbegin(); it != (a).rend(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
template<class T> inline T isqrt(T k) {T r = sqrt(k) + 1; while (r * r > k) r--; return r;}
template<class T> inline T icbrt(T k) {T r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}

template<class T> struct VECTOR {
	int limit, cnt;
	T* buf;
	VECTOR() {
		buf = (T*) calloc(1, sizeof(T));
		limit = 1, cnt = 0;
	}
	void enlarge() {
		limit <<= 1;
		buf = (T*) realloc(buf, sizeof(T) * limit);
	}
	void push_back(T val) {
		if (cnt == limit) enlarge();
		buf[cnt++] = val;
	}
	void push_back() {
		if (cnt) cnt--;
	}
	T& back() {
		return *(buf + cnt - 1);
	}
	int size() {
		return cnt;
	}
	void clear() {
		free(buf);
		buf = (T*) calloc(1, sizeof(T));
		limit = 1, cnt = 0;
	}
	T& operator [] (const int& i) {
		return *(buf + i);
	}
};
template<class T> int upper_bound(VECTOR<T>& v, T val) {
	int l = 0, r = v.size();
	while (l < r) {
		int m = l + r >> 1;
		if (v[m] <= val) {
			l = m + 1;
		}
		else {
			r = m;
		}
	}
	return l;
}
#define vector VECTOR
template<class T> struct CascadingSegment {
    struct Info {
        T key;
        int lnxt, rnxt;
        Info() : key(0), lnxt(0), rnxt(0) {}
        Info(T key) : key(key), lnxt(0), rnxt(0) {}
        int operator <= (const Info& rhs) const {
            return key <= rhs.key;
        }
    };
    
    static const int maxn = 1e5 + 5;
    vector<Info> st[maxn << 2];
    
    void clear() {
        for (int i = 0; i < (maxn << 2); i++) {
            st[i].clear();
        }
    }
    void upd(int p, int i, int L, int R, T val) {
        if (i < L || i > R) return;
        int lptr = st[p].size() ? st[p].back().lnxt : 0;
        int rptr = st[p].size() ? st[p].back().rnxt : 0;
        st[p].push_back(Info(val));
        if (L < R) {
            upd(p << 1, i, L, L + R >> 1, val);
            upd(p << 1 | 1, i, (L + R >> 1) + 1, R, val);
            while (lptr < st[p << 1].size() && val >= st[p << 1][lptr].key) lptr++;
            while (rptr < st[p << 1 | 1].size() && val >= st[p << 1 | 1][rptr].key) rptr++;
            st[p].back().lnxt  = lptr, st[p].back().rnxt = rptr;
        }
    }
    
    int query(int p, int l, int r, int L, int R, T val) {
        if (l > R || r < L) return -INF;
        if (p == 1) {
            int k = upper_bound(st[p], Info(val)) - 1;
            if (!~k) return -INF;
            if (l <= L && r >= R) return st[p][k].key;
            return max(query(p << 1, l, r, L, L + R >> 1, st[p][k].lnxt - 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R, st[p][k].rnxt - 1));
        }
        if (!~val) return -INF;
        if (l <= L && r >= R) return st[p][val].key;
        return max(query(p << 1, l, r, L, L + R >> 1, st[p][val].lnxt - 1), query(p << 1 | 1, l, r, (L + R >> 1) + 1, R, st[p][val].rnxt - 1));
    }
};
CascadingSegment<int> cs;

const int maxn = 1e5 + 5;
int n, q;
int a[maxn];
int l[maxn * 3];
int r[maxn * 3];
int ans[maxn * 3];
vi g[maxn];

void upd(int fen[], int n, int p, int val) {
    for (; p <= n; p += p & -p) {
        chkmin(fen[p], val);
    }
}
int query(int fen[], int n, int p) {
    int res = INF;
    for (; p > 0; p -= p & -p) {
        chkmin(res, fen[p]);
    }
    return res;
}

int compare(int i, int j) {
    if (l[i] != l[j]) return l[i] > l[j];
    return i > j;
}

void work() {
    cs.clear();
    vi dc; FOR(i, 0, n) dc.pb(a[i]);
    sort(all(dc)), uni(dc);
    FORd(i, n, 0) {
        g[i].clear();
        int val = i + 1, cur = INF + INF;
        while (cur) {
            int l = lower_bound(all(dc), a[i]) - dc.begin();
            int r = upper_bound(all(dc), a[i] + (cur >> 1)) - dc.begin() - 1;
            int k = -cs.query(1, l, r, 0, n - 1, -val);
            if (k < INF) {
                g[i].pb(k);
                val = k + 1, cur = a[k] - a[i];
            }
            else {
                break;
            }
        }
        int k = lower_bound(all(dc), a[i]) - dc.begin();
        cs.upd(1, k, 0, n - 1, -i);
    }
    static int fen[maxn];
    fill_n(fen, n + 1, INF);
    vi v; FOR(i, 0, q) v.pb(i);
    sort(all(v), compare);
    int ptr = n - 1;
    FOR(ii, 0, q) {
        int i = v[ii];
        while (ptr >= l[i]) {
            FOR(j, 0, sz(g[ptr])) {
                int k = g[ptr][j];
                upd(fen, n, k + 1, a[k] - a[ptr]);
            }
            ptr--;
        }
        chkmin(ans[i], query(fen, n, r[i] + 1));
    }
}

void solve() {
    cin >> n;
    FOR(i, 0, n) cin >> a[i];
    cin >> q;
    FOR(i, 0, q) {
        cin >> l[i] >> r[i]; l[i]--, r[i]--;
        ans[i] = INF;
    }
    work();
    FOR(i, 0, n) a[i] *= -1;
    work();
    FOR(i, 0, q) cout << ans[i] << "\n";
}

int main() {
#ifdef _LOCAL_
    freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    solve();
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    return 0;
}