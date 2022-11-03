#include <vector>
#include <iostream>
#include <set>
#include <string>
using namespace std;

struct TBox {
    int From;
    int To;
    int Id;
    int Cost;
};

vector<vector<int>> g;
vector<int> tin;
vector<int> tout;
int timer;

void Dfs(int v, int pr) {
    tin[v] = timer;
    tout[v] = timer;
    ++timer;
    for (int u : g[v]) {
        if (u != pr) {
            Dfs(u, v);
            tout[v] = max(tout[v], tout[u]);
        }
    }
}

struct TNumber {
    long long Value;
    long long InfCount;
};

TNumber GetNumber(long long value) {
    return TNumber{value, 0};
}

const TNumber INF = TNumber{0, 1};
const TNumber ZERO = TNumber{0, 0};

TNumber operator + (const TNumber& lhs, const TNumber& rhs) {
    return TNumber{lhs.Value + rhs.Value, lhs.InfCount + rhs.InfCount};
}

TNumber operator - (TNumber& number) {
    return TNumber{-number.Value, -number.InfCount};
}

bool IsLess(const TNumber& lhs, const TNumber& rhs) {
    return lhs.InfCount < rhs.InfCount || (lhs.InfCount == rhs.InfCount && lhs.Value < rhs.Value);
}

TNumber GetMin(const TNumber& lhs, const TNumber& rhs) {
    return (IsLess(lhs, rhs) ? lhs : rhs);
}

bool operator != (const TNumber& lhs, const TNumber& rhs) {
    return lhs.InfCount != rhs.InfCount || lhs.Value != rhs.Value;
}

class TSegmentTree {
public:
    void Init(int n) {
        N = n;
        Sum.assign(4 * n, ZERO);
        Val.assign(4 * n, INF);
        Min.assign(4 * n, INF);
    }

    void Update(int pos, const TNumber& val) {
        Update(1, 0, N - 1, pos, val);
    }

    void Add(int l, int r, const TNumber& val) {
        Add(1, 0, N - 1, l, r, val);
    }

    TNumber Get(int l, int r) {
        return Get(1, 0, N - 1, l, r);
    }
private:
    vector<TNumber> Sum, Val, Min;
    int N;

    void Update(int v, int tl, int tr, int pos, const TNumber& val) {
        DoPush(v, tl, tr);
        if (tl == tr) {
            Val[v] = Min[v] = val;
            Min[v] = Min[v] + Sum[v];
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                Update(2 * v, tl, tm, pos, val);
            } else {
                Update(2 * v + 1, tm + 1, tr, pos, val);
            }
            Min[v] = GetMin(Min[2 * v], Min[2 * v + 1]) + Sum[v];
        }
    }

    void Add(int v, int tl, int tr, int l, int r, const TNumber& val) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            Sum[v] = Sum[v] + val;
            Min[v] = Min[v] + val;
        } else {
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                Add(2 * v, tl, tm, l, r, val);
            } else if (l > tm) {
                Add(2 * v + 1, tm + 1, tr, l, r, val);
            } else {
                Add(2 * v, tl, tm, l, tm, val);
                Add(2 * v + 1, tm + 1, tr, tm + 1, r, val);
            }
            Min[v] = GetMin(Min[2 * v], Min[2 * v + 1]) + Sum[v];
        }
    }

    TNumber Get(int v, int tl, int tr, int l, int r) {
        DoPush(v, tl, tr);
        if (l == tl && r == tr) {
            return Min[v];
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

    void DoPush(int v, int tl, int tr) {
        if (tl != tr) {
            if (Sum[v] != ZERO) {
                Val[2 * v] = Val[2 * v] + Sum[v];
                Val[2 * v + 1] = Val[2 * v + 1] + Sum[v];

                Min[2 * v] = Min[2 * v] + Sum[v];
                Min[2 * v + 1] = Min[2 * v + 1] + Sum[v];

                Sum[2 * v] = Sum[2 * v] + Sum[v];
                Sum[2 * v + 1] = Sum[2 * v + 1] + Sum[v];

                Sum[v] = ZERO;
            }
        }
    }
};

vector<TBox> boxes;

vector<TNumber> dp;
vector<TNumber> dpSum;
vector<vector<int>> boxStart;

vector<set<pair<long long, int>>> addVals;

TSegmentTree segTree;

void CalcResults(int v, int pr) {
    for (int id : boxStart[v]) {
        int t = tin[boxes[id].To];
        long long c = boxes[id].Cost;
        addVals[t].insert(make_pair(c, id));
        segTree.Update(t, GetNumber((*addVals[t].begin()).first));
    }

    dpSum[v] = ZERO;
    for (int u : g[v]) {
        if (tin[u] > tin[v]) {
            CalcResults(u, v);
            dpSum[v] = dpSum[v] + dp[u];
        }
    }

    for (int id : boxStart[v]) {
        int t = tin[boxes[id].To];
        long long c = boxes[id].Cost;
        addVals[t].erase(make_pair(c, id));
        if (addVals[t].empty()) {
            segTree.Update(t, INF);
        } else {
            segTree.Update(t, GetNumber((*addVals[t].begin()).first));
        }
    }

    if (pr != -1) {
        segTree.Add(tin[v], tout[v], dpSum[v]);
        for (int u : g[v]) {
            if (tin[u] > tin[v]) {
                segTree.Add(tin[u], tout[u], -dp[u]);
            }
        }
        dp[v] = segTree.Get(tin[v], tout[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    timer = 0;
    tin.resize(n);
    tout.resize(n);
    Dfs(0, -1);

    boxStart.resize(n);

    boxes.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> boxes[i].To >> boxes[i].From >> boxes[i].Cost;
        --boxes[i].To;
        --boxes[i].From;
        boxes[i].Id = i;
        if (boxes[i].From != boxes[i].To) {
            boxStart[boxes[i].From].push_back(i);
        }
    }

    segTree.Init(n);
    dp.assign(n, INF);
    dpSum.resize(n);
    addVals.resize(n);
    CalcResults(0, -1);

    if (dpSum[0].InfCount > 0) {
        cout << -1 << endl;
    } else {
        cout << dpSum[0].Value << endl;
    }

    return 0;
}