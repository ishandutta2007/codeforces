#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T>
auto sparse_subset_sum(const vector<T>& nums) {
    int N = nums.size();
    map<T, int> seen;
    seen[T(0)] = -1;

    for (int i = 0; i < N; i++) {
        auto x = nums[i];
        if (x > 0) {
            for (auto it = seen.rbegin(); it != seen.rend(); ++it) {
                seen.emplace(it->first + x, i);
            }
        } else if (x < 0) {
            for (auto it = seen.begin(); it != seen.end(); ++it) {
                seen.emplace(it->first + x, i);
            }
        }
    }

    return seen;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        if (find(begin(a), end(a), 0) != end(a)) {
            cout << "YES\n";
            continue;
        }
        int M = 1 << N;
        vector<int> sum(M);
        for (int m = 0; m < M; m++) {
            for (int i = 0; i < N; i++) {
                if ((m >> i) & 1) {
                    sum[m] += a[i];
                } else {
                    sum[m] -= a[i];
                }
            }
        }
        bool found = false;
        for (int m = 0; m < M && !found; m++) {
            for (int s = m; s && !found; s = m & (s - 1)) {
                found = sum[s] == sum[s ^ m];
            }
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}