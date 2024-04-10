#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n;
pair<int, int> a[max_n];
long long w;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%I64d", &n, &w);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        sort(a, a + n);
        reverse(a, a + n);
        long long sum = 0;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (sum + a[i].first <= w) {
                sum += a[i].first;
                ans.push_back(a[i].second);
            }
        }
        if (sum * 2 < w) {
            puts("-1");
        } else {
            printf("%d\n", ans.size());
            for (int x : ans) {
                printf("%d ", 1 + x);
            }
            puts("");
        }
    }
    return 0;
}