#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

void solve() {
    int n;
    cin >> n;
    vector<pii> t(n);
    int q(0);
    for (int i = 0; i < n; ++i) {
        cin >> t[i].first >> t[i].second;
    }

    int mx(0), ans(0);
    int ti = 0;

    for (int i = 0; i < 1<<20; ++i) {
        if (q) {
            --q;
            ans = i;
        }
        if (ti < t.size() && t[ti].first == i) {
            q += t[ti++].second;
            mx = max(mx, q);
        }
    }

    if (q) ans = q + (1<<20) - 1;

    cout << ans << ' ' << mx << endl;
}

int main() {
    solve();
    return 0;
}