#include <bits/stdc++.h>

using namespace std;

const int max_n = 222, inf = 1000111222;

int n, k, ans, used[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        used[s[i]] = 1;
    }
    for (char c = 'a'; c <= 'z' && k; ++c) {
        if (used[c]) {
            --k;
            ans += c - 'a' + 1;
            ++c;
        }
    }
    if (k) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}