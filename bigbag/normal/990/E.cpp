#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111;
const long long inf = 1000111222000111222LL;

int n, m, k, used[max_n], l[max_n];
long long ans = inf;

int get(int len) {
    int x = 0, res = 0;
    while (x < n) {
        if (used[x]) {
            int pos = l[x];
            if (pos + len <= x) {
                return -1;
            }
            x = pos + len;
            ++res;
        } else {
            ++res;
            x += len;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int pos;
        scanf("%d", &pos);
        used[pos] = 1;
    }
    used[n] = 1;
    l[0] = 0;
    if (used[0]) {
        l[0] = -1000111222;
    }
    for (int i = 1; i <= n; ++i) {
        l[i] = i;
        if (used[i]) {
            l[i] = l[i - 1];
        }
    }
    for (int i = 1; i <= k; ++i) {
        int cost;
        scanf("%d", &cost);
        int res = get(i);
        //cout << i << " " << res << endl;
        if (res != -1) {
            ans = min(ans, 1LL * res * cost);
        }
    }
    if (ans == inf) {
        ans = -1;
    }
    printf("%I64d\n", ans);
    return 0;
}