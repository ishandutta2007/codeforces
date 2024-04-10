#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    mt19937 rng(random_device{}());
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (N == 3) {
            cout << "1 3 2\n";
            cout << "2 3 1\n";
            cout << "3 1 2\n";
            continue;
        }
        vector<int> nums(N);
        nums[0] = 1, nums[1] = 3, nums[2] = 2;
        for (int i = 3; i < N; i++) {
            nums[i] = i + 1;
        }
        for (int s = 0; s < N; s++) {
            for (int i = 0; i < N; i++) {
                cout << nums[(i + s) % N] << " \n"[i + 1 == N];
            }
        }
    }
    return 0;
}