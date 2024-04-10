/**
 *  created: 02/05/2021, 17:46:40
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, m, x, ans[max_n];
pair<int, int> a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &m, &x);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            ans[a[i].second] = i % m;
        }
        puts("YES");
        for (int i = 0; i < n; ++i) {
            printf("%d ", ans[i] + 1);
        }
        puts("");
    }
    return 0;
}