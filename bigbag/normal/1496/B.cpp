/**
 *  created: 10/03/2021, 17:53:17
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, k, a[max_n];

int solve() {
    set<int> q(a, a + n);
    int x = 0;
    while (k--) {
        while (q.count(x)) {
            ++x;
        }
        int mx = *q.rbegin();
        int val = (x + mx + 1) / 2;
        if (mx < val) {
            return q.size() + k + 1;
        }
        if (q.count(val)) {
            break;
        }
        q.insert(val);
    }
    return q.size();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", solve());
    }
    return 0;
}