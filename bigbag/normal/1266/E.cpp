#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int n, t, a[max_n];
map<pair<int, int>, int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ans += a[i];
    }
    scanf("%d", &t);
    while (t--) {
        int s, t, num;
        scanf("%d%d%d", &s, &t, &num);
        --s;
        --num;
        if (q.count({s, t})) {
            int old = q[{s, t}];
            if (a[old] >= 0) {
                ++ans;
            }
            ++a[old];
            q.erase({s, t});
        }
        if (num != -1) {
            if (a[num] > 0) {
                --ans;
            }
            --a[num];
            q[{s, t}] = num;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}