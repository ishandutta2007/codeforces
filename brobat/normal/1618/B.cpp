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
    vector<string> v(n);
    forn(i, 0, n - 2) cin >> v[i];
    string s = v[0];
    bool done = false;
    forn(i, 1, n - 2) {
        if(v[i-1][1] != v[i][0]) {
            s += v[i][0];
            done = true;
        }
        s += v[i][1];
    }
    if(!done) s += 'a';
    cout << s << endl;
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