/**
 *  created: 25/01/2021, 17:00:24
**/

#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        while (n % 2 == 0) {
            n /= 2;
        }
        if (n > 1) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}