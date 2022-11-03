#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cassert>
using namespace std;

class TSegmentTree {
public:
    void Init(int n) {
        N = n;
        Sum.assign(4 * N, 0);
        MaxPrefixSum.assign(4 * N, 0);
    }

    void Set(int pos, int value) {
        Set(1, 0, N - 1, pos, value);
    }

    int GetPos() {
        if (MaxPrefixSum[1] <= 0) {
            return -1;
        } else {
            return GetPos(1, 0, N - 1, 0);
        }
    }

private:
    int N;
    vector<int> Sum;
    vector<int> MaxPrefixSum;

    void Set(int v, int tl, int tr, int pos, int value) {
        if (tl == tr) {
            Sum[v] = value;
            MaxPrefixSum[v] = max(0, value);
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                Set(2 * v, tl, tm, pos, value);
            } else {
                Set(2 * v + 1, tm + 1, tr, pos, value);
            }
            Sum[v] = Sum[2 * v] + Sum[2 * v + 1];
            MaxPrefixSum[v] = max(
                MaxPrefixSum[2 * v + 1],
                MaxPrefixSum[2 * v] + Sum[2 * v + 1]);
        }
    }

    int GetPos(int v, int tl, int tr, int add) {
        if (tl == tr) {
            return tl;
        } else {
            int tm = (tl + tr) >> 1;
            if (MaxPrefixSum[2 * v + 1] + add > 0) {
                return GetPos(2 * v + 1, tm + 1, tr, add);
            } else {
                return GetPos(2 * v, tl, tm, add + Sum[2 * v + 1]);
            }
        }
    }
};

const int PUSH = 1;
const int POP = 0;

inline int GetValue(int tp) {
    if (tp == PUSH) {
        return 1;
    } else if (tp == POP) {
        return -1;
    } else {
        assert(false);
    }
}

int m;
vector<int> values, poses, types, a;

TSegmentTree st;

void Solve() {
    st.Init(m);
    a.resize(m);
    for (int i = 0; i < m; ++i) {
        st.Set(poses[i], GetValue(types[i]));

        if (types[i] == PUSH) {
            a[poses[i]] = values[i];
        }

        int pos = st.GetPos();
        if (pos != -1) {
            pos = a[pos];
        }

        cout << pos << '\n';
    }
    cout.flush();
}

bool Read() {
    if (!(cin >> m)) {
        return false;
    }
    values.resize(m);
    poses.resize(m);
    types.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> poses[i] >> types[i];
        --poses[i];
        if (types[i] == PUSH) {
            cin >> values[i];
        }
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}