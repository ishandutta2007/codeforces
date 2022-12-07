#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n, h;
vector <int> v;

bool check(int k) {
    // Return true if it is possible to do h damage with value k
    int x = k;
    forn(i, 1, n) {
        // See how much damage was done between v[i - 1] and v[i].
        x += min(v[i] - v[i - 1], k);
    }
    if(x >= h) return true;
    return false;
}

int binary_search(int left, int right) {
    int ans = -1;
    while(left <= right) {
        int mid = (left + right)/2;
        if(!check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans + 1;
}

void solve() {
    cin >> n >> h;
    v.resize(n);
    forn(i, 0, n) cin >> v[i];
    cout << binary_search(0, 1E18 + 1) << endl;
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