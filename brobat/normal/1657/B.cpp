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
    int n, b, x, y;
    cin >> n >> b >> x >> y;
    int ans = 0;
    int curr = 0;
    for(int i = 1; i <= n; i++) {
        if(curr + x <= b) {
            curr += x;
        } else {
            curr -= y;
        }
        ans += curr;
    }
    cout << ans << endl;
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