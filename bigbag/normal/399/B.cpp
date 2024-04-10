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

const int max_n = 55, inf = 111111111;

long long n, dp[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    reverse(s.begin(), s.end());
    dp[1] = 1;
    for (int i = 2; i < max_n; ++i) {
        dp[i] = 2 * dp[i - 1] + 1;
    }
    long long ans = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == 'B') {
            ans += 1 + dp[s.length() - i - 1];
            s[i] = 'R';
        }
    }
    cout << ans << endl;
    return 0;
}