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

const int max_n = 111111, mod = 1000000007;

long long n, dp[11], len[11];
string s, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 10; ++i) {
        dp[i] = i;
        len[i] = 10;
    }
    for (int i = n - 1; i >= 0; --i) {
        long long ndp = 0, nlen = 1, digit;
        for (int j = 3; j < a[i].length(); ++j) {
            digit = a[i][j] - '0';
            ndp = ((ndp * len[digit]) % mod + dp[digit]) % mod;
            nlen = (nlen * len[digit]) % mod;
        }
        dp[a[i][0] - '0'] = ndp;
        len[a[i][0] - '0'] = nlen;
    }
    long long ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        long long digit = s[i] - '0';
        ans = ((ans * len[digit]) % mod + dp[digit]) % mod;
    }
    cout << ans << endl;
    return 0;
}