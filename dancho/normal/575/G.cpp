#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> g[1 << 20];
int ne[1 << 20];

map<pii, int> mp;

queue<int> q;

int dep[1 << 20];
vector<int> bu[1 << 20];
queue< vector<int> > qq;

char ou[1 << 20];
vector<int> p;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        scanf("%d %d %d", &a, &b, &l);
        g[a].push_back(make_pair(b, l));
        g[b].push_back(make_pair(a, l));
        mp[make_pair(a, b)] = mp[make_pair(b, a)] = l;
    }
    memset(ne, -1, sizeof(ne));

    // Start with 0s
    qq.push(vector<int>());
    ne[n - 1] = -2;
    q.push(n - 1);
    dep[n - 1] = 0;
    bu[0].push_back(n - 1);
    while (q.size()) {
        int v = q.front();
        q.pop();
        qq.back().push_back(v);
        for (int i = 0; i < (int) g[v].size(); ++i) {
            if (g[v][i].second == 0) {
                int u = g[v][i].first;
                if (ne[u] == -1) {
                    ne[u] = v;
                    dep[u] = dep[v] + 1;
                    bu[dep[u]].push_back(u);
                    q.push(u);
                }
            }
        }
    }

    while (ne[0] == -1) {
        // printf("OP %d\n", (int) qq.size());
        vector<int> els = qq.front();
        qq.pop();
        for (int l = 0; l <= 9; ++l) {
            bool ad = false;
            for (int i = 0; i < (int) els.size(); ++i) {
                int v = els[i];
                for (int j = 0; j < (int) g[v].size(); ++j) {
                    if (g[v][j].second != l) continue;
                    int u = g[v][j].first;
                    if (ne[u] == -1) {
                        ne[u] = v;
                        if (!ad) {
                            qq.push(vector<int>());
                            ad = true;
                        }
                        qq.back().push_back(u);
                    }
                }
            }
        }
    }

    int l = (1 << 19);
    ou[l] = 0;
    p.push_back(0);
    int k = ne[0];
    while (k != -2) {
        ou[--l] = '0' + mp[make_pair(p.back(), k)];
        p.push_back(k);
        k = ne[k];
    }
    while (ou[l] == '0') {
        ++l;
    }
    if (ou[l] == 0) {
        printf("0\n");
    } else {
        printf("%s\n", ou + l);
    }
    printf("%d\n", (int) p.size());
    printf("%d", p[0]);
    for (int i = 1; i < (int) p.size(); ++i) {
        printf(" %d", p[i]);
    }
    printf("\n");
    return 0;
}