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
    int n;
    cin >> n;
    vector <pair<int, int>> v(n);
    set <int> s;
    forn(i, 0, n) cin >> v[i].first >> v[i].second;
    sort(v.begin(),v.end(), [&](pair<int, int> &x, pair<int, int> &y) {
        return x.second - x.first < y.second - y.first;
    });
    forn(i, 1, n + 1) s.insert(i);
    forn(i, 0, n) {
        auto x = lower_bound(s.begin(), s.end(), v[i].first);
        cout << v[i].first << " " << v[i].second << " " << (*x) << endl;
        s.erase(x);
    }
    cout << endl;
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