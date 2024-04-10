#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 62, inf = 1111111111;

long long ans, s, x, dp[max_n][2];

bool get_bit(long long x, int poz) {
    return (bool) (x & (1LL << poz));
}

int solve() {
    int ans = 0;
    for (int i = 1; i < s; ++i) {
        if ((i ^ (s - i)) == x) {
            cout << i << " " << s - i << endl;
            ++ans;
        }
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> x;
    //cout << solve() << endl;
    if (x == 0) {
        if (s % 2 == 0) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < 2; ++j) {
            //if (i < 10)
            //cout << i << " " << j << " : " << dp[i][j] << endl;
            for (int k = 0; k < 2; ++k) {
                int q = get_bit(x, i) ^ k;
                int sum = j + k + q;
                if (sum % 2 == get_bit(s, i)) {
                    /*if (dp[i][j]) {
                        if (i < 10) cout << i << " " << j << " -> " << i + 1 << " " << sum / 2 << endl;
                    }*/
                    dp[i + 1][sum / 2] += dp[i][j];
                }
            }
        }
    }
    if (s == x) {
        dp[max_n - 1][0] -= 2;
    }
    cout << dp[max_n - 1][0] << endl;
    return 0;
}