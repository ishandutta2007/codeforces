#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
const double PI = acos(-1);
// = 5e5 + 17;
const int MOD1 = 998244353;
const int MOD = 1000000007;
const int INF = 1e9;
const int MaXN = 150;
const int N = 1e8 + 1000;
const int LOG = 25;
const int FACT = 120;

mt19937 rng(239);
typedef uint64_t ull;
uniform_int_distribution<ull> nextRand(0, (1LL << 62) - 1);
int root = 3;

template<class A, class B>
void sum(A &a, B b) {
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}

ll add(ll a, ll b) {
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;

}

int to_i(char c) {
    return c - 'a';
}

ll mult(ll a, ll b) {
    ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll gcd_eu(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0LL;
        y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll poww(ll a, ll b) {
    ll val = 1;
    a %= MOD;
    while (b > 0) {
        if (b % 2) val = mult(a, val);
        a = mult(a, a);
        b >>= 1;
    }
    return val % MOD;
}

ll inv(ll a) {
    return poww(a, MOD - 2);
}

int gcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1 = 0, y1 = 0;
    ll d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

__int128 fact[32];

ll bin(int n, int k) {
    if (k > n) return 0;
    return fact[n] / fact[n - k] / fact[k];
}

ll calc(int n, int x) {
    __int128 prod = 1, znam = 1;
    for (int i = 0; i < x; i++) {
        prod *= (n - i);
        znam *= (i + 1);
    }
    return prod / znam;
}

int cnt = 0;

bool check(const vector<int> &a) {
    for (auto start: a) {
        int steps = 0;
        while ((start != 0 || !steps) && steps < a.size()) {
            steps++;
            start = a[start];
        }
        if (start) return 0;
    }
    return true;
}

void rec(const vector<int> &a, const vector<int> &cur, int k) {
    if (!k) {
        if (check(cur)) cnt++;
        return;
    }
    for (auto x: a) {
        vector<int> p = cur;
        p.pb(x);
        rec(a, p, k - 1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<int> a(k);
    iota(a.begin(), a.begin() + k, 0);
    rec(a,{},  k);
    cout << mult(cnt, poww(n - k, n - k)) << "\n";
    //cout << check({0, 0}) << "\n";
    return 0;
}