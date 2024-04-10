#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 300100;
const int MOD = 1000000007;

void solve() {
    int n; char c; string s;
    cin >> n >> c >> s;
    bool isZero = true;
    forn(i, 0, n) if(s[i]!=c) isZero = false;
    if(isZero) {
        cout << 0 << endl;
        return;
    }
    for(int i = n; i > n/2; i--) {
        if(s[i - 1] == c) {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }
    }
    cout << 2 << endl;
    cout << n << " " << n - 1 << endl;
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