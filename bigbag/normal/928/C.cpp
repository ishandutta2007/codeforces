#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

char buf[15];

struct project {
    string name;
    int version, name_id;
    project() {
    }
    void read() {
        scanf("%s%d", buf, &version);
        name = buf;
    }
    void write() const {
        printf("%s %d\n", name.c_str(), version);
    }
    bool operator < (const project &p) const {
        return name < p.name || name == p.name && version < p.version;
    }
};

int n, dist[max_n], best[max_n];
project p[max_n];
vector<project> to[max_n];
vector<int> g[max_n];
map<project, int> ids;
map<string, int> names;
vector<project> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        p[i].read();
        int m;
        scanf("%d", &m);
        to[i].resize(m);
        for (int j = 0; j < m; ++j) {
            to[i][j].read();
        }
        ids[p[i]] = i;
        names[p[i].name] = i;
    }
    for (int i = 0; i < n; ++i) {
        p[i].name_id = names[p[i].name];
        g[i].resize(to[i].size());
        for (int j = 0; j < to[i].size(); ++j) {
            g[i][j] = ids[to[i][j]];
        }
    }
    queue<int> q;
    q.push(0);
    memset(best, -1, sizeof(best));
    best[p[0].name_id] = 0;
    for (int it = 1; !q.empty(); ++it) {
        queue<int> q2;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            if (v) {
                ans.push_back(p[v]);
            }
            for (int to : g[v]) {
                if (best[p[to].name_id] == -1) {
                    q2.push(p[to].name_id);
                    dist[p[to].name_id] = it;
                    best[p[to].name_id] = to;
                } else if (dist[p[to].name_id] == it && p[best[p[to].name_id]].version < p[to].version) {
                    best[p[to].name_id] = to;
                }
            }
        }
        while (!q2.empty()) {
            int name_id = q2.front();
            q2.pop();
            q.push(best[name_id]);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        ans[i].write();
    }
    return 0;
}