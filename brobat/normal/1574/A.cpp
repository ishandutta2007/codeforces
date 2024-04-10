#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    forn(i, 1, n + 1) {
        // i^th index has to be skipped.
        forn(j, 0, i) cout << "(";
        cout << ")";
        forn(j, i+1, n+1) cout << "(";
        forn(j, n+1, 2*n) cout << ")";
        cout << endl; 
    }
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