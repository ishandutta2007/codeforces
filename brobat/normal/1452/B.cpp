#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n; cin >> n;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end());
    int sum = accumulate(v.begin(), v.end(), 0ll);
    int ans = 0;
    int f = v[n - 1];
    int c = sum - (n - 1) * f;
    if(c > 0) {
        int d = c % (n - 1);
        if(d) {
            ans += n - 1 - d;
        }
    }
    else if(c < 0) {
        ans -= c;
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