#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int ans, p, n, x;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &p, &n);
    ans = 0;
    while (n--) {
        scanf("%d", &x);
        ans = (ans * p + x) % 2;
    }
    if (ans) {
        puts("odd");
    } else {
        puts("even");
    }
    return 0;
}