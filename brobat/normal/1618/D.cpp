#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    int eq = 0;
    int cnt = 1;
    for(int i = 1; i < 2*k; i++) {
        if(v[i] < v[i - 1]) {
            eq = max(eq, cnt);
            cnt = 0;
        }
        cnt++;
    }
    eq = max(eq, cnt);
    if(k > 0) ans += max(0ll, eq - k);
    for(int i = 2*k; i < n; i++) {
        ans += v[i];
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