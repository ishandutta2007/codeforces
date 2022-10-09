#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i: a) cin >> i;
    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0ll);
    ll rem = n - sum % n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll cur = sum / n + (i >= rem);
        ans += abs(a[i] - cur);
    }
    cout << ans / 2;
    
    return 0;
}