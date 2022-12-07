#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 998244353;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

int fact[5001], inv[5001];
int n, k;
string s;
vector <int> v;

int comb(int x, int y) {
    if(x < y) return 0;
    if(y == 0) return 1;
    return fact[x] * inv[y] % MOD * inv[x - y] % MOD;
}

void solve() {
    fact[0] = fact[1] = inv[0] = inv[1] = 1;
    forn(i, 2, 5001) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = binpow(fact[i], MOD - 2);
    }
    cin >> n >> k;
    cin >> s;
    forn(i, 0, n) {
        if(s[i] == '1') v.push_back(i);
    }
    if(v.size() < k || k == 0) {
        cout << 1 << endl;
        return;
    }
    if(v.size() == k) {
        cout << comb(n, k) << endl;
        return;
    }
    v.push_back(n);
    int ans = comb(v[k], k);
    for(int i = 1; i + k < v.size(); i++) {
        ans += comb(v[i+k] - v[i-1] - 1, k);
        ans -= comb(v[i+k-1] - v[i-1] - 1, k - 1);
        ans = (ans + MOD) % MOD;
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}