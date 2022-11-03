#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <utility>
#include <set>
using namespace std;

struct TFrog {
    int Pos;
    long long Power;
    int Index;
    int Count;
};

int n, m, k;
vector<TFrog> a;
vector<pair<int, int>> b;
vector<int> coords;
vector<int> frogIndex;

const long long INF = 1e18;

struct TSegmentTree {
    void Build(int v, int tl, int tr) {
        if (tl == tr) {
            Val[v] = -INF;
            int index = frogIndex[tl];
            if (index != -1) {
                Val[v] = coords[a[index].Pos] + a[index].Power;
            }
        } else {
            int tm = (tl + tr) >> 1;
            Build(2 * v, tl, tm);
            Build(2 * v + 1, tm + 1, tr);
            Val[v] = max(Val[2 * v], Val[2 * v + 1]);
        }
    }

    void Build() {
        Val.resize(4 * k);
        Build(1, 0, k - 1);
    }

    int Get(int v, int tl, int tr, int r, long long val) {
        if (Val[v] < val) {
            return -1;
        }
        if (tl == tr) {
            return frogIndex[tl];
        } else {
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                return Get(2 * v, tl, tm, r, val);
            }
            if (Val[2 * v] >= val) {
                return Get(2 * v, tl, tm, tm, val);
            } else {
                return Get(2 * v + 1, tm + 1, tr, r, val);
            }
        }
    }

    int Get(int r, long long val) {
        return Get(1, 0, k - 1, r, val);
    }

    void Add(int v, int tl, int tr, int pos, long long val) {
        if (tl == tr) {
            Val[v] += val;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                Add(2 * v, tl, tm, pos, val);
            } else {
                Add(2 * v + 1, tm + 1, tr, pos, val);
            }
            Val[v] = max(Val[2 * v], Val[2 * v + 1]);
        }
    }

    void Add(int pos, long long val) {
        Add(1, 0, k - 1, pos, val);
    }

    vector<long long> Val;
};

TSegmentTree st;

set<pair<long long, int>> remains;

void Add(int frogIndex, long long value) {
    a[frogIndex].Power += value;
    ++a[frogIndex].Count;
    st.Add(a[frogIndex].Pos, value);

    if (!remains.empty()) {
        auto itr = remains.upper_bound(make_pair(a[frogIndex].Power + coords[a[frogIndex].Pos], m));

        if (itr != remains.begin()) {
            --itr;
            long long pos = itr->first;
            int index = itr->second;
            if (coords[a[frogIndex].Pos] <= pos) {
                remains.erase(itr);
                Add(frogIndex, b[index].second);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].Pos >> a[i].Power;
        a[i].Index = i;
        a[i].Count = 0;
    }

    b.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i].first >> b[i].second;
    }

    coords.reserve(n + m);
    for (int i = 0; i < n; ++i) {
        coords.push_back(a[i].Pos);
    }
    for (int i = 0; i < m; ++i) {
        coords.push_back(b[i].first);
    }

    {
        sort(coords.begin(), coords.end());
        coords.resize(unique(coords.begin(), coords.end()) - coords.begin());
        unordered_map<int, int> mp;
        for (int i = 0; i < (int) coords.size(); ++i) {
            mp[coords[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            a[i].Pos = mp[a[i].Pos];
        }
        for (int i = 0; i < m; ++i) {
            b[i].first = mp[b[i].first];
        }
    }

    k = coords.size();

    frogIndex.assign(k, -1);
    for (int i = 0; i < n; ++i) {
        frogIndex[a[i].Pos] = i;
    }

    st.Build();

    for (int i = 0; i < m; ++i) {
        int frogIndex = st.Get(b[i].first, coords[b[i].first]);

        if (frogIndex == -1) {
            remains.insert(make_pair(coords[b[i].first], i));
            continue;
        }

        Add(frogIndex, b[i].second);
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i].Count << " " << a[i].Power << '\n';
    }
    cout.flush();

    return 0;
}