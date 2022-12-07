#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 1E9;
    int f = count(a.begin(), a.end(), '1');
    int g = count(b.begin(), b.end(), '1');
    if(f == g) {
        // Should be possible in even number of flips.
        int temp = 0;
        forn(i, 0, n) {
            if(a[i] != b[i]) temp++;
        }
        ans = min(ans, temp);
    }
    if(g == n - f + 1) {
        // Should be possible in odd number of flips.
        int temp = 0;
        forn(i, 0, n) {
            if(a[i] == b[i]) temp++;
        }
        ans = min(ans, temp);
    }
    if(ans == 1E9) {
        ans = -1;
    }
    cout << ans << endl;
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