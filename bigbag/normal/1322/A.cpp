#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, ans;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s", &n, s);
    int bal = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++bal;
        } else {
            --bal;
            if (bal < 0) {
                ++ans;
                while (i + 1 < n && bal < 0) {
                    ++ans;
                    ++i;
                    if (s[i] == '(') {
                        ++bal;
                    } else {
                        --bal;
                    }
                }
            }
        }
    }
    if (bal != 0) {
        ans = -1;
    }
    printf("%d\n", ans);
    return 0;
}