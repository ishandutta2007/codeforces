#include <bits/stdc++.h>

using namespace std;

int n, a, x;
map<int, int> q;
long long ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int it = 0; it < 2; ++it) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a, &x);
            q[a] = max(q[a], x);
        }
    }
    for (const pair<int, int> &p : q) {
        ans += p.second;
    }
    printf("%I64d\n", ans);
    return 0;
}