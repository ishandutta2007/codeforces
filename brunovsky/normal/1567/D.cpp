#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;

    vector<long> pow10(10);
    pow10[0] = 1;
    for (int i = 1; i < 10; i++) {
        pow10[i] = pow10[i - 1] * 10;
    }
    while (T--) {
        // Minimize carries
        long sum;
        int N;
        cin >> sum >> N;

        if (N == 1) {
            cout << sum << '\n';
            continue;
        }

        auto cmp = [&](long a, long b) {
            string x = to_string(a);
            string y = to_string(b);
            if (x.size() != y.size()) {
                return x.size() < y.size();
            } else {
                return x > y;
            }
        };

        multiset<long, decltype(cmp)> nums(cmp);
        int ones = 0;

        auto extract = [&](long x) {
            string s = to_string(x);
            int S = s.size();
            long k = pow10[S - 1];
            return k;
        };

        auto partition = [&](long x) {
            string s = to_string(x);
            int S = s.size();
            if (x == pow10[S - 1]) {
                assert(S > 1);
                return pow10[S - 2];
            } else {
                return pow10[S - 1];
            }
        };

        auto add = [&](long x) {
            if (x == 1) {
                ones++;
            } else {
                nums.insert(x);
            }
        };

        for (int i = 0; i < N; i++) {
            if (sum > 0) {
                if (i + 1 == N) {
                    add(sum);
                    sum = 0;
                } else {
                    auto k = extract(sum);
                    sum -= k;
                    add(k);
                }
            } else {
                long x = *nums.begin();
                nums.erase(nums.begin());
                auto k = partition(x);
                add(k), add(x - k);
            }
        }

        assert(sum == 0);

        while (ones > 0) {
            nums.insert(1), ones--;
        }

        vector<long> ans(begin(nums), end(nums));
        assert(int(ans.size()) == N);
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}