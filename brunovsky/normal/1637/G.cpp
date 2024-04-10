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

        if (N == 2) {
            cout << -1 << '\n';
            continue;
        }

        int A = 1 << (8 * sizeof(int) - __builtin_clz(N - 1));
        int M = A;
        vector<pair<int, int>> ops;

        vector<int> nums(A == N ? N - 1 : N), ones;
        iota(begin(nums), end(nums), 1);
        int zeros = 0;

        while (!nums.empty() && M >= 1) {
            int relax;
            do {
                relax = 0;
                vector<int> res;
                int K = nums.size(), l = 0, r = K - 1;
                while (l < K && nums[l] == 0) {
                    res.push_back(nums[l++]);
                }
                while (l < r) {
                    if (nums[l] + nums[r] < M) {
                        res.push_back(nums[l++]);
                    } else if (nums[l] + nums[r] > M) {
                        res.push_back(nums[r--]);
                    } else {
                        ones.push_back(M);
                        res.push_back(nums[r] - nums[l]);
                        ops.push_back({nums[r], nums[l]});
                        l++, r--, relax++;
                    }
                }
                if (l == r) {
                    res.push_back(nums[l]);
                }
                sort(begin(res), end(res));
                swap(res, nums);
            } while (relax > 0);

            while (!nums.empty() && nums.back() == M) {
                ones.push_back(M);
                nums.pop_back();
            }
            while (!nums.empty() && nums.back() == 0) {
                zeros++;
                nums.pop_back();
            }
            M /= 2;
        }

        assert(nums.empty());
        sort(begin(ones), end(ones));

        int relax;
        do {
            relax = 0;
            int O = ones.size();
            vector<int> res;
            for (int i = 0; i < O; i++) {
                if (i + 1 < O && ones[i] < A && ones[i] == ones[i + 1]) {
                    res.push_back(2 * ones[i]);
                    ops.push_back({ones[i], ones[i]});
                    zeros++, relax++, i++;
                } else {
                    res.push_back(ones[i]);
                }
            }
            swap(ones, res);
            sort(begin(ones), end(ones));
        } while (relax > 0);

        for (int n : ones) {
            while (n < A) {
                ops.push_back({n, 0});
                ops.push_back({n, n});
                n *= 2;
            }
        }

        while (zeros--) {
            ops.push_back({A, 0});
        }

#ifdef LOCAL
        multiset<int> run;
        for (int i = 1; i <= N; i++) {
            run.insert(end(run), i);
        }
        for (auto [a, b] : ops) {
            assert(a >= b);
            assert(run.count(a));
            run.erase(run.find(a));
            assert(run.count(b));
            run.erase(run.find(b));
            run.insert(a + b);
            run.insert(a - b);
        }
        eputln(N, A, "|", run);
#else
        cout << ops.size() << '\n';
        for (auto [a, b] : ops) {
            cout << a << ' ' << b << '\n';
        }
#endif
    }

    return 0;
}