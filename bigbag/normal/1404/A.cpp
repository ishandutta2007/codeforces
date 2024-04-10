#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

char buf[max_n];

string read() {
    scanf("%s", buf);
    return buf;
}

int t, n, k, used[max_n][2];
int cnt[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        string s = read();
        for (int i = 0; i < k; ++i) {
            used[i][0] = 0;
            used[i][1] = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] != '?') {
                used[i % k][s[i] - '0'] = 1;
            }
        }
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < k; ++i) {
            if (s[i] == '?') {
                if (!used[i][1]) {
                    ++cnt[0];
                }
                if (!used[i][0]) {
                    ++cnt[1];
                }
            } else {
                ++cnt[s[i] - '0'];
            }
        }
        bool ok = min(cnt[0], cnt[1]) >= k / 2;
        for (int i = 0; i < k; ++i) {
            ok &= (used[i][0] + used[i][1]) < 2;
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}