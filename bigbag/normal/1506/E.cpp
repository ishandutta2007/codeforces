/**
 *  created: 25/03/2021, 16:49:52
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> ans(n, -1);
        vector<int> used(n + 1);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (i == 0 || a[i] != a[i - 1]) {
                ans[i] = a[i];
                used[a[i]] = 1;
            }
        }
        vector<int> v;
        for (int x = 1; x <= n; ++x) {
            if (!used[x]) {
                v.push_back(x);
            }
        }
        int num = 0;
        for (int i = 0; i < n; ++i) {
            if (ans[i] != -1) {
                printf("%d ", ans[i]);
            } else {
                printf("%d ", v[num++]);
            }
        }
        puts("");
        set<int> q(v.begin(), v.end());
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (ans[i] != -1) {
                printf("%d ", ans[i]);
                last = ans[i];
            } else {
                auto it = q.lower_bound(last);
                --it;
                printf("%d ", *it);
                q.erase(it);
            }
        }
        puts("");
    }
    return 0;
}