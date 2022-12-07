#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    vector <int> v(3); int m;
    cin >> v[0] >> v[1] >> v[2] >> m;
    sort(v.begin(), v.end());
    int b = v[0] + v[1] + v[2] - 3;
    int a = (v[2] > v[1] + v[0])?v[2]-v[1]-v[0]-1:0;
    cout << (m>=a&&m<=b?"YES":"NO") << endl;
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