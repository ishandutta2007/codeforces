#include <iostream>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;

const int mx = 6000;
const ll p = 141, mod = 1791791791;
string s, s1;
ll base[mx], hs[mx], hs1[mx];
int n, dp[mx][mx], ans[mx];

ll gethash(int i, int j) {
    return (hs[j+1] - hs[i] + mod) % mod;
}

ll gethash1(int i, int j) {
    return (hs1[j+1] - hs1[i] + mod) % mod;
}

bool nice(int i, int j) {
    ll hash1 = gethash(i, j);
    ll hash2 = gethash1(n - j - 1, n - i - 1);
    if (i < n - j - 1)
        return ((hash1 * base[n - j - i - 1] % mod + mod) % mod == hash2);
    else
        return ((hash2 * base[i + j + 1 - n] % mod + mod) % mod == hash1);
}

int main()
{
    cin >> s;
    n = s.length();
    s1 = s;
    reverse(s1.begin(), s1.end());
    base[0] = 1;
    for (int i = 1; i < mx; ++i) {
        base[i] = (base[i-1] * p) % mod;
    }
    for (int i = 1; i <= n; ++i) {
        hs[i] = (hs[i-1] + (s[i-1] - 'a') * base[i]) % mod;
        hs1[i] = (hs1[i-1] + (s1[i-1] - 'a') * base[i]) % mod;
    }
    for (int i = 0; i < mx; ++i) {
        for (int j = 0; j < mx; ++j) {
            dp[i][j] = -1;
        }
    }
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            if (nice(i, j))
                dp[i][j] = min(dp[i][i + len / 2 - 1], dp[j - len / 2 + 1][j]) + 1;
            else
                dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ans[dp[i][j]]++;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        ans[i] += ans[i+1];
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    return 0;
}