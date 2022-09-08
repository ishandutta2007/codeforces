/**
 *  created: 29/08/2021, 17:36:39
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        if ((a + b) % 2) {
            puts("-1");
        } else if (a == b) {
            if (a == 0) {
                puts("0");
            } else {
                puts("1");
            }
        } else {
            puts("2");
        }
    }
    return 0;
}