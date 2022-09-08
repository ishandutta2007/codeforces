#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, a[max_n];
vector<pair<long long, int>> dp;

bool cmp(const pair<long long, int> &a, const pair<long long, int> &b) {
    return a.first * b.second <= b.first * a.second;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    dp.push_back({a[n - 1], 1});
    for (int i = n - 2; i >= 0; --i) {
        dp.push_back({a[i], 1});
        while (dp.size() >= 2) {
            pair<long long, int> p(dp.back().first + dp[dp.size() - 2].first, dp.back().second + dp[dp.size() - 2].second);
            if (cmp(p, dp.back())) {
                dp.pop_back();
                dp.pop_back();
                dp.push_back(p);
            } else {
                break;
            }
        }
    }
    while (!dp.empty()) {
        double val = 1.0 * dp.back().first / dp.back().second;
        for (int j = 0; j < dp.back().second; ++j) {
            printf("%.15f\n", val);
        }
        dp.pop_back();
    }
    return 0;
}