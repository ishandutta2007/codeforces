#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 200087, logN = 18, K = 500, C = 100;

lli inv1, inv2;

void solve() {
    int n;
    cin >> n;
    vector <lli> dp(n + 1, 0);
    dp[0] = 1;
    lli even = 0, odd = inv1;
    fop (i,1,n + 1) {
        if (i & 1 ^ 1) dp[i] = even, odd = (odd * inv2 + dp[i] * inv1) % mod;
        else dp[i] = odd, even = (even * inv2 + dp[i] * inv1) % mod;
    }
    cout << dp[n] << endl;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    inv1 = mod + 1 >> 1;
    inv2 = inv1 * inv1 % mod;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}