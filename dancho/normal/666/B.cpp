#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int INF = 1000000000;

int n;

void bfs(int s, const vector<vector<int> > &g, vector<int> &dt) {
    queue<int> q;
    q.push(s);
    dt.assign(n, INF);
    dt[s] = 0;
    while (q.size()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i];
            if (dt[v] + 1 < dt[u]) {
                dt[u] = dt[v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    int m;
    vector<vector<int> > g, gr;
    scanf("%d %d", &n, &m);
    g.resize(n);
    gr.resize(n);
    for (int i = 0; i < m; ++i) {
        int j, k;
        scanf("%d %d", &j, &k);
        --j; --k;
        g[j].push_back(k);
        gr[k].push_back(j);
    }
    vector<vector<int> > lf(n);
    vector<vector<int> > lr(n);
    for (int i = 0; i < n; ++i) {
        bfs(i, g, lf[i]);
        bfs(i, gr, lr[i]);
    }
    vector< vector<pair<int, int> > > lfs(n), lfr(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (lf[i][j] != INF) {
                lfs[i].push_back(make_pair(lf[i][j], j));
            }
            if (lr[i][j] != INF) {
                lfr[i].push_back(make_pair(lr[i][j], j));
            }
        }
        sort(lfs[i].begin(), lfs[i].end(), greater<pair<int, int> >());
        sort(lfr[i].begin(), lfr[i].end(), greater<pair<int, int> >());
    }

    int bsl = -1;
    vector<int> s;
    for (int a2 = 0; a2 < n; ++a2) {
        for (int a3 = 0; a3 < n; ++a3) {
            if (a2 == a3) {
                continue;
            }
            if (lf[a2][a3] == INF) {
                continue;
            }
            for (int i = 0; i < 4 && i < (int) lfr[a2].size(); ++i) {
                if (a2 == lfr[a2][i].second) {
                    continue;
                }
                if (a3 == lfr[a2][i].second) {
                    continue;
                }
                for (int j = 0; j < 4 && j < (int) lfs[a3].size(); ++j) {
                    if (a2 == lfs[a3][j].second) {
                        continue;
                    }
                    if (a3 == lfs[a3][j].second) {
                        continue;
                    }
                    if (lfs[a3][j].second == lfr[a2][i].second) {
                        continue;
                    }
                    if (lf[a2][a3] + lfr[a2][i].first + lfs[a3][j].first > bsl) {
                        // printf("SL %d %d\n", a2, a3);
                        bsl = lf[a2][a3] + lfr[a2][i].first + lfs[a3][j].first;
                        s.clear();
                        s.push_back(lfr[a2][i].second);
                        s.push_back(a2);
                        s.push_back(a3);
                        s.push_back(lfs[a3][j].second);
                    }
                    break;
                }
            }
        }
    }
    printf("%d %d %d %d\n", s[0] + 1, s[1] + 1, s[2] + 1, s[3] + 1);
    return 0;
}