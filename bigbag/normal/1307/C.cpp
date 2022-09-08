#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;
const int max_c = 30;

int n, cnt[max_c];
long long cnt2[max_c][max_c];
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        for (int c = 0; c < max_c; ++c) {
            cnt2[c][s[i] - 'a'] += cnt[c];
        }
        ++cnt[s[i] - 'a'];
    }
    long long ans = *max_element(cnt, cnt + max_c);
    for (int c = 0; c < max_c; ++c) {
        for (int c2 = 0; c2 < max_c; ++c2) {
            ans = max(ans, cnt2[c][c2]);
        }
    }
    cout << ans << "\n";
    return 0;
}