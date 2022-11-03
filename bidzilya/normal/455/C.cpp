#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

#include <cassert>
using namespace std;

class TBox {
public:
    TBox(int k) {
        Values.clear();
        K = k;
    }

    void Add(const pair<int, int>& value) {
        Values.push_back(value);
        if (Values.size() > K) {
            sort(Values.begin(), Values.end(), greater<pair<int, int>>());
            Values.resize(K);
        }
    }

    int Get(int except) const {
        for (int i = 0; i < (int) Values.size(); ++i) {
            if (Values[i].second != except) {
                return Values[i].first;
            }
        }
        assert(false);
    }

    int Size() const {
        return Values.size();
    }

private:
    vector<pair<int, int>> Values;
    int K;
};

const int INF = 1e9;

class TDsu {
public:
    TDsu(int n, const vector<int>& mn, const vector<int>& mx) {
        Rank.assign(n, 0);
        Parent.resize(n);
        for (int i = 0; i < n; ++i) {
            Parent[i] = i;
        }
        Min = mn;
        Max = mx;
    }

    int GetParent(int v) {
        if (Parent[v] == v) {
            return v;
        }
        return Parent[v] = GetParent(Parent[v]);
    }

    bool Unite(int v1, int v2) {
        v1 = GetParent(v1);
        v2 = GetParent(v2);

        if (v1 == v2) {
            return false;
        }

        if (Rank[v1] < Rank[v2]) {
            swap(v1, v2);
        }

        Parent[v2] = v1;
        if (Rank[v1] == Rank[v2]) {
            ++Rank[v1];
        }

        Max[v1] = max(max(Max[v1], Max[v2]), Min[v1] + Min[v2] + 1);
        Min[v1] = min(max(Min[v1], 1 + Min[v2]), max(Min[v2], 1 + Min[v1]));

        return true;
    }

    int GetMax(int v) {
        v = GetParent(v);
        return Max[v];
    }

private:
    vector<int> Rank;
    vector<int> Parent;
    vector<int> Min;
    vector<int> Max;
};

int n;
vector<vector<int>> g;
vector<int> downDist;
vector<int> upDist;

vector<int> cmp;
vector<vector<int>> cmps;

void DfsDown(int v, int pr) {
    cmp[v] = cmps.size() - 1;
    cmps[cmp[v]].push_back(v);
    downDist[v] = 0;
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }
        DfsDown(u, v);
        downDist[v] = max(downDist[v], downDist[u] + 1);
    }
}

void DfsUp(int v, int pr, int curUpDist) {
    upDist[v] = curUpDist;
    TBox box(2);
    box.Add(make_pair(curUpDist, -1));
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }
        int dist = downDist[u] + 1;
        box.Add(make_pair(dist, u));
    }
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }
        DfsUp(u, v, box.Get(u) + 1);
    }
}

int main() {
    int m, q;
    scanf("%d%d%d", &n, &m, &q);

    g.resize(n);
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    downDist.resize(n);
    cmp.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (cmp[i] == -1) {
            cmps.push_back(vector<int>());
            DfsDown(i, -1);
        }
    }

    const int cmpCount = cmps.size();

    upDist.resize(n);
    for (int c = 0; c < cmpCount; ++c) {
        DfsUp(cmps[c][0], -1, 0);
    }

    vector<int> minDist(cmpCount, INF);
    vector<int> maxDist(cmpCount, 0);
    for (int i = 0; i < n; ++i) {
        const int dist = max(upDist[i], downDist[i]);
        minDist[cmp[i]] = min(minDist[cmp[i]], dist);
        maxDist[cmp[i]] = max(maxDist[cmp[i]], dist);
    }

    TDsu dsu(cmpCount, minDist, maxDist);

    for (int i = 0; i < q; ++i) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int v;
            scanf("%d", &v);
            --v;
            printf("%d\n", dsu.GetMax(cmp[v]));
        } else {
            int x, y;
            scanf("%d%d", &x, &y);
            --x;
            --y;
            dsu.Unite(cmp[x], cmp[y]);
        }
    }

    return 0;
}