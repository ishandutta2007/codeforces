#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int ad[512][512];

int md[512];

int bfs(int e) {
    queue<int> q;
    q.push(1);
    memset(md, -1, sizeof(md));
    md[1] = 0;
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= n; ++i) {
            if (ad[i][v] == e && md[i] == -1) {
                md[i] = md[v] + 1;
                q.push(i);
            }
        }
    }
    return md[n];
}

int main() {
    scanf("%d %d", &n, &m);
    memset(ad, 0, sizeof(n));
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        ad[a][b] = ad[b][a] = 1;
    }

    int k = bfs(0);
    int l = bfs(1);
    if (k == -1 || l == -1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", max(k, l));
    return 0;
}