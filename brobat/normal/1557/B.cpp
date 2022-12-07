#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    forn(i, 0, n) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int x = 0;
    forn(i, 1, n) {
        if(v[i].second != v[i-1].second + 1) x++;
    }
    if(k>x) cout << "Yes" << endl;
    else cout << "No" << endl;
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