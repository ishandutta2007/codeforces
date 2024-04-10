/**
 *  created: 11/07/2021, 17:08:19
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int tests, n, a[max_n];

bool ok() {
    map<int, int> q;
    for (int i = 0; i < n; ++i) {
        if (i % 2) {
            ++q[a[i]];
        }
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (i % 2) {
            --q[a[i]];
        }
    }
    for (auto p : q) {
        if (p.second) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &tests);
    while (tests--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        if (ok()) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}