#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dis[510][510], dis2[510];
int u[250010], v[250010], w[250010];
int n, m;
void rmain() {
    scanf("%d%d", &n, &m);
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", u + i, v + i, w + i);
        dis[u[i]][v[i]] = dis[v[i]][u[i]] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
    for (int i = 1; i <= n; i++) dis2[i] = dis[1][i] + dis[n][i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) dis2[j] = min(dis2[j], dis2[i] + dis[i][j]);
    ll ans = 1e18;
    for (int i = 1; i <= m; i++) ans = min(ans, 1ll * min(min(dis2[u[i]], dis2[v[i]]) + 2, min(dis[1][u[i]] + dis[n][v[i]], dis[n][u[i]] + dis[1][v[i]]) + 1) * w[i]);
    printf("%lld\n", ans);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}