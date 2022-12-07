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
    vector <int> v(n);
    forn(i, 0, n) cin >> v[i];
    int p = n - 1;
    while(p > 0) {
        if(v[p - 1] <= v[p]) {
            p--;
        } else {
            break;
        }
    }
    if(p == 0) {
        cout << 0 << endl;
        return;
    }
    if(p == n - 1 || v[n - 1] < 0) {
        cout << -1 << endl;
        return;
    }
    cout << p << endl;
    for(int i = p - 1; i >= 0; i--) {
        cout << i + 1 << " " << i + 2 << " " << n << endl;
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