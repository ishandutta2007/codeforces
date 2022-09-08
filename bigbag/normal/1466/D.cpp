/**
 *  created: 30/12/2020, 16:58:30
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n;
pair<int, int> a[max_n];
vector<int> g[max_n];

bool cmp(int x, int y) {
    return a[x] < a[y];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i].first);
            a[i].second = 0;
            ans += a[i].first;
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            ++a[u].second;
            ++a[v].second;
        }
        sort(a, a + n);
        reverse(a, a + n);
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int st = 1;
            if (i == 0) {
                st = 1;
            }
            for (int j = st; j < a[i].second; ++j) {
                v.push_back(a[i].first);
            }
        }
        printf("%I64d ", ans);
        for (int x : v) {
            ans += x;
            printf("%I64d ", ans);
        }
        puts("");
    }
    return 0;
}