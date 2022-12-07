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
    int n, x;
    cin >> n >> x;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    vector <int> m(n + 1, -INF);
    m[0] = 0;
    // m[i] --> Max sum of a subarray of size i.
    vector <int> pre(n, 0);
    pre[0] = v[0];
    forn(i, 1, n) pre[i] = pre[i - 1] + v[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            // Subarray from j to i, inclusive.
            int sum = (j == 0 ? pre[i] : pre[i] - pre[j - 1]);
            m[i - j + 1] = max(m[i - j + 1], sum);
        }
    }
    for(int k = 0; k <= n; k++) {
        int mx = -INF;
        for(int i = 0; i <= n; i++) {
            mx = max(mx, m[i] + (min(i, k) * x));
        }
        cout << mx << " ";
    }
    cout << endl;
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}