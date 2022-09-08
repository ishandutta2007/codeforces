/**
 *  created: 22/07/2021, 17:36:24
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", n / 10 + (n % 10 == 9));
    }
    return 0;
}