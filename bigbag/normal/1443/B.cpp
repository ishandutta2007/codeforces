#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, a, b, n;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%s", &a, &b, s);
        n = strlen(s);
        int last = -1;
        vector<int> v;
        int cnt = 0;
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                ++i;
            } else {
                if (last != -1) {
                    v.push_back(i - last);
                }
                ++cnt;
                while (i < n && s[i] == '1') {
                    ++i;
                }
                last = i;
            }
        }
        sort(v.begin(), v.end());
        int res = cnt * a, ans = cnt * a;
        for (int x : v) {
            res += x * b;
            res -= a;
            ans = min(ans, res);
        }
        printf("%d\n", ans);
    }
    return 0;
}