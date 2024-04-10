#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n;
long long cv, cur, ans;
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s", s);
    n = strlen(s);
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'v' && s[i - 1] == 'v') {
            ans += cur;
            ++cv;
        } else if (s[i] == 'o') {
            cur += cv;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}