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
    cout << fixed << showpoint << setprecision(9) << endl;
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(rbegin(a), rend(a));
        long sum = accumulate(begin(a) + 1, end(a), 0LL);
        double avg = a[0] + 1.0 * sum / (N - 1);
        cout << avg << endl;
    }
    return 0;
}