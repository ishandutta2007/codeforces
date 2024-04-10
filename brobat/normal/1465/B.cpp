#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int fair(int x) {
    string s = to_string(x);
    forn(i, 0, s.length()) {
        if(s[i]=='0') continue;
        if(x % (s[i]-'0') != 0) return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    forn(i, n, n + 1E6) {
        if(fair(i)) {
            cout << i << endl;
            return;
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
    while(T--) solve();

    return 0;
}