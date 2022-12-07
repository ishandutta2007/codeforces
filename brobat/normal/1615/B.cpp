#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

int b[MAXN][18];

void pre() {
    forn(i, 0, 18) b[0][i] = 0;
    forn(i, 1, MAXN) {
        int x = i;
        vector <int> v;
        while(x) {
            v.push_back(x % 2);
            x = x / 2;
        }
        forn(j, 0, 18) b[i][j] = b[i-1][j];
        forn(j, 0, v.size()) {
            if(v[j] == 1) {
                b[i][18 - j - 1]++;
            }
        }
    }
    // forn(i, 0, 10) {
    //     forn(j, 0, 5) {
    //         cout << b[i][18 - j - 1] << " ";
    //     }
    //     cout << endl;
    // }
}

void solve() {
    int l, r;
    cin >> l >> r;
    int x = r - l + 1;
    int ans = -1;
    forn(i, 0, 18) {
        ans = max(ans, b[r][i] - b[l-1][i]);
    }
    cout << r - l + 1 - ans << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    pre();
    while(T--) solve();

    return 0;
}