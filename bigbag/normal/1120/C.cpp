#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

void get_prefix_function(const string &s, int p[]) {
    p[0] = 0;
    for (int i = 1; i < s.length(); ++i) {
        p[i] = p[i - 1];
        while (p[i] > 0 && s[i] != s[p[i]]) {
            p[i] = p[p[i] - 1];
        }
        if (s[i] == s[p[i]]) {
            ++p[i];
        }
    }
}

int n, a, b, p[max_n], mx[max_n], dp[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> a >> b >> s;
    for (int i = 1; i < n; ++i) {
        string t = s.substr(i) + "#" + s.substr(0, i);
        get_prefix_function(t, p);
        for (int j = n - i; j < t.length(); ++j) {
            mx[i] = max(mx[i], p[j]);
        }
    }
    dp[0] = a;
    for (int i = 1; i < n; ++i) {
        dp[i] = a + dp[i - 1];
        for (int j = 0; j < i; ++j) {
            if (mx[j + 1] >= i - j) {
                dp[i] = min(dp[i], dp[j] + b);
            }
        }
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}