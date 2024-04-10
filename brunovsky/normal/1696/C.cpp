#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto compute(const vector<int>& a, int m) {
    int N = a.size();
    vector<pair<int, int64_t>> runs;
    for (int i = 0; i < N; i++) {
        int c = 1, v = a[i];
        while (v % m == 0) {
            v /= m;
            c *= m;
        }
        if (runs.empty() || runs.back().first != v) {
            runs.push_back({v, c});
        } else {
            runs.back().second += c;
        }
    }
    return runs;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, m;
        cin >> N >> m;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        int K;
        cin >> K;
        vector<int> b(K);
        for (int i = 0; i < K; i++) {
            cin >> b[i];
        }
        if (compute(a, m) == compute(b, m)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}