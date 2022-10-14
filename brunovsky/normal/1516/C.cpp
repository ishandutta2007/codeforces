#include <bits/stdc++.h>

using namespace std;

// *****

bool subset_sum(const vector<int>& nums, int target_sum) {
    int N = nums.size();
    int neg = 0, pos = 0;
    for (int i = 0; i < N; i++)
        nums[i] > 0 ? pos += nums[i] : neg += nums[i];

    if (target_sum < neg || pos < target_sum)
        return false;

    // note: if you have a dynamic bitset class, use it instead and shift by x
    int S = pos - neg + 1;
    vector<bool> dp(S, false);

    for (int i = 0; i < N && !dp[target_sum - neg]; i++) {
        int x = nums[i];
        if (x >= 0) {
            for (int s = pos; s >= x + neg; s--) {
                dp[s - neg] = dp[s - neg] | dp[s - x - neg];
            }
        } else {
            for (int s = neg; s <= x + pos; s++) {
                dp[s - neg] = dp[s - neg] | dp[s - x - neg];
            }
        }
        dp[x - neg] = true;
    }

    return dp[target_sum - neg];
}

auto solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int S = accumulate(begin(A), end(A), 0);
    if (S & 1) {
        cout << 0 << endl;
        return;
    }
    if (!subset_sum(A, S / 2)) {
        cout << 0 << endl;
        return;
    }
    int minb = 50;
    for (int n : A) {
        int b = 0;
        while ((n & 1) == 0)
            b++, n >>= 1;
        minb = min(minb, b);
    }
    for (int i = 0; i < N; i++) {
        int b = 0;
        while ((A[i] & 1) == 0)
            b++, A[i] >>= 1;
        if (b == minb) {
            cout << 1 << '\n' << (i + 1) << endl;
            return;
        }
    }
    __builtin_unreachable();
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}