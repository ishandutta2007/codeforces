#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

void solve() {
    int n;
    cin >> n;
    int arr[n], grr[n], min_arr[n];
    forn(i, 0, n) cin >> arr[i];
    forn(i, 0, n) cin >> grr[i];
    min_arr[0] = arr[0];
    forn(i, 1, n) min_arr[i] = min(arr[i], min_arr[i-1]);
    vector <int> v;
    // forn(i, 0, n) cerr << min_arr[i] << " ";
    v.push_back(-min_arr[0]);
    forn(i, 1, n) v.push_back(-min_arr[i]);
    // for(auto i : v) cerr << i << " ";
    // cerr << endl;
    int ans = n+5;
    forn(i, 0, n) {
        // Assume i swaps are performed on grr, i.e. grr[i] is at the front.
        auto it = lower_bound(v.begin(), v.end(), 1 - grr[i]);
        int c = it - v.begin();
        // cout << i + c << " ";
        ans = min(ans, i + c);
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