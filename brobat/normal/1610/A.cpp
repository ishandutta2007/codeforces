#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, m;
    cin >> n >> m;
    if(n > m) swap(n, m);
    if(n == 1 && m == 1) {
        cout << 0 << endl;
        return;
    }
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    cout << 2 << endl;
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