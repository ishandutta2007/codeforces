#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

#define pi pair<int, int>

void solve() {
    vector <pi> v(3);
    for(int i = 0; i < 3; i++) {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    if(v[1].first == v[2].first) {
        cout << abs(v[1].second - v[2].second) << endl;
    } else {
        cout << 0 << endl;
    }
}

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}