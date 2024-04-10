#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, n, k;
    cin >> t >> n >> a >> b >> k;
    if (k > n) {
        cout << 0 << endl;
        return 0;
    }
    int lo = 0, hi = t + 1;
    while (hi - lo > 1) {
        int mid = lo + hi >> 1;
        function<bool(int)> can = [&](int mid) {
            int A = min(a, mid);
            int B = min(b, mid);
            if (A * 1LL * ((n + 1) / 2) + B * 1LL * (n / 2) >= k * 1LL * mid) return true;
            return false;
        };
        if (can(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << endl;
    return 0;
}