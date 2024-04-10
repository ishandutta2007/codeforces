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
    bool marked[n + 1]; memset(marked, false, sizeof(marked));
    bool pos = true;
    forn(i, 0, n) {
        int x = v[i];
        while(x) {
            if(x > n) {
                x = x/2;
                continue;
            }
            if(!marked[x]) {
                marked[x] = true;
                // cout << x << endl;
                break;
            }
            else x = x/2;
        }
        if(x == 0) {
            pos = false;
            break;
        }
    }
    cout << (pos ? "YES" : "NO") << endl;
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