#include <bits/stdc++.h>
using namespace std;

long long calc(long long n, int t) {
    long long r = sqrt(n) + 5;
    while (r * (r + t) > n) {
        --r;
    }
    return r;
}

long long calc(long long n) {
    long long ans = 0;
    for (int t = 0; t < 3; ++t) {
        ans += calc(n, t);
    }
    return ans;
}

void solve() {
    long long l, r;
    cin >> l >> r;
    cout << calc(r) - calc(l - 1) << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}