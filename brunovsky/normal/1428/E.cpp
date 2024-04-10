#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto cost(int n, int k) {
    // cut carrot of length n into k pieces
    int l = n / k, r = l + 1;
    int tot = l * k;
    int high = n - tot;
    int low = k - high;
    return 1LL * low * l * l + 1LL * high * r * r;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> pieces(N, 1);
    int S = N;

    priority_queue<pair<int64_t, int>> pq;
    for (int i = 0; i < N; i++) {
        if (a[i] > 1) {
            pq.emplace(cost(a[i], 1) - cost(a[i], 2), i);
        }
    }

    while (S++ < K) {
        auto [x, i] = pq.top();
        pq.pop();
        pieces[i]++;
        if (a[i] > pieces[i]) {
            pq.emplace(cost(a[i], pieces[i]) - cost(a[i], pieces[i] + 1), i);
        }
    }

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        ans += cost(a[i], pieces[i]);
    }
    cout << ans << '\n';
    return 0;
}

// 10^12 - 2*(5*10^5)^2=10^12-50*10^10=10^12-5*10^11 = 5*10^11