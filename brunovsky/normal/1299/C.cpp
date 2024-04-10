#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct Ratio {
    int64_t n;
    int d;
    friend Ratio operator+(Ratio a, Ratio b) { return Ratio{a.n + b.n, a.d + b.d}; }
    friend bool operator<=(Ratio a, Ratio b) { return a.n * b.d <= a.d * b.n; }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int64_t> sum(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum[i + 1] = a[i] + sum[i];
    }
    vector<Ratio> ans = {Ratio{a[0], 1}};
    for (int i = 2; i <= N; i++) {
        auto cur = Ratio{a[i - 1], 1};
        while (!ans.empty() && cur <= ans.back()) {
            cur = cur + ans.back();
            ans.pop_back();
        }
        ans.push_back(cur);
    }
    cout << setprecision(9) << fixed << showpoint;
    for (auto [n, d] : ans) {
        double v = double(n) / d;
        for (int i = 0; i < d; i++) {
            cout << v << '\n';
        }
    }
    return 0;
}