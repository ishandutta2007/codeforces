#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

const string YES = "YES";
const string NO = "NO";

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

struct TEdge {
    int From;
    int To;
    bool IsSpecial;
};

int n;
vector<vector<TEdge>> g;

vector<bool> used;
vector<int> tin;
vector<int> tout;
vector<int> up;
int curTime;

void BuildTimes(int v, int pr) {
    used[v] = true;
    tin[v] = curTime++;
    up[v] = tin[v];
    for (const TEdge& e : g[v]) {
        if (e.To == pr) {
            continue;
        }

        if (used[e.To]) {
            up[v] = min(up[v], tin[e.To]);
        } else {
            BuildTimes(e.To, v);
            up[v] = min(up[v], up[e.To]);
        }
    }
    tout[v] = curTime++;
}

vector<int> cmps;
int cmpCount;

void BuildCmps(int v, int pr, int curCmp) {
    used[v] = true;
    cmps[v] = curCmp;
    for (const TEdge& e : g[v]) {
        if (e.To == pr) {
            continue;
        }

        if (!used[e.To]) {
            if (up[e.To] > tin[v]) {
                ++cmpCount;
                BuildCmps(e.To, v, cmpCount - 1);
            } else {
                BuildCmps(e.To, v, curCmp);
            }
        }
    }
}

vector<vector<TEdge>> cg;

vector<bool> goodCmp;

vector<bool> reach;
vector<bool> goodReach;

vector<int> pr;

bool IsResult(int v, int finish) {
    used[v] = true;
    if (v == finish) {
        reach[v] = true;
        goodReach[v] = goodCmp[v];
        return goodReach[v];
    }
    reach[v] = false;
    goodReach[v] = false;
    for (const TEdge& e : cg[v]) {
        int u = e.To;

        if (!used[u]) {
            IsResult(u, finish);

            pr[u] = v;
        }
    }
    for (const TEdge& e : cg[v]) {
        int u = e.To;

        if (pr[u] == v) {
            if (reach[u]) {
                reach[v] = true;

                if (goodReach[u] || e.IsSpecial || goodCmp[v]) {
                    goodReach[v] = true;
                }
            }
        }
    }
    return goodReach[v];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2; 
        int buf;
        scanf("%d%d%d", &v1, &v2, &buf);
        --v1;
        --v2;
        bool isSpec = buf;
        g[v1].push_back(TEdge{v1, v2, isSpec});
        g[v2].push_back(TEdge{v2, v1, isSpec});
    }

    int start, finish;
    scanf("%d%d", &start, &finish);
    --start;
    --finish;

    used.assign(n, false);
    tin.resize(n);
    tout.resize(n);
    up.resize(n);
    curTime = 0;

    BuildTimes(0, -1);

    cmps.resize(n);
    used.assign(n, false);
    cmpCount = 1;
    BuildCmps(0, -1, 0);

    goodCmp.assign(cmpCount, false);
    for (int v = 0; v < n; ++v) {
        int cv = cmps[v];
        for (const TEdge& e : g[v]) {
            int cu = cmps[e.To];
            if (cv == cu && e.IsSpecial) {
                goodCmp[cv] = true;
            }
        }
    }

    cg.resize(cmpCount);
    for (int v = 0; v < n; ++v) {
        int cv = cmps[v];
        for (const TEdge& e : g[v]) {
            int cu = cmps[e.To];

            if (cv != cu) {
                cg[cv].push_back(TEdge{cv, cu, e.IsSpecial});
            }
        }
    }

    reach.resize(cmpCount);
    used.assign(cmpCount, false);
    goodReach.resize(cmpCount);
    pr.resize(cmpCount);
    pr[cmps[start]] = -1;
    printf("%s\n", (IsResult(cmps[start], cmps[finish]) ? YES.c_str() : NO.c_str()));

    return 0;
}