#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int fact[MAXN];

void pre() {
    fact[0] = fact[1] = 1;
    fact[2] = 1;
    forn(i, 3, MAXN) fact[i] = (fact[i-1] * i) % MOD;
}

void solve() {
    int n; cin >> n; cout << fact[2*n] << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    pre();
    while(T--) solve();

    return 0;
}