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

const int max_n = 1011, mod = 1000000007;

string n;
int k, ans, dp[max_n], c[max_n][max_n];

void get_all_c() {
    c[0][0] = 1;
    for (int i = 1; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
}

int f(int cnt) {
    int res = 0;
    int x = cnt;
    for (int i = 0; i < n.length(); ++i) {
        if (n[i] == '1') {
            res += c[n.length() - i - 1][x];
            res %= mod;
            --x;
        }
        if (x < 0) {
            break;
        }
    }
    if (x == 0) {
        ++res;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_c();
    cin >> n >> k;
    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; i < max_n; ++i) {
        int cnt = 0, x = i;
        while (x) {
            cnt += x % 2;
            x /= 2;
        }
        dp[i] = dp[cnt] + 1;
    }
    for (int i = 1; i < max_n; ++i) {
        if (dp[i] + 1 == k) {
            if (i == 1) {
                ans = mod - 1;
            }
            ans += f(i);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}