/**
 *  created: 16/02/2021, 16:39:43
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t, n, x, cnt[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int need = n / 3;
        cnt[0] = cnt[1] = cnt[2] = 0;
        while (n--) {
            scanf("%d", &x);
            ++cnt[x % 3];
        }
        int ans = 0;
        while (cnt[0] != cnt[1] || cnt[1] != cnt[2]) {
            int pos = max_element(cnt, cnt + 3) - cnt;
            --cnt[pos];
            ++cnt[(pos + 1) % 3];
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}