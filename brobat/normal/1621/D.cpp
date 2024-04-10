#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 510;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

int arr[MAXN][MAXN];
int ans, n;

void solve() {
    cin >> n;
    forn(i, 0, 2*n) {
        forn(j, 0, 2*n) {
            cin >> arr[i][j];
        }
    }
    ans = 0;
    forn(i, n, 2*n) {
        forn(j, n, 2*n) {
            ans += arr[i][j];
            arr[i][j] = 0;
        }
    }
    int x = min({arr[n][0], arr[n][n - 1], arr[2*n - 1][0], arr[2*n - 1][n - 1]});
    int y = min({arr[0][n], arr[n - 1][n], arr[0][2*n - 1], arr[n - 1][2*n - 1]});
    cout << ans + min(x, y) << endl;
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