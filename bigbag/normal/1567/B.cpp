/**
 *  created: 05/09/2021, 17:38:38
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int t, a, b, pref[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 1; i < max_n; ++i) {
        pref[i] = pref[i - 1] ^ i;
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        b ^= pref[a - 1];
        int ans = a;
        if (b == 0) {
        } else if (b != a) {
            ++ans;
        } else {
            ans += 2;
        }
        printf("%d\n", ans);
    }

    return 0;
}