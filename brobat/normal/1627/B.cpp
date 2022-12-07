#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int dist(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> v;
    forn(i, 1, n + 1) forn(j, 1, m + 1) v.push_back(max({dist(i, j, 1, 1), dist(i, j, 1, m), dist(i, j, n, 1), dist(i, j, n, m)}));
    sort(v.begin(), v.end());
    for(auto i : v) cout << i << " ";
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