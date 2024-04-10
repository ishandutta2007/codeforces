#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n, k;
    cin >> n >> k;
    vector <int> v(k);
    forn(i, 0, k) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int x = v[0] - 1;
    int m = 1;
    forn(i, 1, k) {
        int c = x - (n - v[i]);
        if(c >= 0) {
            m++;
            x = c;
        }
        else break;
    }
    cout << m << endl;
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