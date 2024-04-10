#include <bits/stdc++.h>

using namespace std;

const int max_n = 40;
int mod;

int t, x, dp[max_n], cnt[max_n];
vector<int> v;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

void get_v(int x) {
    v.clear();
    while (x) {
        v.push_back(x % 2);
        x /= 2;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> x >> mod;
        get_v(x);
        for (int i = 0; i < v.size(); ++i) {
            cnt[i] = 1 << i;
        }
        cnt[v.size() - 1] = 1 + x - (1 << (v.size() - 1));
        for (int i = 0; i < v.size(); ++i) {
            cnt[i] %= mod;
            dp[i] = cnt[i];
        }
        for (int i = 0; i < v.size(); ++i) {
            for (int j = i + 1; j < v.size(); ++j) {
                dp[j] += mul(dp[i], cnt[j]);
                dp[j] %= mod;
            }
        }
        cout << accumulate(dp, dp + v.size(), 0LL) % mod << "\n";
    }
    return 0;
}