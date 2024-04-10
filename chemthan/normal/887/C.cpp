#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
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

struct myhash {
    int operator () (const vi& v) const {
        long long res = 0;
        for (int x : v) {
            res = res * 6;
            res += x - 1;
        }
        return res;
    }
};

unordered_map<vi, int, myhash> hs;

vi ar(24);
int sq[6][8] = {
    {1, 3, 5, 7, 9, 11, 24, 22},
    {2, 4, 6, 8, 10, 12, 23, 21},
    {13, 14, 5, 6, 17, 18, 21, 22},
    {15, 16, 7, 8, 19, 20, 23, 24},
    {3, 4, 17, 19, 10, 9, 16, 14},
    {1, 2, 18, 20, 12, 11, 15, 13},
};
int sq2[6][4] = {
    {13, 14, 16, 15},
    {18, 17, 19, 20},
    {3, 4, 2, 1},
    {9, 10, 12, 11},
    {5, 6, 8, 7},
    {22, 21, 23, 24},
};

vi rotate(vi& ar, int ix) {
    vi res = ar;
    FOR(i, 0, 8) {
        int j = (i + 2) % 8;
        res[sq[ix][i] - 1] = ar[sq[ix][j]- 1];
    }
    FOR(i, 0, 4) {
        int j = (i + 1) % 4;
        res[sq2[ix][i] - 1] = ar[sq2[ix][j] - 1];
    }
    return res;
}

vi normalize(vi ar) {
    map<int, int> tmp;
    vi res;
    FOR(i, 0, sz(ar)) {
        if (!tmp.count(ar[i])) {
            int id = sz(tmp);
            res.pb(id);
            tmp[ar[i]] = id;
        }
        else {
            res.pb(tmp[ar[i]]);
        }
    }
    return res;
}

void solve() {
    FOR(i, 0, 24) ar[i] = i / 4;
    queue<vi> que;
     que.push(ar);
    while (sz(que)) {
        vi ar = que.front(); que.pop();
        FOR(i, 0, 6) {
            vi nar = rotate(ar, i);
            nar = normalize(nar);
            if (!hs[nar]) {
                hs[nar] = 1, que.push(nar);
            }
        }
        break;
    }
    vi res(24);
    FOR(i, 0, 24) cin >> res[i];
    res = normalize(res);
    FORall(it, hs) {
        vi tmp = it->fi;
        int found = 0;
        FOR(i, 0, 24) FOR(j, i + 1, 24) {
            if (tmp[i] == tmp[j] && res[i] != res[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int JUDGE_ONLINE = 1;
    if (argc > 1) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        JUDGE_ONLINE = 0;
        assert(freopen(argv[2], "wb", stdout));
    }
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}