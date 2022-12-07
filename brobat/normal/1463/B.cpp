#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

vector <int> pw(80);

void pre() {
    pw[0] = 1;
    forn(i, 1, 80) pw[i] = pw[i-1] * 2;
}

void solve() {
    int n; cin >> n;
    vector <int> v(n), ans(n);
    forn(i, 0, n) {
        cin >> v[i];
        if(v[i]==1) {
            ans[i] = 1;
            continue;
        }
        int a = *lower_bound(pw.begin(), pw.end(), v[i]);
        if(a > 1000000007) {
            ans[i] = 536870912;
            continue;
        }
        if((v[i] - a/2) > (a - v[i])) {
            ans[i] = a;
        }
        else {
            ans[i] = a/2;
        }
    }
    forn(i, 0, n) cout << ans[i] << " ";
    cout << endl;
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