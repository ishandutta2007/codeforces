#include <bits/stdc++.h>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); --i)
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
const int FFTMOD = 119 << 23 | 1;
const int INF = (int) 1e9 + 23111992;
const ll LINF = (ll) 1e18 + 23111992;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ull isqrt(ull k) {ull r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
mt19937 mt(chrono::high_resolution_clock::now().time_since_epoch().count());
inline int myrand() {return abs((int) mt());}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 2e5 + 5;
int n;
string s[maxn];

void chemthan() {
    cin >> n;
    vi f(26);
    FOR(i, 0, n) {
        cin >> s[i];
        for (char& c : s[i]) c -= 'a';
    }
    int cnt = 0, pv = -1;
    FOR(i, 0, sz(s[0])) {
        if (pv == -1) {
            pv = s[0][i];
            cnt = 1;
        }
        else if (pv != s[0][i]) {
            chkmax(f[pv], cnt);
            pv = s[0][i];
            cnt = 1;
        }
        else {
            cnt++;
        }
    }
    chkmax(f[pv], cnt);
    FOR(i, 1, n) {
        vi nf(26);
        FOR(j, 0, 26) {
            chkmax(nf[j], (int) (!!f[j]));
        }
        int cnt = 0, pv = -1;
        FOR(j, 0, sz(s[i])) {
            if (pv == -1) {
                pv = s[i][j];
                cnt = 1;
            }
            else if (pv != s[i][j]) {
                chkmax(nf[pv], cnt);
                pv = s[i][j];
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        chkmax(nf[pv], cnt);
        int l = 1, r = 1;
        while (l < sz(s[i]) && s[i][l - 1] == s[i][l]) l++;
        reverse(all(s[i]));
        while (r < sz(s[i]) && s[i][r - 1] == s[i][r]) r++;
        reverse(all(s[i]));
        if (l == sz(s[i])) {
            chkmax(nf[s[i][0]], (f[s[i][0]] + 1) * sz(s[i]) + f[s[i][0]]);
        }
        chkmax(nf[s[i][0]], !!f[s[i][0]] + l);
        chkmax(nf[s[i].back()], !!f[s[i].back()] + r);
        if (s[i][0] == s[i].back() && l < sz(s[i]) && f[s[i][0]]) {
            chkmax(nf[s[i][0]], !!f[s[i][0]] + l + r);
        }
        f = nf;
    }
    cout << *max_element(all(f)) << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
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