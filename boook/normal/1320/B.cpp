#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

vector<int> G[N];
vector<int> revG[N];
int p[N];
int dis[N];

int main () {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        G[x].push_back(y);
        revG[y].push_back(x);
    }
    int k; scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &p[i]);
    }
    memset(dis, -1, sizeof(dis));
    dis[ p[k] ] = 1;
    queue<int> que;
    que.push(p[k]);
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i: revG[t]) {
            if (dis[i] == -1) {
                dis[i] = dis[t] + 1;
                que.push(i);
            }
        }
    }
    int mn = 0, mx = 0;
    for (int i = 2; i <= k; ++i) {
        if (dis[ p[i - 1] ] != dis[ p[i] ] + 1) {
            ++mx; ++mn;
        }
        else {
            int cnt = 0;
            for (int j: G[ p[i - 1] ]) {
                if (dis[ p[i - 1] ] == dis[j] + 1) {
                    ++cnt;
                }
            }
            if (cnt > 1) ++mx;
        }
    }
    printf("%d %d\n", mn, mx);
}