#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, x;
    cin >> n >> x;
    vector <int> v(n), s(n);
    forn(i, 0, n) {cin >> v[i]; s[i] = v[i];}
    sort(s.begin(), s.end());
    int c = n - x;
    bool pos = true;
    forn(i, c, n - c) {
        if(v[i]!=s[i]) pos = false;
    }
    if(pos) cout << "YES" << endl;
    else if(2*c > n) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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