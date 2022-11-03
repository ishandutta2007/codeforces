#include <iostream>
#include <vector>
using namespace std;


void Dfs(int v, int pr, const vector<vector<int>>& g, vector<int>& result) {
    result.push_back(v);
    for (int u : g[v]) {
        if (u == pr) {
            continue;
        }
        Dfs(u, v, g, result);
    }
    result.push_back(v);
}

vector<int> GetEulerTour(const vector<vector<int>>& g) {
    vector<int> result;
    Dfs(0, -1, g, result);
    return result;
}

struct TSegmentTree {
    void Init(int n) {
        N = n;
        T.assign(4 * N, 0);
        P.assign(4 * N, 0);
    }

    void DoPush(int v, int tl, int tr) {
        if (P[v] != 0) {
            if (tl != tr) {
                P[2 * v] = P[2 * v + 1] = P[v];
                T[2 * v] = T[2 * v + 1] = P[v];
            }
            P[v] = 0;
        }
    }

    void Push(int v, int tl, int tr, int l, int r, long long val) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            P[v] = val;
            T[v] = val;
        } else {
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                Push(2 * v, tl, tm, l, r, val);
            } else if (l > tm) {
                Push(2 * v + 1, tm + 1, tr, l, r, val);
            } else {
                Push(2 * v, tl, tm, l, tm, val);
                Push(2 * v + 1, tm + 1, tr, tm + 1, r, val);
            }
            T[v] = T[2 * v] | T[2 * v + 1];
        }
    }

    void Push(int l, int r, long long val) {
        Push(1, 0, N - 1, l, r, val);
    }

    int GetBitCount(long long mask) {
        int result = 0;
        while (mask > 0) {
            result += (mask & 1);
            mask >>= 1;
        }
        return result;
    }

    long long Get(int v, int tl, int tr, int l, int r) {
        DoPush(v, tl, tr);
        if (tl == l && tr == r) {
            return T[v];
        } else {
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                return Get(2 * v, tl, tm, l, r);
            } else if (l > tm) {
                return Get(2 * v + 1, tm + 1, tr, l, r);
            } else {
                return (Get(2 * v, tl, tm, l, tm) | Get(2 * v + 1, tm + 1, tr, tm + 1, r));
            }
        }
    }

    long long Get(int l, int r) {
        return GetBitCount(Get(1, 0, N - 1, l, r));
    }

    int N;
    vector<long long> T;
    vector<long long> P;
};

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        --v1;
        --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    vector<int> tour = GetEulerTour(g);

    TSegmentTree st;
    st.Init(tour.size());

    vector<int> start, finish;
    start.assign(n, tour.size());
    finish.assign(n, -1);
    for (int i = 0; i < (int) tour.size(); ++i) {
        start[tour[i]] = min(start[tour[i]], i);
        finish[tour[i]] = max(finish[tour[i]], i);
    }

    for (int i = 0; i < (int) tour.size(); ++i) {
        int v = tour[i];
        if (start[v] == i) {
            st.Push(start[v], finish[v], (1LL << (c[v] - 1)));
        }
    }

    for (int i = 0; i < m; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int v, c;
            cin >> v >> c;
            --v;
            long long mask = (1LL << (c - 1));
            st.Push(start[v], finish[v], mask);
        } else {
            int v;
            cin >> v;
            --v;
            cout << st.Get(start[v], finish[v]) << '\n';
        }
    }
    cout.flush();

    return 0;
}