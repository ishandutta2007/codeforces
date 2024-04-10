#include <bits/stdc++.h>

using namespace std;

int n, x;
multiset<int> a, b;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x;
    int t;
    for (int i = -1; ++i < n; ) cin >> t, a.insert(t);
    for (int i = -1; ++i < n;) cin >> t, b.insert(t);
    int ans = n;
    while (a.size()) {
        int m = *a.begin();
        a.erase(a.begin());
        auto t = b.lower_bound(x - m);
        if (t == b.end()) {
            --ans;
            continue;
        }
        b.erase(t);
    }
    cout << 1 << ' ' << ans;
    return 0;
}