#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

inline int GetFromMap(int pos, const unordered_map<int, int>& mp) {
    auto itr = mp.find(pos);
    if (itr == mp.end()) {
        return 0;
    } else {
        return (*itr).second;
    }
}

class TSegmentTree {
public:
    void Init(int n) {
        N = n;
        Map.resize(4 * n);
    }

    void Add(int pos, int val, int count) {
        Add(1, 0, N - 1, pos, val, count);
    }

    int Get(int pos, int val) {
        return Get(1, 0, N - 1, pos, val);
    }
private:
    int N;
    vector<unordered_map<int, int>> Map;

    void Add(int v, int tl, int tr, int pos, int val, int count) {
        if (pos <= tl) {
            Map[v][val] += count;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos > tm) {
                Add(2 * v + 1, tm + 1, tr, pos, val, count);
            } else {
                Add(2 * v, tl, tm, pos, val, count);
                Add(2 * v + 1, tm + 1, tr, pos, val, count);
            }
        }
    }

    int Get(int v, int tl, int tr, int pos, int val) const {
        int result = GetFromMap(val, Map[v]);
        if (tl != tr) {
            int tm = (tl + tr) >> 1;

            if (pos <= tm) {
                result += Get(2 * v, tl, tm, pos, val);
            } else {
                result += Get(2 * v + 1, tm + 1, tr, pos, val);
            }
        }
        return result;
    }
};

struct TQuery {
    int Type;
    int Time;
    int Val;
};

int main() {
    int n;
    scanf("%d", &n);

    vector<TQuery> qs(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &qs[i].Type, &qs[i].Time, &qs[i].Val);
    }

    {
        vector<int> times(n);
        for (int i = 0; i < n; ++i) {
            times[i] = qs[i].Time;
        }
        sort(times.begin(), times.end());

        unordered_map<int, int> g;
        for (int i = 0; i < n; ++i) {
            g[times[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            qs[i].Time = g[qs[i].Time];
        }
    }

    TSegmentTree st;
    st.Init(n);

    for (int i = 0; i < n; ++i) {
        if (qs[i].Type == 1) {
            st.Add(qs[i].Time, qs[i].Val, 1);
        } else if (qs[i].Type == 2) {
            st.Add(qs[i].Time, qs[i].Val, -1);
        } else {
            printf("%d\n", st.Get(qs[i].Time, qs[i].Val));
        }
    }

    return 0;
}