#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto output(const vector<int>& nums) {
    int N = nums.size();
    for (int i = 0; i < N; i++) {
        cout << nums[i] << " \n"[i + 1 == N];
    }
}

vector<int> solve(int N, int M) {
    vector<int> nums;
    int B = 0;
    for (int s = 1; s <= N; s++) {
        B += (s - 1) / 2;
    }
    if (M == 0) {
        for (int i = 1; i <= N; i++) {
            nums.push_back(int(1e8) + i);
        }
    } else if (M == B) {
        for (int i = 1; i <= N; i++) {
            nums.push_back(i);
        }
    } else if (0 < M && M < B) {
        int S = 0;
        for (int s = 1; s < N; s++) {
            S += (s - 1) / 2;
            nums.push_back(s);
            if (S <= M && M < S + s / 2) {
                int take = s / 2 - M + S;
                int add = s + 1 + (s % 2) + 2 * take;
                nums.push_back(add);
                break;
            }
        }
        int K = nums.size();
        while (K < N) {
            nums.push_back(int(4e8) + 20'000 * K++);
        }
    }
    return nums;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    auto nums = solve(N, M);
    if (nums.empty()) {
        cout << -1 << '\n';
    } else {
        output(nums);
    }
    return 0;
}

// Can't do better than 1...n