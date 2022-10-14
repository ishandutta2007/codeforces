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

    // int nk = 0;
    // vector<int> nums = {1, 2, 3, 4, 5, 6};
    // do {
    //     cout << setw(3) << nk++ << " -- " << nums << endl;
    // } while (next_permutation(begin(nums), end(nums)));

    int N, Q;
    cin >> N >> Q;
    long sum = 0;

    vector<long> fac(18, 1);
    for (int i = 2; i < 18; i++) {
        fac[i] = i * fac[i - 1];
    }

    vector<long> prefix(N + 1);
    for (int i = 0; i < N; i++) {
        prefix[i + 1] = prefix[i] + i + 1;
    }

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            if (sum == 0) {
                cout << prefix[r] - prefix[l - 1] << '\n';
                continue;
            }

            int changed = 2;
            while (sum >= fac[changed]) {
                changed++;
            }
            vector<int> suffix(changed);
            for (int i = 0; i < changed; i++) {
                suffix[changed - i - 1] = N - i;
            }
            debug(N, suffix, sum);

            int f = changed - 1;
            long rem = sum;

            while (rem > 0) {
                int fit = rem / fac[f];
                int i = changed - f - 1;
                while (fit-- > 0) {
                    swap(suffix[changed - f - 1], suffix[++i]);
                }
                debug(i, f, fit, suffix);
                rem %= fac[f--];
            }
            debug(suffix);

            // split [l,r] in what comes before and after suffix
            int cut = N - changed + 1;
            if (cut <= l) {
                int s = l - cut, t = r - cut;
                int ans = accumulate(begin(suffix) + s, begin(suffix) + t + 1, 0);
                cout << ans << '\n';
            } else if (cut <= r) {
                int t = r - cut;
                long ans = accumulate(begin(suffix), begin(suffix) + t + 1, 0);
                ans += prefix[cut - 1] - prefix[l - 1];
                cout << ans << '\n';
            } else {
                cout << prefix[r] - prefix[l - 1] << '\n';
            }
        } else {
            long x;
            cin >> x;
            sum += x;
        }
    }
    return 0;
}