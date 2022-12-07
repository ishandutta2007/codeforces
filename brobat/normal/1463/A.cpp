#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    vector <int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    int x = v[0] + v[1] + v[2];
    sort(v.begin(), v.end());
    if(x%9==0 && x/9<=v[0]) {
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