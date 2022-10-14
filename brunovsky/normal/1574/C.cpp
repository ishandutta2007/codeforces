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
    int N;
    cin >> N;
    vector<long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));
    long M = a.back();
    long all = accumulate(begin(a), end(a), 0LL);
    long rest = all - M;

    int Q;
    cin >> Q;
    while (Q--) {
        long x, y;
        cin >> x >> y;
        int i = lower_bound(begin(a), end(a), x) - begin(a);
        if (i == N) {
            long attack = x - M;
            long defend = max<long>(0, y - rest);
            cout << attack + defend << '\n';
        } else if (a[i] == x) { // we send exactly this dude
            long defend = max<long>(0, y - (all - a[i]));
            cout << defend << '\n';
        } else {
            long ans_send_hi = max<long>(0, y - (all - a[i]));
            long ans_send_lo = LLONG_MAX;
            if (i > 0) {
                long attack = x - a[i - 1];
                long defend = max<long>(0, y - (all - a[i - 1]));
                ans_send_lo = attack + defend;
            }
            cout << min(ans_send_hi, ans_send_lo) << '\n';
        }
    }
    return 0;
}