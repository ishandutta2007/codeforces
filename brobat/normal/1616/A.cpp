#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    int n;
    cin >> n;
    vector <int> v(n);
    forn(i, 0, n) {
        cin >> v[i];
        v[i] = abs(v[i]);
    }
    map <int, int> m;
    forn(i, 0, n) m[v[i]]++;
    int ans = 0;
    for(auto i : m) {
        ans += min(i.second, i.first==0 ? 1ll : 2ll);
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