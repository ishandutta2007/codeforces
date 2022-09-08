/**
 *  created: 25/01/2021, 17:01:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    a[0] = 1;
    a[2020] = 1;
    for (int i = 2021; i < max_n; ++i) {
        a[i] = a[i - 2020] | a[i - 2021];
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (a[n]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}