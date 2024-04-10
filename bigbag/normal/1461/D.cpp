/**
 *  created: 11/12/2020, 16:49:39
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, q, a[max_n];
set<int> ans;

void solve(int l, int r) {
    const long long sum = accumulate(a + l, a + r + 1, 0LL);
    if (sum < inf) {
        ans.insert(sum);
    }
    if (l == r) {
        return;
    }
    int val = (a[l] + a[r]) / 2, cnt = 0;
    for (int i = l; i <= r; ++i) {
        if (a[i] <= val) {
            ++cnt;
        }
    }
    if (cnt == 0 || cnt == r - l + 1) {
        return;
    }
    solve(l, l + cnt - 1);
    solve(l + cnt, r);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        ans.clear();
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        solve(0, n - 1);
        while (q--) {
            int x;
            scanf("%d", &x);
            if (ans.count(x)) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
    }
    return 0;
}