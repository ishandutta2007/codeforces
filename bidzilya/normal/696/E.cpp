#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const long long LONG_INF = 1e18;
const int INF = 1e9;

struct TGirl {
    long long Value;
    int VertId;
    int GirlId;
};

bool operator < (const TGirl& lhs, const TGirl& rhs) {
    return lhs.Value < rhs.Value || (lhs.Value == rhs.Value && lhs.VertId < rhs.VertId);
}

bool operator == (const TGirl& lhs, const TGirl& rhs) {
    return lhs.Value == rhs.Value && lhs.VertId == rhs.VertId && lhs.GirlId == rhs.GirlId;
}

bool operator != (const TGirl& lhs, const TGirl& rhs) {
    return !(lhs == rhs);
}

template<typename T>
T GetMin(const T& lhs, const T& rhs) {
    return lhs < rhs ? lhs : rhs;
}

TGirl GetWorstGirl() {
    return TGirl{LONG_INF, INF, -1};
}

class TSegmentTree {
public:
    void Init(int n) {
        N = n;
        Push.assign(4 * n, 0);
        FixedPush.assign(4 * n, 0);
        Value.assign(4 * n, GetWorstGirl());
    }

    TGirl Get(int l, int r) {
        return Get(1, 0, N - 1, l, r);
    }

    void Change(int pos, const TGirl& girl) {
        Change(1, 0, N - 1, pos, girl);
    }

    void Add(int l, int r, long long value) {
        Add(1, 0, N - 1, l, r, value);
    }
private:
    int N;
    vector<long long> Push;
    vector<long long> FixedPush;
    vector<TGirl> Value;

    TGirl Get(int v, int tl, int tr, int l, int r) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            return Value[v];
        } else {
            int tm = (tl + tr) >> 1;

            if (r <= tm) {
                return Get(2 * v, tl, tm, l, r);
            } else if (l > tm) {
                return Get(2 * v + 1, tm + 1, tr, l, r);
            } else {
                return GetMin(Get(2 * v, tl, tm, l, tm), Get(2 * v + 1, tm + 1, tr, tm + 1, r));
            }
        }
    }

    void Change(int v, int tl, int tr, int pos, const TGirl& girl) {
        DoPush(v, tl, tr);
        if (tl == tr) {
            Value[v] = girl;
            if (girl != GetWorstGirl()) {
                Value[v].Value += FixedPush[v];
            }
        } else {
            int tm = (tl + tr) >> 1;

            if (pos <= tm) {
                Change(2 * v, tl, tm, pos, girl);
            } else {
                Change(2 * v + 1, tm + 1, tr, pos, girl);
            }

            Value[v] = GetMin(Value[2 * v], Value[2 * v + 1]);
        }
    }

    void Add(int v, int tl, int tr, int l, int r, long long value) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            Push[v] += value;
            FixedPush[v] += value;
            if (Value[v] != GetWorstGirl()) {
                Value[v].Value += value;
            }
        } else {
            int tm = (tl + tr) >> 1;

            if (r <= tm) {
                Add(2 * v, tl, tm, l, r, value);
            } else if (l > tm) {
                Add(2 * v + 1, tm + 1, tr, l, r, value);
            } else {
                Add(2 * v, tl, tm, l, tm, value);
                Add(2 * v + 1, tm + 1, tr, tm + 1, r, value);
            }
            Value[v] = GetMin(Value[2 * v], Value[2 * v + 1]);
        }
    }

    void DoPush(int v, int tl, int tr) {
        if (Push[v] != 0) {
            if (tl != tr) {
                if (Value[2 * v] != GetWorstGirl()) {
                    Value[2 * v].Value += Push[v];
                }
                if (Value[2 * v + 1] != GetWorstGirl()) {
                    Value[2 * v + 1].Value += Push[v];
                }
                Push[2 * v] += Push[v];
                Push[2 * v + 1] += Push[v];
                FixedPush[2 * v] += Push[v];
                FixedPush[2 * v + 1] += Push[v];
            }
            Push[v] = 0;
        }
    }
};

class TFenwickTree {
public:
    void Init(int n) {
        N = n;
        Sum.assign(n, 0);
    }

    void Add(int l, int r, long long value) {
        Add(l, value);
        if (r + 1 != N) {
            Add(r + 1, -value);
        }
    }

    long long Get(int pos) const {
        long long result = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            result += Sum[pos];
        }
        return result;
    }
private:
    int N;
    vector<long long> Sum;

    void Add(int pos, long long value) {
        for (; pos < N; pos |= (pos + 1)) {
            Sum[pos] += value;
        }
    }
};

int n;
vector<vector<int>> g;

vector<vector<TGirl>> girlIds;

const int MAX_LOG = 20;

vector<int> tin;
vector<int> tout;
int curTime;
vector<vector<int>> up;
vector<int> sz;

vector<vector<int>> paths;

vector<int> pathId;
vector<int> innerPathId;

void BuildTimes(int v, int pr) {
    up[v].resize(MAX_LOG);
    if (pr == -1) {
        for (int i = 0; i < MAX_LOG; ++i) {
            up[v][i] = v;
        }
    } else {
        up[v][0] = pr;
        for (int i = 1; i < MAX_LOG; ++i) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
    }
    sz[v] = 1;
    tin[v] = curTime++;
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }
        BuildTimes(u, v);
        sz[v] += sz[u];
    }
    tout[v] = curTime++;
}

bool IsParent(int par, int vert) {
    return tin[par] <= tin[vert] && tout[par] >= tout[vert];
}

int GetLca(int v1, int v2) {
    if (IsParent(v1, v2)) {
        return v1;
    }
    if (IsParent(v2, v1)) {
        return v2;
    }
    for (int i = MAX_LOG - 1; i >= 0; --i) {
        if (!IsParent(up[v2][i], v1)) {
            v2 = up[v2][i];
        }
    }
    return up[v2][0];
}

void BuildPaths(int v, int pr, int curPathId) {
    if (curPathId == -1) {
        paths.push_back(vector<int>());
        curPathId = paths.size() - 1;
    }
    pathId[v] = curPathId;
    paths[pathId[v]].push_back(v);
    innerPathId[v] = paths[pathId[v]].size() - 1;
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }
        if (2 * sz[u] > sz[v]) {
            BuildPaths(u, v, curPathId);
        } else {
            BuildPaths(u, v, -1);
        }
    }
}

int pathCount;

vector<int> girlPtrs;

TFenwickTree ft;

vector<TSegmentTree> sts;

TGirl GetMinGirlOnDecompositionPath(int d, int u) {
    int curPathId = pathId[d];

    TGirl result = sts[curPathId].Get(innerPathId[u], innerPathId[d]);

    long long addValue = ft.Get(tin[paths[curPathId][0]]);

    if (result != GetWorstGirl()) {
        result.Value += addValue;
    }

    return result;
}

TGirl GetMinGirlOnPath(int d, int u) {
    TGirl result = GetWorstGirl();

    while (pathId[d] != pathId[u]) {
        int ud = paths[pathId[d]][0];

        result = GetMin(result, GetMinGirlOnDecompositionPath(d, ud));

        d = up[ud][0];
    }

    result = GetMin(result, GetMinGirlOnDecompositionPath(d, u));

    return result;
}

TGirl GetMinGirl(int v1, int v2) {
    int g = GetLca(v1, v2);
    if (g != v1 && g != v2) {
        return GetMin(GetMinGirlOnPath(v1, g), GetMinGirlOnPath(v2, g));
    } else if (g == v1) {
        return GetMinGirlOnPath(v2, v1);
    } else {
        return GetMinGirlOnPath(v1, v2);
    }
}

void DeleteGirl(const TGirl& g) {
    int curVertId = g.VertId;
    int curPathId = pathId[curVertId];
    int curInnerPathId = innerPathId[curVertId];

    ++girlPtrs[curVertId];

    TGirl newGirl =
        girlPtrs[curVertId] >= (int) girlIds[curVertId].size()
        ? GetWorstGirl()
        : girlIds[curVertId][girlPtrs[curVertId]];

    sts[curPathId].Change(curInnerPathId, newGirl);
}

int main() {
    // freopen("input2.txt", "r", stdin);

    int m, q;
    scanf("%d%d%d", &n, &m, &q);

    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    girlIds.resize(n);
    for (int i = 0; i < m; ++i) {
        int ci;
        scanf("%d", &ci);
        --ci;
        girlIds[ci].push_back(TGirl{i, ci, i});
    }

    tin.resize(n);
    tout.resize(n);
    up.resize(n);
    curTime = 0;
    sz.resize(n);
    BuildTimes(0, -1);

    pathId.resize(n);
    innerPathId.resize(n);
    BuildPaths(0, -1, -1);
    pathCount = paths.size();

    ft.Init(curTime);

    sts.resize(pathCount);
    for (int pathId = 0; pathId < pathCount; ++pathId) {
        sts[pathId].Init(paths[pathId].size());

        for (int i = 0; i < (int) paths[pathId].size(); ++i) {
            int v = paths[pathId][i];
            if (!girlIds[v].empty()) {
                sts[pathId].Change(i, girlIds[v][0]);
            }
        }
    }

    girlPtrs.assign(n, 0);

    for (; q; --q) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int v1, v2, k;
            scanf("%d%d%d", &v1, &v2, &k);
            --v1;
            --v2;

            vector<TGirl> result;
            for (int i = 0; i < k; ++i) {
                TGirl mn = GetMinGirl(v1, v2);

                if (mn == GetWorstGirl()) {
                    break;
                }

                result.push_back(mn);

                DeleteGirl(mn);
            }

            printf("%d", (int) result.size());
            for (const TGirl& g : result) {
                printf(" %d", g.GirlId + 1);
            }
            printf("\n");
        } else {
            int v, k;
            scanf("%d%d", &v, &k);
            --v;

            ft.Add(tin[v], tout[v], k);

            int curPathId = pathId[v];
            int curInnerPathId = innerPathId[v];

            if (curInnerPathId != 0) {
                sts[curPathId].Add(curInnerPathId, paths[curPathId].size() - 1, k);
            }
        }
    }

    return 0;
}