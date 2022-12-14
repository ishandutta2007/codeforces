#include <bits/stdc++.h>

using namespace std;

int n, m, P[100005];

int find(int x) {
    return P[x] == x ? x : P[x] = find(P[x]);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) P[i] = i;
        int ans = m;
        for (int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == y) ans--;
            else if (find(x) == find(y)) ans++;
            else {
                P[find(x)] = find(y);
            }
        }
        printf("%d\n", ans);
    }
}