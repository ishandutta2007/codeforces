#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 998244353;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    int ones = 0;
    forn(i, 0, n) {
        cin >> v[i];
        if(v[i] == 1) ones++;
    }
    vector <int> x(n+3, 0), y(n+3, 0), z(n+3, 0);
    // x[i] ---> 0, 1, 2, ... i
    // y[i] ---> Alternating between i and i - 2
    // z[i] ---> Alternating between i and i + 2.
    // 0 can be the starting point only.
    // For 1, take 2^(number of 1s) - 1.
    int ans = (binpow(2, ones) - 1 + MOD) % MOD;
    // cerr << "ans after 1s is = " << ans << endl;
    forn(i, 0, n) {
        if(v[i] == 0) {
            x[0] = (x[0] * 2 + 1) % MOD;
            z[0] = (z[0] + y[2] + z[0]) % MOD;
        }
        else if(v[i] == 1) {
            x[1] = (x[1] + x[1] + x[0]) % MOD;
            z[1] = (z[1] + y[3] + z[1]) % MOD;
        }
        else {
            int a = v[i];
            x[a] = (x[a] + x[a] + x[a - 1]) % MOD;
            z[a] = (z[a] + y[a + 2] + z[a]) % MOD;
            y[a] = (y[a] + z[a - 2] + y[a] + x[a - 2]) % MOD;
        }
    }
    forn(i, 0, n + 1) {
        // if(x[i] > 10 || y[i] > 10 || z[i] > 10) cerr << "Garbage at " << i << endl;
        ans = (ans + x[i] + y[i] + z[i]) % MOD;
        // cerr << x[i] << " " << y[i] << " " << z[i] << endl;
    }
    cout << ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}