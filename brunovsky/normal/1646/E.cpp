#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int is_sqrt(int n) {
    int m = floor(sqrt(n));
    while (m * m > n) {
        m--;
    }
    while ((m + 1) * (m + 1) <= n) {
        m++;
    }
    return m * m == n;
}

auto binpow(int n, int m) {
    int64_t ans = 1;
    int64_t k = n;
    while (m) {
        if (m & 1)
            ans *= k;
        if (m >>= 1)
            k *= k;
    }
    return ans;
}

auto brute(int N, int M) {
    set<int64_t> nums;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            nums.insert(binpow(n + 1, m + 1));
        }
    }
    return nums.size();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<int> powers(N + 1, 1);
    for (int64_t n = 1000; n >= 2; n--) {
        int64_t m = n * n;
        int p = 2;
        while (m <= N) {
            powers[m] = p++;
            m *= n;
        }
    }

    int P = 1 + *max_element(begin(powers), end(powers));
    vector<int> count(P);
    count[1] = M;

    vector<int8_t> used(P * M + 1);
    for (int k = 1; k <= M; k++) {
        used[k] = true;
    }

    for (int p = 2; p < P; p++) {
        for (int k = 1; k <= M; k++) {
            count[p] += !used[k * p];
            used[k * p] = true;
        }
    }

    int64_t ans = 1;
    for (int n = 2; n <= N; n++) {
        ans += count[powers[n]];
    }
    cout << ans << '\n';
    return 0;
}