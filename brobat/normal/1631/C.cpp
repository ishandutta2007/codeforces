#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 65556;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

void solve() {
    int n, k;
    cin >> n >> k;
    if(k == n - 1) {
        if(n == 4) {
            cout << -1 << endl;
            return;
        }
        vector <int> done(n, 0);
        cout << n - 1 << " " << n - 2 << endl;
        cout << 1 << " " << 3 << endl;
        cout << n - 1 - 3 << " " << 0 << endl;
        done[n - 1] = done[n - 2] = done[1] = done[3] = done[n - 1 - 3] = done[0] = 1;
        forn(i, 0, n) {
            if(done[i] == 0) {
                cout << i << " " << n - 1 - i << endl;
                done[i] = 1;
                done[n - 1 - i] = 1;
            }
        }
        return;
    }
    vector <int> done(n, 0);
    cout << n - 1 << " " << k << endl;
    done[n - 1] = 1;
    done[k] = 1;
    if(k != 0) {
        cout << n - 1 - k << " " << 0 << endl;
        done[n - 1 - k] = 1;
        done[0] = 1;
    }
    forn(i, 0, n) {
        if(done[i] == 0) {
            cout << i << " " << n - 1 - i << endl;
            done[i] = 1;
            done[n - 1 - i] = 1;
        }
    }
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