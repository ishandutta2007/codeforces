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
    vector <int> k(n+1), h(n+1);
    h[0] = 0; k[0] = 0;
    forn(i, 0, n) cin >> k[i+1];
    forn(i, 0, n) cin >> h[i+1];
    for(int i = n - 1; i >= 0; i--) {
        h[i] = max(h[i], h[i + 1] - (k[i + 1] - k[i]));
    }
    int sp = 0;
    int mana = 0;
    forn(i, 1, n + 1) {
        if(k[i] - k[i - 1] >= h[i]) {
            sp = h[i];
            mana += h[i]*(h[i]+1)/2;
        }
        else {
            mana += sp*(k[i] - k[i - 1]) + (k[i] - k[i-1])*(k[i] - k[i-1]+1)/2;
            sp += k[i] - k[i-1];
        }
    }
    cout << mana << endl;
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