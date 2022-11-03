#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

class TSegmentTree {
public:
    void Init(const vector<int>& value) {
        N = value.size();
        Value.resize(4 * N);
        Build(1, 0, N - 1, value);
        AddValue.assign(4 * N, 0);
    }

    int Get(int pos) const {
        return Get(1, 0, N - 1, pos);
    }

    void Add(int l, int r, int val) {
        Add(1, 0, N - 1, l, r, val);
    }
private:
    int N;
    vector<int> Value;
    vector<int> AddValue;

    void Build(int v, int tl, int tr, const vector<int>& value) {
        if (tl == tr) {
            Value[v] = value[tl];
        } else {
            int tm = (tl + tr) >> 1;
            Build(2 * v, tl, tm, value);
            Build(2 * v + 1, tm + 1, tr, value);
        }
    }

    int Get(int v, int tl, int tr, int pos) const {
        if (tl == tr) {
            return Value[v] ^ AddValue[v];
        } else {
            int tm = (tl + tr) >> 1;

            if (pos <= tm) {
                return AddValue[v] ^ Get(2 * v, tl, tm, pos);
            } else {
                return AddValue[v] ^ Get(2 * v + 1, tm + 1, tr, pos);
            }
        }
    }

    void Add(int v, int tl, int tr, int l, int r, int val) {
        if (tl == l && tr == r) {
            AddValue[v] ^= val;
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
        }
    }
};

struct TQuery {
    int L;
    int R;
    int Id;
};

bool operator < (const TQuery& lhs, const TQuery& rhs) {
    return lhs.L < rhs.L;
}

int GetXor(const vector<int>& xs, int l, int r) {
    return l == 0 ? xs[r] : xs[r] ^ xs[l - 1];
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<int> xs(n);
    xs[0] = a[0];
    for (int i = 1; i < n; ++i) {
        xs[i] = xs[i - 1] ^ a[i];
    }

    vector<int> xus(n);
    set<int> used;
    for (int i = 0; i < n; ++i) {
        xus[i] = (i == 0 ? 0 : xus[i - 1]);

        if (used.find(a[i]) == used.end()) {
            used.insert(a[i]);
            xus[i] ^= a[i];
        }
    }

    TSegmentTree st;
    st.Init(xus);

    int q;
    scanf("%d", &q);
    vector<vector<TQuery>> qs(n);
    for (int i = 0; i < q; ++i) {
        TQuery cur;
        scanf("%d%d", &cur.L, &cur.R);
        --cur.L;
        --cur.R;
        cur.Id = i;
        qs[cur.L].push_back(cur);
    }

    vector<int> nextPos(n, -1);
    map<int, int> nextPosMap;
    for (int i = n - 1; i >= 0; --i) {
        auto itr = nextPosMap.find(a[i]);

        if (itr != nextPosMap.end()) {
            nextPos[i] = itr->second;
        }

        nextPosMap[a[i]] = i;
    }

    vector<int> result(q);
    for (int i = 0; i < n; ++i) {
        for (const TQuery& cur : qs[i]) {
            result[cur.Id] = st.Get(cur.R) ^ GetXor(xs, i, cur.R);
        }
        int nxPos = nextPos[i];
        int from = i + 1;
        int to;
        if (nxPos == -1) {
            to = n - 1;
        } else {
            to = nxPos - 1;
        }

        if (from <= to) {
            st.Add(from, to, a[i]);
        }
    }

    for (int i = 0; i < q; ++i) {
        printf("%d\n", result[i]);
    }

    return 0;
}