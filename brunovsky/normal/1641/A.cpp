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
        int N, x;
        cin >> N >> x;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        const int MAX = a.back();
        multiset<int> nums(begin(a), end(a));
        int ans = 0;
        while (!nums.empty()) {
            int n = *nums.begin();
            nums.erase(nums.begin());
            if (1LL * n * x <= MAX && nums.count(n * x)) {
                nums.erase(nums.find(n * x));
            } else {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}