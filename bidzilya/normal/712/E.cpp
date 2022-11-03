#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

using TBox = pair<double, double>;

TBox Merge(const TBox& lhs, const TBox& rhs) {
    return {
        lhs.first * rhs.first / (1.0 + (rhs.first - 1.0) * lhs.second),
        rhs.second + (1.0 - rhs.second) * lhs.second * rhs.first / (1.0 + lhs.second * (rhs.first - 1.0))
    };
}

class TSegTree {
public:
    void Init(const vector<double>& values) {
        N = values.size();
        Values.resize(4 * N);
        Init(1, 0, N - 1, values);
    }

    double Get(int l, int r) {
        return Get(1, 0, N - 1, l, r).first;
    }

    void Set(int pos, double value) {
        Set(1, 0, N - 1, pos, value);
    }

private:
    int N;
    vector<TBox> Values;

    void Init(int v, int tl, int tr, const vector<double>& values) {
        if (tl == tr) {
            Values[v].first = Values[v].second = values[tl];
        } else {
            int tm = (tl + tr) >> 1;

            Init(2 * v, tl, tm, values);
            Init(2 * v + 1, tm + 1, tr, values);

            Values[v] = Merge(Values[2 * v], Values[2 * v + 1]);
        }
    }

    TBox Get(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return Values[v];
        } else {
            int tm = (tl + tr) >> 1;

            if (r <= tm) {
                return Get(2 * v, tl, tm, l, r);
            } else if (l > tm) {
                return Get(2 * v + 1, tm + 1, tr, l, r);
            } else {
                return Merge(
                    Get(2 * v, tl, tm, l, tm),
                    Get(2 * v + 1, tm + 1, tr, tm + 1, r)
                );
            }
        }
    }

    void Set(int v, int tl, int tr, int pos, double value) {
        if (tl == tr) {
            Values[v].first = Values[v].second = value;
        } else {
            int tm = (tl + tr) >> 1;

            if (pos <= tm) {
                Set(2 * v, tl, tm, pos, value);
            } else {
                Set(2 * v + 1, tm + 1, tr, pos, value);
            }

            Values[v] = Merge(Values[2 * v], Values[2 * v + 1]);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<double> values(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        values[i] = 1.0 * a / b;
    }

    TSegTree st;
    st.Init(values);

    cout << fixed << setprecision(15);
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int pos, a, b;
            cin >> pos >> a >> b;
            --pos;

            st.Set(pos, 1.0 * a / b);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            --r;

            cout << st.Get(l, r) << '\n';
        }
    }
    cout.flush();

    return 0;
}