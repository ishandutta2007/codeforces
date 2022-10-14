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
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        vector<int> b(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> b[i];
        }
        sort(begin(a), end(a));
        sort(rbegin(b), rend(b));
        int k = N - N / 4;
        long Ap = accumulate(end(a) - k, end(a), 0LL);
        long Bp = accumulate(begin(b), begin(b) + k, 0LL);
        int added = 0;
        while (Ap < Bp) {
            a.push_back(100);
            b.push_back(0);
            N++, added++;
            int nk = N - N / 4;
            if (nk > k) {
                Ap += 100;
                Bp += b[k];
            } else {
                Ap += 100;
                Ap -= a[N - (k + 1)];
            }
            k = nk;
        }
        cout << added << '\n';
    }
    return 0;
}