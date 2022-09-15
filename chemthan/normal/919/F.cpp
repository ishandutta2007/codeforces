#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
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
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

template<class TK, class TV> struct HashTable {
    static const int MAXN = 10000000;
    static const int MAGIC = 7654321;
    int ptr;
    int lst[MAGIC];
    int prv[MAXN];
    TK l[MAXN];
    TV x[MAXN];
    int cnt;
    int used[MAGIC];
    
    HashTable() {
        ptr = 0;
        fill_n(lst, MAGIC, -1);
        cnt = 0;
    }
    void clear() {
        ptr = 0;
        for (int i = 0; i < cnt; i++) {
            lst[used[i]] = -1;
        }
        cnt = 0;
    }
    TV& operator [] (const TK& key) {
        int hs = (key % MAGIC + MAGIC) % MAGIC;
        if (!~lst[hs]) {
            used[cnt++] = hs;
        }
        for (int e = lst[hs]; ~e; e = prv[e]) {
            if (l[e] == key) {
                return x[e];
            }
        }
        l[ptr] = key, x[ptr] = 0;
        prv[ptr] = lst[hs], lst[hs] = ptr;
        return x[ptr++];
    }
    int count(TK key) {
        int hs = (key % MAGIC + MAGIC) % MAGIC;
        for (int e = lst[hs]; ~e; e = prv[e]) {
            if (l[e] == key) {
                return 1;
            }
        }
        return 0;
    }
    void erase(TK key) {
        int hs = (key % MAGIC + MAGIC) % MAGIC;
        int nxt = -1;
        for (int e = lst[hs]; ~e; e = prv[e]) {
            if (l[e] == key) {
                if (!~nxt) {
                    lst[hs] = prv[e];
                }
                else {
                    prv[nxt] = prv[e];
                }
                return;
            }
            nxt = e;
        }
    }
};

HashTable<long long, int> hs;
int dp[1000000];
int cnt;

int query(vi a, vi b) {
    long long t = 0;
    FOR(i, 0, sz(a)) {
        t = t * 9 + a[i];
    }
    FOR(i, 0, sz(b)) {
        t = t * 9 + b[i];
    }
    if (hs.count(t)) return hs[t];
    int res = cnt++;
    return hs[t] = res;
}

void chemthan() {
    ms(dp, -1);
    queue<vi> que;
    FOR(i1, 0, 5) FOR(i2, i1, 5) FOR(i3, i2, 5) FOR(i4, i3, 5) FOR(i5, i4, 5) {
        FOR(i6, i5, 5) FOR(i7, i6, 5) FOR(i8, i7, 5) {
            if (i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8) {
                vi a(5), b(5);
                a[i1]++, a[i2]++, a[i3]++, a[i4]++, a[i5]++, a[i6]++, a[i7]++, a[i8]++;
                b[0] = 8;
                int ix = query(a, b);
                dp[ix] = 0;
                que.push(a), que.push(b);
            }
        }
    }
    while (sz(que)) {
        vi a = que.front(); que.pop();
        vi b = que.front(); que.pop();
        auto check = [&] (vi a, vi b) {
            int ix1 = query(a, b);
            if (dp[ix1] != -1) {
                return;
            }
            int found = 0;
            FOR(i, 1, 5) FOR(j, 1, 5) if (a[i] && b[j]) {
                vi na = a, nb = b;
                na[i]--, na[(i + j) % 5]++;
                int ix2 = query(nb, na);
                if (dp[ix2] == 0) {
                    dp[ix1] = 1;
                    que.push(a), que.push(b);
                    return;
                }
                else if (dp[ix2] == -1) {
                    found = 1;
                }
            }
            if (!found) {
                dp[ix1] = 0;
                que.push(a), que.push(b);
            }
        };
        FOR(i, 1, 5) FOR(j, 0, 5) if (a[i] && b[j]) {
            vi na = a, nb = b;
            nb[j]--, nb[(j - i + 5) % 5]++;
            check(nb, na);
        }
    }
    int test; scanf("%d", &test);
    while (test--) {
        int f;
        vi a(5), b(5);
        scanf("%d", &f);
        FOR(i, 0, 8) {
            int x; scanf("%d", &x);
            a[x]++;
        }
        FOR(i, 0, 8) {
            int x; scanf("%d", &x);
            b[x]++;
        }
        if (!f) {
            int ix = query(a, b);
            if (dp[ix] == 1) {
                puts("Alice");
            }
            else if (dp[ix] == 0) {
                puts("Bob");
            }
            else {
                puts("Deal");
            }
        }
        else {
            int ix = query(b, a);
            if (dp[ix] == 0) {
                puts("Alice");
            }
            else if (dp[ix] == 1) {
                puts("Bob");
            }
            else {
                puts("Deal");
            }
        }
    }
}

int main(int argc, char* argv[]) {
    //ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    chemthan();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}