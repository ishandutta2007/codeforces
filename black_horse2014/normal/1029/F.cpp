#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b; cin >> a >> b;
    vector<long long> va, vb;
    for (int i = 1; 1LL * i * i <= a; i++) if (a % i == 0) {
        va.push_back(i);
        if (i < a / i) va.push_back(a / i);
    }
    for (int i = 1; 1LL * i * i <= b; i++) if (b % i == 0) {
        vb.push_back(i);
        if (i < b / i) vb.push_back(b / i);
    }
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    long long ans = 2 * (1 + a + b);
    for (int i = 1; 1LL * i * i <= a + b; i++) {
        if ((a + b) % i == 0) {
            long long x = i, y = (a + b) / i;
            {
                long long from = (a + y - 1) / y;
                if (from <= i) {
                    int cnt = upper_bound(va.begin(), va.end(), i) - lower_bound(va.begin(), va.end(), from);
                    if (cnt > 0) ans = min(ans, 2 * (x + y));
                }
            }
            {
                long long from = (b + y - 1) / y;
                if (from <= i) {
                    int cnt = upper_bound(vb.begin(), vb.end(), i) - lower_bound(vb.begin(), vb.end(), from);
                    if (cnt > 0) ans = min(ans, 2 * (i + y));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}