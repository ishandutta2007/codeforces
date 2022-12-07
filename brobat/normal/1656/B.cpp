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
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    set <int> s;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }
    for(int i = 0; i < n; i++) {
        if(s.find(v[i] - k) != s.end()) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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