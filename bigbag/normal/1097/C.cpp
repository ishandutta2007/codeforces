#include <bits/stdc++.h>

using namespace std;

const int max_len = 500555, inf = 1000111222;

char s[max_len];
int n, ans, tot[max_len][2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int len = strlen(s);
        int bal = 0, min_bal = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                ++bal;
            } else {
                --bal;
            }
            min_bal = min(min_bal, bal);
        }
        if (bal > 0) {
            if (min_bal >= 0) {
                ++tot[bal][0];
            }
        } else if (bal < 0) {
            if (min_bal - bal >= 0) {
                ++tot[-bal][1];
            }
        } else if (bal == 0 && min_bal >= 0) {
            ++ans;
        }
    }
    ans /= 2;
    for (int i = 1; i < max_len; ++i) {
        ans += min(tot[i][0], tot[i][1]);
    }
    printf("%d\n", ans);
    return 0;
}