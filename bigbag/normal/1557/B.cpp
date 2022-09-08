/**
 *  created: 09/08/2021, 17:38:19
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, k, pos[max_n];
pair<int, int> a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i].first);
            a[i].second = i;
        }
        sort(a, a + n);
        for (int i = 0; i < n; ++i) {
            pos[a[i].second] = i;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            ++cnt;
            while (i + 1 < n && pos[i] + 1 == pos[i + 1]) {
                ++i;
            }
        }
        if (cnt <= k) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}