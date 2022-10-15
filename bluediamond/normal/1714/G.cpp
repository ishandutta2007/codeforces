#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9 + 7;
const int N = 200005;
 
vector<int> G[N];
int a[N], b[N], ans[N];
LL s[N];
void dfs(int u, int d, LL now) {
    now += a[u];
    s[d] = s[d - 1] + b[u];
    ans[u] = upper_bound(s + 1, s + d + 1, now) - s - 1;
    for (auto v : G[u]) {
        dfs(v, d + 1, now);
    }
}
int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 2; i <= n; i++) {
            int fa;
            scanf("%d %d %d", &fa, &a[i], &b[i]);
            G[fa].push_back(i);
        }
        dfs(1, 0, 0);
        for (int i = 2; i <= n; i++) {
            printf("%d%c", ans[i], " \n"[i == n]);
        }
    }
    return 0;
}