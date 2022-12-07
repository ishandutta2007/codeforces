#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int comb(int n, int r) {
    if(n < r) return 0;
    if(r == 3) return n*(n-1)*(n-2)/6;
    if(r == 2) return n*(n-1)/2;
    if(r == 1) return n;
    return 1;
}

void solve() {
    int n;
    cin >> n;
    int den = comb(n, 3) * 2;
    vector <int> ans(n + 1, 0);
    forn(i, 0, n + 1) {
        ans[i] = 2 * (comb(i, 3)*comb(n - i, 0) + comb(i, 2) * comb(n - i, 1)) + comb(i, 1) * comb(n - i, 2);
    }
    double x;
    cin >> x;
    forn(i, 0, n + 1) {
        double y = ans[i] * 1.0 / den;
        if(y >= x) {
            cout << i << endl;
            return;
        }
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}