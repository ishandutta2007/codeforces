#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

int func(int x) {
    int k;
    cin >> k;
    vector <int> v(k);
    forn(i, 0, k) cin >> v[i];
    sort(v.begin(), v.end());
    return x * (v[k - 1] - v[0]);
}

void solve() {
    int w, h;
    cin >> w >> h;
    int ans = 0;
    forn(i, 0, 2) ans = max(ans, func(h));
    forn(i, 0, 2) ans = max(ans, func(w));
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