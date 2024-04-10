#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> nums = {0};
    for (int i = 1, N = 1; N <= 1000; i++) {
        if (i % 3 != 0 && i % 10 != 3) {
            nums.push_back(i), N++;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        cout << nums[k] << '\n';
    }
    return 0;
}