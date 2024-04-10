#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T>
using max_heap = priority_queue<T>;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void low_to_high() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    a.erase(unique(begin(a), end(a)), end(a));
    N = a.size();

    vector<int> den(N, 1), val = a;

    priority_queue<pair<int, int>> heap;
    for (int i = 0; i < N; i++) {
        heap.emplace(val[i], i);
    }

    int ans = a[N - 1] - a[0], low = a[0];
    auto current = [&]() { return heap.top().first - low; };

    while (ans > 0 && den[heap.top().second] < K) {
        int i = heap.top().second;
        heap.pop();
        int n = val[i];
        int m = min(K, (a[i] + n) / n);
        if (m < K && a[i] / m > low) {
            m = min(K, a[i] / low);
        }
        den[i] = m;
        val[i] = a[i] / m;
        heap.emplace(val[i], i);
        low = min(low, val[i]);
        ans = min(ans, current());
    }

    cout << ans << '\n';
}

void high_to_low() {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    a.erase(unique(begin(a), end(a)), end(a));
    N = a.size();

    vector<int> den(N, K), val(N);
    for (int i = 0; i < N; i++) {
        val[i] = a[i] / K;
    }

    const int M = a[N - 1] + 1;
    vector<vector<int>> ids(M);
    for (int i = 0; i < N; i++) {
        ids[val[i]].push_back(i);
    }

    int ans = val[N - 1] - val[0], high = val[N - 1];
    bool ok = true;

    for (int v = val[0]; ans > 0 && v < M && ok; v++) {
        ans = min(ans, high - v);
        for (int i : ids[v]) {
            if (den[i] == 1) {
                ok = false;
                break;
            }
            int n = val[i];
            int m = max(1, a[i] / (n + 1));
            if (m > 1 && a[i] / m < high) {
                m = max(1, (a[i] + high + 1) / (high + 1));
            }
            den[i] = m;
            val[i] = a[i] / m;
            ids[val[i]].push_back(i);
            high = max(high, val[i]);
        }
        ids[v].clear(), ids[v].shrink_to_fit();
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        high_to_low();
    }

    return 0;
}