#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n, k;
    cin >> n >> k;
    if(k == 1) {
        cout << "YES" << endl;
        forn(i, 1, n + 1) cout << i << endl;
        return;
    }
    if(n % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            cout << n*j + i << " ";
        }
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
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}