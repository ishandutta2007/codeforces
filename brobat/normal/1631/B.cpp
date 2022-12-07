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
    int op = 0;
    int val = v[n - 1];
    forn(j, 0, log2(n) + 2) {
        int eq = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(v[i] == v[i + 1]) eq++;
            else break;
        }
        if(eq == n) break;
        if(eq*2 >= n) {
            op++;
            break;
        }
        for(int i = 0; i < eq * 2; i++) {
            v[n - 1 - i] = val;
        }
        op++;
    }
    cout << op << endl;
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