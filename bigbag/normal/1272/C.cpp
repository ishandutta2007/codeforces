#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, k, ok[222], a[max_n];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    while (k--) {
        char c;
        cin >> c;
        ok[c] = 1;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int pos = i;
        while (i < n && ok[s[i]]) {
            ++i;
        }
        ans += 1LL * (i - pos) * (i - pos + 1) / 2;
    }
    cout << ans << "\n";
    return 0;
}