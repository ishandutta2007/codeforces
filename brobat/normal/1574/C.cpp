#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n, m, x, y, ans, sum;

void solve() {
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0ll);
    cin >> m;
    forn(tt, 0, m) {
        cin >> x >> y;
        auto it = lower_bound(v.begin(), v.end(), x);
        ans = 5E18;
        if(it != v.end()) ans = max(0ll, x - *it) + max(0ll, y - sum + *it);
        if(it != v.begin()) {
            --it;
            ans = min(ans, max(0ll, x - *it) + max(0ll, y - sum + *it));
        }
        cout << ans << endl;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}