#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

int solve() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    char grid[n][m];
    forn(i, 0, n) forn(j, 0, m) cin >> grid[i][j];
    --r; --c;
    if(grid[r][c]=='B') return 0;
    int cnt = 0;
    forn(i, 0, n) forn(j, 0, m) if(grid[i][j]=='B') cnt++;
    if(cnt == 0) return -1;
    forn(i, 0, m) if(grid[r][i]=='B') return 1;
    forn(i, 0, n) if(grid[i][c]=='B') return 1;
    return 2;
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
        cout << solve() << endl;
    }

    return 0;
}