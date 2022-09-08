/**
 *  created: 12/11/2021, 16:50:50
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;
string s;

int solve() {
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        vector<int> cnt(3);
        for (int len = 1; i + len <= n && len < 11; ++len) {
            ++cnt[s[i + len - 1] - 'a'];
            if (len > 1 && cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
                ans = min(ans, len);
            }
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    return ans;
    /*for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == 'a' && s[i + 1] == 'a') {
            return 2;
        }
    }
    for (int i = 0; i + 2 < n; ++i) {
        if (s[i] == 'a' && s[i + 2] == 'a') {
            return 3;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            int pos = i;
            while (pos + 3 < n && a[pos + 3] == 'a') {
                pos += 3;
            }
            for (int j = i; j <= pos; j += 3) {

            }
            i = pos;
        }
    }*/
    return -1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        cout << solve() << "\n";
    }
    return 0;
}