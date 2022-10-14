#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int64_t> p(N);
        for (int i = 0; i < N; i++) {
            cin >> p[i];
            p[i] /= 100;
        }
        int64_t x, a, y, b, profit;
        cin >> x >> a >> y >> b >> profit;
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        int64_t g = lcm(a, b);
        sort(rbegin(p), rend(p));
        vector<int64_t> sum(N + 1);
        for (int i = 0; i < N; i++) {
            sum[i + 1] = sum[i] + p[i];
        }
        int L = 0, R = N + 1;
        while (L + 1 < R) {
            int K = (L + R) / 2;
            int64_t both = K / g;
            int64_t gotx = K / a - both;
            int64_t goty = K / b - both;
            int64_t gain = 0;
            gain += (sum[both] - 0) * (x + y);
            gain += (sum[both + gotx] - sum[both]) * x;
            gain += (sum[both + gotx + goty] - sum[both + gotx]) * y;
            (gain < profit) ? L = K : R = K;
        }
        cout << (R > N ? -1 : R) << '\n';
    }
    return 0;
}