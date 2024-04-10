/**
 *  created: 18/02/2021, 16:36:48
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n;
long long a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }
        bool ok = 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] < i) {
                ok = 0;
                break;
            }
            a[i + 1] += a[i] - i;
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}