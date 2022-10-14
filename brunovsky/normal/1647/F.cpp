#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void setmin(int& a, int b) { a = min(a, b); }
void setmax(int& a, int b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        assert(a[i] > 0);
    }

    int ans = 0;

    auto solve = [&]() {
        int m = max_element(begin(a), end(a)) - begin(a);
        int a0 = 0, a1 = 0;
        for (int i = 0; i <= m; i++) {
            if (a0 < a[i]) {
                a0 = a[i];
            } else if (a1 < a[i]) {
                a1 = a[i];
            } else {
                return;
            }
        }

        // Until you commit a peak you want to keep a1 low if possible as well
        vector<array<int, 2>> front(N, {0, INT_MAX});
        front[m] = {a0, a1};

        // front[i][0]: how large can a0 remain if we assign this to hill 1
        // front[i][1]: how small can a1 remain if we assign this to hill 0
        for (int i = m + 1; i < N; i++) {
            if (a[i - 1] < a[i]) {
                // {x,a[i-1]} -> {x,a[i]}
                front[i][0] = front[i - 1][0];
            } else {
                // {a[i-1],y} -> {a,y}
                front[i][1] = front[i - 1][1];
            }
            if (front[i - 1][1] < a[i]) {
                // {a[i-1],y} -> {a[i-1],a[i]}
                setmax(front[i][0], a[i - 1]);
            }
            if (front[i - 1][0] > a[i]) {
                // {x,a[i-1]} -> {a[i],a[i-1]}
                setmin(front[i][1], a[i - 1]);
            }
        }

        int b0 = 0, b1 = 0;
        for (int i = N - 1; i >= m + 1; i--) {
            if (b0 < a[i]) {
                b0 = a[i];
            } else if (b1 < a[i]) {
                b1 = a[i];
            } else {
                break;
            }
            auto [f0, f1] = front[i];
            if (b0 == a[i]) {
                swap(b0, b1);
            }
            ans += f0 > b0;
            if (b0 < b1) {
                swap(b0, b1);
            }
        }
    };

    solve();
    reverse(begin(a), end(a));
    solve();
    cout << ans << '\n';
    return 0;
}