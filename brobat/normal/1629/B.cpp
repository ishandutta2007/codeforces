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
    int l, r, k;
    cin >> l >> r >> k;
    if(l == 1 && r == 1) {
        cout << "NO" << endl;
        return;
    }
    if(l == r) {
        cout << "YES" << endl;
        return;
    }
    if(k == 0) {
        cout << "NO" << endl;
        return;
    }
    int curr = r - l + 1;
    int req = (r - l)/2 + 1;
    if(l%2 && r%2) req--;
    cout << (curr - req <= k ? "YES" : "NO") << endl;
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