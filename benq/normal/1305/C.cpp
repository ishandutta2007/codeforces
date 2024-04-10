//
// Created by   on 28.10.2019.
//
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf_int = 1e9 + 100;
const ll inf_ll = 1e18;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double dbl;
#define pb push_back
#define eb emplace_back
const double pi = 3.1415926535898;
#define dout if(debug) cout
#define fi first
#define se second
#define sp setprecision
#define sz(a) (int(a.size()))
#define mp make_pair
#define all(a) a.begin(),a.end()
bool debug = 0;
const int MAXN = 2e5 + 100;
const int LOG = 21;
const int mod = 1e9 + 7;
const int MX = (1e7 + 100) * 1.5;
typedef long long li;
 
template<class T1, class T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &rhs) {
    out << "( " << rhs.first << " , " << rhs.second << " )";
    return out;
}
 
template<typename A, typename B>
string to_string(pair<A, B> p);
 
template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template<typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string &s) {
    return '"' + s + '"';
}
 
string to_string(const char *s) {
    return to_string((string) s);
}
 
string to_string(bool b) {
    return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
 
template<size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
 
template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
 
template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template<typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " +
           to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
 
#ifdef zxc
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
 
int a[MAXN];
 
int cnt[MAXN];
 
ll bin_pow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}
 
ll inc[MAXN];
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vals;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        vals.pb(a[i]);
    }
    sort(all(vals));
    for (int v : vals) {
        int x = v % m;
        for (int j = 0; j < m; ++j) {
            inc[x - j + m] += cnt[j];
        }
        cnt[x]++;
    }
    ll ans = 1;
 
    for (int i = 0; i < 3 * m; ++i) {
        if (inc[i]) {
            ll val = i % m;
            ans = (ans * bin_pow(val, inc[i], m));
            ans %= m;
        }
    }
 
 
    cout << ans << "\n";
 
}
 
signed main() {
#ifdef zxc
    freopen("../input.txt", "r", stdin);
    //    freopen("../output.txt", "w", stdout);
#else
#endif //zxc
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.precision(15);
 
    int t = 1;
    while (t--)
        solve();
    debug(1.0 * clock() / CLOCKS_PER_SEC);
}