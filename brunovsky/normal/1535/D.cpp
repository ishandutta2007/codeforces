#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int K;
    string str;
    cin >> K >> str;
    int N = (1 << K);
    str = "#" + str;

    vector<int> mapping(N);

    string new_s(N, '#');
    for (int s = 1, step = K - 1; step >= 0; step--) {
        for (int i = 0; i < (1 << step); i++) {
            mapping[s] = (1 << step) + i;
            new_s[mapping[s]] = str[s];
            s++;
        }
    }
    str = new_s;

    vector<int> dp(2 * N);
    for (int i = 0; i < N; i++) {
        dp[i + N] = 1;
    }
    auto update = [&](int i) {
        if (str[i] == '1') {
            dp[i] = dp[i << 1 | 1];
        } else if (str[i] == '0') {
            dp[i] = dp[i << 1];
        } else {
            dp[i] = dp[i << 1] + dp[i << 1 | 1];
        }
    };
    for (int i = N - 1; i >= 1; i--) {
        update(i);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int p;
        string c;
        cin >> p >> c;
        int i = mapping[p];
        str[i] = c[0];
        while (i >= 1) {
            update(i);
            i >>= 1;
        }
        cout << dp[1] << endl;
    }

    return 0;
}