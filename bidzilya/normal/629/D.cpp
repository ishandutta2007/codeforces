#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>

#include <cmath>
using namespace std;

const double PI = acos(-1.0);

struct TSegmentTree {
    void Init(int n) {
        N = n;
        T.assign(4 * n, 0);
    }

    long long Get(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return T[v];
        } else {
            int tm = (tl + tr) >> 1;
            if (r <= tm) {
                return Get(2 * v, tl, tm, l, r);
            } else if (l > tm) {
                return Get(2 * v + 1, tm + 1, tr, l, r);
            } else {
                return max(Get(2 * v, tl, tm, l, tm), Get(2 * v + 1, tm + 1, tr, tm + 1, r));
            }
        }
    }

    long long Get(int l, int r) {
        return Get(1, 0, N - 1, l, r);
    }

    void Set(int v, int tl, int tr, int pos, long long val) {
        if (tl == tr) {
            T[v] = max(T[v], val);
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                Set(2 * v, tl, tm, pos, val);
            } else {
                Set(2 * v + 1, tm + 1, tr, pos, val);
            }
            T[v] = max(T[2 * v], T[2 * v + 1]);
        }
    }

    void Set(int pos, long long val) {
        Set(1, 0, N - 1, pos, val);
    }

    int N;
    vector<long long> T;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> vals(n);
    vector<long long> buf(n);
    for (int i = 0; i < n; ++i) {
        int r, h;
        cin >> r >> h;
        vals[i] = 1LL * r * r * h;
        buf[i] = vals[i];
    }

    sort(buf.begin(), buf.end());
    buf.resize(unique(buf.begin(), buf.end()) - buf.begin());
    map<long long, int> mp;
    for (int i = 0; i < (int) buf.size(); ++i) {
        mp[buf[i]] = i;
    }

    vector<int> mappedVals(n);
    for (int i = 0; i < n; ++i) {
        mappedVals[i] = mp[vals[i]];
    }

    TSegmentTree seg;
    seg.Init(buf.size());
    for (int i = 0; i < n; ++i) {
        long long val = vals[i] + (mappedVals[i] > 0 ? seg.Get(0, mappedVals[i] - 1) : 0);
        seg.Set(mappedVals[i], val);
    }

    cout << fixed << setprecision(15);
    cout << seg.Get(0, buf.size() - 1) * PI << endl;

    return 0;
}