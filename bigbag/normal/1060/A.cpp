#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, cnt;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '8') {
            ++cnt;
        }
    }
    int ans = 0;
    for (int i = 1; i <= cnt; ++i) {
        int x = min(i, (n - i) / 10);
        ans = max(ans, x);
    }
    cout << ans << "\n";
    return 0;
}