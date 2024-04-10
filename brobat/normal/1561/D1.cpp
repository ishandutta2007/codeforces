#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i <= n; i++)
#define MAXN 200100
// #define MOD 1000000007

int n, MOD;
int dp[MAXN];
int sum;

void assign(int x) {
    dp[x] = sum; //Subtract
    // From quotients??
    vector <int> v;
    int zz = 0;
    forn(k, 1, sqrt(x)) {
        // s[k] = 1;
        if(k != zz) {
            v.push_back(k);
            zz = k;
        }
        // s.insert(k);
        // s.insert(x/k);
    }
    for(int k = sqrt(x); k>=1; k--) {
        // s[x/k] = 1;
        if(x/k != zz) {
            v.push_back(x/k);
            zz = x/k;
        }
    }
    // s has root(x) values.
    int z = v.size();
    for(int i = 0; i < z - 1; i++) {
        dp[x] += (x/v[i] - x/v[i+1]) * dp[v[i]] % MOD;
        dp[x] %= MOD;
    }
    // for(auto i : s) {
    //     // How many times does the value i come??
    //     cout << i << " ";
    //     if(i==x) continue;
    //     dp[x] += (x/i - x/(i+1) + 1) * dp[i] % MOD;
    //     dp[x] %= MOD;
    // }
    sum += dp[x];
    sum %= MOD;
}

void solve() {
    cin >> n >> MOD;
    forn(i, 1, n) dp[i] = 0;
    dp[1] = 1;
    sum = 1;
    // assign(2);
    // assign(15);
    forn(i, 2, n) assign(i);
    cout << dp[n];
    // forn(i, 1, n) cout << dp[i] << " ";
    // assign(3);
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}