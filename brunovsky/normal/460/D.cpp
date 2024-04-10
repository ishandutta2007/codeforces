#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    long l, r, k;
    cin >> l >> r >> k;

    auto answer = [&](const vector<long>& nums) {
        long vxor = 0;
        for (long v : nums)
            vxor ^= v;
        cout << vxor << '\n';
        cout << nums.size() << '\n';
        for (int i = 0, B = nums.size(); i < B; i++) {
            cout << nums[i] << " \n"[i + 1 == B];
        }
    };

    if (k == 1) {
        answer({l});
        return 0;
    }

    long N = r - l + 1;

    if (N <= 12) {
        // brute force
        vector<long> best;
        long best_v = LONG_MAX;
        for (int n = 1; n < (1 << N); n++) {
            if (__builtin_popcount(n) <= k) {
                vector<long> nums;
                long v = 0;
                for (int i = 0; i < N; i++) {
                    if ((n >> i) & 1) {
                        nums.push_back(l + i);
                        v ^= l + i;
                    }
                }
                if (best.empty() || best_v > v) {
                    best = move(nums);
                    best_v = v;
                }
            }
        }
        answer(best);
        return 0;
    }

    if (k >= 4) {
        while (l % 4 != 0) {
            l++;
        }
        answer({l, l + 1, l + 2, l + 3});
        return 0;
    }

    if (k == 3) {
        int B = 8 * sizeof(r) - __builtin_clzll(r);
        debug(B);

        auto mk = [&](int a, int b, int c, char aa, char bb, char cc) {
            auto s = string(a, aa) + string(b, bb) + string(c, cc);
            debug(s);
            return stoll(s, nullptr, 2);
        };

        for (int a = 0; a <= B; a++) {
            for (int b = 0; a + b <= B; b++) {
                for (int c = a + b == 0; a + b + c <= B; c++) {
                    // okay so put u = 110, v = 101, w = 011
                    auto u = mk(a, b, c, '1', '1', '0');
                    auto v = mk(a, b, c, '1', '0', '1');
                    auto w = mk(a, b, c, '0', '1', '1');
                    bool uok = l <= u && u <= r;
                    bool vok = l <= v && v <= r;
                    bool wok = l <= w && w <= r;
                    bool diff = u > v && v > w;
                    if (uok && vok && wok && diff) {
                        answer({u, v, w});
                        return 0;
                    }
                }
            }
        }
    }

    // k=2 or failed k=3
    while (l % 2 != 0) {
        l++;
    }
    answer({l, l + 1});
    return 0;
}