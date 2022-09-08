/**
 *  created: 17/03/2021, 16:49:17
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 3; i < k; ++i) {
            printf("1 ");
        }
        n -= k - 3;
        if (n % 4 == 0) {
            printf("%d %d %d\n", n / 4, n / 4, n / 2);
            continue;
        }
        int pw = 1;
        while (n % (2LL * pw) == 0) {
            pw *= 2;
        }
        n /= pw;
        printf("%d %d %d\n", pw, pw * (n / 2), pw * (n / 2));
    }
    return 0;
}