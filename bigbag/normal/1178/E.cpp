#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n;
char s[max_n];

void solve(int l, int r) {
    if (l == r) {
        printf("%c", s[l]);
        return;
    }
    if (l > r) {
        return;
    }
    if (s[l] == s[r]) {
        printf("%c", s[l]);
        solve(l + 1, r - 1);
        printf("%c", s[r]);
        return;
    }
    if (s[l] == s[r - 1]) {
        solve(l, r - 1);
        return;
    }
    if (s[l + 1] == s[r]) {
        solve(l + 1, r);
        return;
    }
    solve(l + 1, r - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s", s);
    n = strlen(s);
    solve(0, n - 1);
    return 0;
}