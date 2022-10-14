#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto compute(const vector<int>& a, const vector<int>& b) {
    int N = a.size();
    int asum = a[0], bsum = b[0];
    int cost = 0;
    for (int i = 1; i < N; i++) {
        cost += asum * a[i] + bsum * b[i];
        asum += a[i], bsum += b[i];
    }
    cost *= 2;
    for (int i = 0; i < N; i++) {
        cost += (N - 1) * (a[i] * a[i] + b[i] * b[i]);
    }
    return cost;
}

template <typename T>
void setmin(T& a, T b) {
    a = min(a, b);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N), b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }

        if (N == 1) {
            cout << 0 << '\n';
            continue;
        }

        int64_t base = 0;
        for (int i = 0; i < N; i++) {
            base += (N - 1) * (a[i] * a[i] + b[i] * b[i]);
        }

        int A = 0, B = 0;
        for (int i = 0; i < N; i++) {
            A += a[i];
            B += b[i];
            if (a[i] < b[i]) {
                swap(a[i], b[i]);
            }
        }

        vector<int> sum(N + 1);
        for (int i = 1; i <= N; i++) {
            sum[i] = a[i - 1] + b[i - 1] + sum[i - 1];
        }

        int V = sum[N];
        vector<int64_t> ans(V + 1, INT64_MAX / 3);
        ans[0] = 0;

        for (int i = 0; i < N; i++) {
            vector<int64_t> tmp(V + 1, INT64_MAX / 3);
            for (int v = 0; v + a[i] <= V; v++) {
                int r = sum[i] - v;
                setmin(tmp[v + a[i]], ans[v] + a[i] * v + b[i] * r);
            }
            for (int v = 0; v + b[i] <= V; v++) {
                int r = sum[i] - v;
                setmin(tmp[v + b[i]], ans[v] + b[i] * v + a[i] * r);
            }
            swap(tmp, ans);
        }

        int64_t best = *min_element(begin(ans), end(ans));
        cout << (base + 2 * best) << '\n';
    }
    return 0;
}