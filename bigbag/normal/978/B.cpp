#include <bits/stdc++.h>

using namespace std;

int n, ans;
string s;

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        while (i < n && s[i] == 'x') {
            ++cnt;
            ++i;
        }
        ans += max(0, cnt - 2);
    }
    cout << ans << endl;
    return 0;
}