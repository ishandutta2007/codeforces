#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n;
vector <int> a, b;

bool check(int x) {
    int pos = 0;
    forn(i, 0, n) {
        if(b[i] >= pos && a[i] >= x - 1 - pos) {
            pos++;
        }
    }
    if(pos >= x) return true;
    return false;
}

int binary_search(int left, int right) {
    int ans = -1;
    while(left <= right) {
        int mid = (left + right)/2;
        if(check(mid)) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    a.resize(n); b.resize(n);
    forn(i, 0, n) cin >> a[i] >> b[i];
    cout << binary_search(0, n + 1) << endl;
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