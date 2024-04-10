/**
 *  created: 02/05/2021, 17:41:04
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;

bool is_sqrt(int x) {
    int y = sqrt(x);
    return y * y == x || ((y + 1) * (y + 1) == x) || ((y - 1) * (y - 1) == x);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if ((n % 2 == 0 && is_sqrt(n / 2)) || (n % 4 == 0 && is_sqrt(n / 4))) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}