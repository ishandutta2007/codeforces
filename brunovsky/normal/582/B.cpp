#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

long longest_increasing_subsequence(const vector<int>& nums) {
    int N = nums.size();
    vector<int> P(N, 0);
    vector<int> M(N + 1, 0);

    int L = 0;
    for (int i = 0; i < N; i++) {
        int lo = 1, hi = L;
        while (lo <= hi) {
            int mid = (lo + hi + 1) / 2;
            if (nums[M[mid]] <= nums[i])
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        P[i] = M[lo - 1];
        M[lo] = i;
        L = max(L, lo);
    }
    return L;
}

auto solve() {
    long N, T;
    cin >> N >> T;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (T == 1) {
        return longest_increasing_subsequence(A);
    }
    int K = min(T, 2 * N);
    vector<int> B(N * K);
    for (int i = 0; i < N * K; i++) {
        B[i] = A[i % N];
    }
    if (K == T) {
        return longest_increasing_subsequence(B);
    }

    unordered_map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        cnt[A[i]]++;
    }
    long ans = 0;
    for (auto [n, many] : cnt) {
        vector<int> before;
        for (int i = 0; i < N * N; i++) {
            if (B[i] <= n) {
                before.push_back(B[i]);
            }
        }
        vector<int> after;
        for (int i = 0; i < N * N; i++) {
            if (B[i] >= n) {
                after.push_back(B[i]);
            }
        }
        int before_len = longest_increasing_subsequence(before);
        int after_len = longest_increasing_subsequence(after);
        ans = max(ans, before_len + after_len + (T - 2 * N) * many);
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}