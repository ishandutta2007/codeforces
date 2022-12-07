#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    vector <int> diff(n - 1);
    forn(i, 0, n - 1) diff[i] = v[i + 1] - v[0];
    bool m = true;
    forn(i, 0, n - 1) if(diff[i]) m = false;
    if(m) {
        cout << -1 << endl;
        return;
    }
    int g = diff[0];
    forn(i, 1, n - 1) g = __gcd(g, diff[i]);
    cout << g << endl;
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