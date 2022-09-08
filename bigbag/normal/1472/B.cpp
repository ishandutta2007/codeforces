/**
 *  created: 04/01/2021, 16:37:34
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, cnt[3];

bool solve() {
    if (cnt[1] % 2) {
        return false;
    }
    if (cnt[2] % 2) {
        if (!cnt[1]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        cnt[1] = cnt[2] = 0;
        while (n--) {
            int x;
            scanf("%d", &x);
            ++cnt[x];
        }
        if (solve()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}