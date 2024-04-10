#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

const char* YES = "Yes";
const char* NO = "No";

vector<vector<int>> g;

int starts[2];
int fixedDegrees[2];

vector<int> degrees;

vector<int> used;

set<pair<int, int>> edges;

vector<int> head;

void Dfs(int v, int curHead) {
    head[v] = curHead;
    used[v] = 1;
    for (int u : g[v]) {
        if (!used[u]) {
            edges.insert(make_pair(v, u));
            ++degrees[v];
            ++degrees[u];
            if (curHead == -1) {
                Dfs(u, u);
            } else {
                Dfs(u, curHead);
            }
        }
    }
    used[v] = 2;
}

void ShowBad() {
    printf("%s\n", NO);
    exit(0);
}

void ShowGood() {
    printf("%s\n", YES);
    for (const pair<int, int>& p : edges) {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }
    exit(0);
}

void ShowResult() {
    for (int i = 0; i < 2; ++i) {
        if (degrees[starts[i]] > fixedDegrees[i]) {
            ShowBad();
        }
    }
    ShowGood();
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    scanf("%d%d%d%d", &starts[0], &starts[1], &fixedDegrees[0], &fixedDegrees[1]);

    --starts[0];
    --starts[1];

    used.assign(n, 0);
    degrees.assign(n, 0);
    used[starts[1]] = 2;
    head.resize(n);
    Dfs(starts[0], -1);

    used[starts[1]] = 0;

    set<int> heads;
    int base = -1;
    for (int v : g[starts[1]]) {
        if (v != starts[0] && used[v]) {
            base = v;
            heads.insert(head[v]);
        }
    }

    if (base == -1) {
        Dfs(starts[0], -1);
        ShowResult();
    } else {
        heads.erase(head[base]);

        Dfs(base, head[base]);

        if (degrees[starts[1]] > fixedDegrees[1]) {
            ShowBad();
        }

        if (degrees[starts[0]] <= fixedDegrees[0]) {
            ShowGood();
        }

        int needDelCount = degrees[starts[0]] - fixedDegrees[0];
        int canAddCount = fixedDegrees[1] - degrees[starts[1]];

        if (canAddCount < needDelCount) {
            ShowBad();
        }

        for (int v : g[starts[1]]) {
            if (v == starts[0]) {
                continue;
            }
            int ch = head[v];
            if (heads.find(ch) != heads.end()) {
                heads.erase(ch);
                edges.erase(make_pair(starts[0], ch));
                edges.insert(make_pair(v, starts[1]));
                --degrees[starts[0]];
                ++degrees[starts[1]];
                --needDelCount;
                --canAddCount;

                if (needDelCount == 0) {
                    break;
                }
            }
        }

        ShowResult();
    }

    return 0;
}