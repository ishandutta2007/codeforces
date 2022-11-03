#include <iostream>
#include <vector>

#include <cstdio>
using namespace std;

struct TSegmentTree {
    void Build(int n, long long mx) {
        Mx = mx;
        T.assign(4 * n, 0);
        N = n;
    }

    void Add(int v, int tl, int tr, int pos, long long val) {
        if (tl == tr) {
            T[v] = min(Mx, T[v] + val);
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                Add(2 * v, tl, tm, pos, val);
            } else {
                Add(2 * v + 1, tm + 1, tr, pos, val);
            }
            T[v] = T[2 * v] + T[2 * v + 1];
        }
    }

    void Add(int pos, long long val) {
        Add(1, 0, N - 1, pos, val);
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
                return Get(2 * v, tl, tm, l, tm) + Get(2 * v + 1, tm + 1, tr, tm + 1, r);
            }
        }
    }

    long long Get(int l, int r) {
        return Get(1, 0, N - 1, l, r);
    }

    long long Mx;
    int N;
    vector<long long> T;
};


int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;

    TSegmentTree ta, tb;

    ta.Build(n, a);
    tb.Build(n, b);

    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int d, x;
            cin >> d >> x;
            --d;
            ta.Add(d, x);
            tb.Add(d, x);
        } else {
            int d;
            cin >> d;
            --d;
            long long result = 0;
            if (d > 0) {
                result += tb.Get(0, d - 1);
            }
            if (d + k < n) {
                result += ta.Get(d + k, n - 1);
            }
            cout << result << '\n';
        }
    }
    cout.flush();

    return 0;
}