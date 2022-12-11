#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int mn = v[0];
    for (int i = 0; i < n; ++i) {
        mn = min(mn, v[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if ((v[i] - mn) % k != 0) {
            cout << -1 << endl;
            return;
        }
        ans += (v[i] - mn) / k;
    }
    cout << ans;
}

int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}