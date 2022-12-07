#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    int n, k;
    cin >> n >> k;
    if(k <= (n+1)/2) {
        char arr[n][n];
        forn(i, 0, n) forn(j, 0, n) arr[i][j] = '.';
        forn(i, 0, k) {
            arr[2*i][2*i] = 'R';
        }
        forn(i, 0, n) {
            forn(j, 0, n) {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << -1 << endl;
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}