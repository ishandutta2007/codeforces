#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TFenwickTree {
public:
    void Init(int n) {
        Values.assign(n, 0);
    }

    void Add(int pos, int val) {
        for (; pos < (int) Values.size(); pos |= (pos + 1)) {
            Values[pos] += val;
        }
    }

    void Add(int l, int r, int val) {
        Add(l, val);
        if (r != (int) Values.size() - 1) {
            Add(r + 1, -val);
        }
    }

    int Get(int pos) {
        int result = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
            result += Values[pos];
        }
        return result;
    }

    int Get(int l, int r) {
        if (l == 0) {
            return Get(r);
        } else {
            return Get(r) - Get(l - 1);
        }
    }

private:
    vector<int> Values;
};

int n, k;

inline int GetNextPos(int pos) {
    pos += k;
    if (pos >= n) {
        pos -= n;
    }
    return pos;
}

TFenwickTree ss;
TFenwickTree ff;

void Solve() {
    ss.Init(n);
    ff.Init(n);

    long long sum = 1;
    for (int i = 0, pos = 0; i < n; ++i) {
        int l = pos;
        int r = GetNextPos(pos);

        if (l > r) {
            swap(l, r);
        }

        sum += 1;

        {
            int cl = l + 1;
            int cr = r - 1;
            cr = min(cr, n - 1 - k);
            cl = max(cl, r - k + 1);
            if (cl <= cr) {
                sum += ss.Get(cl, cr);
            }

            cl = l + 1;
            cr = r - 1;
            cl = max(cl, n - k);
            cr = min(cr, l - k + n - 1);
            if (cl <= cr) {
                sum += ss.Get(cl, cr);
            }
        }

        {
            int cl = l + 1;
            int cr = r - 1;
            cr = min(cr, k - 1);
            cl = max(cl, r - n + k + 1);
            if (cl <= cr) {
                sum += ff.Get(cl, cr);
            }

            cl = l + 1;
            cr = r - 1;
            cl = max(cl, k);
            cr = min(cr, l + k - 1);
            if (cl <= cr) {
                sum += ff.Get(cl, cr);
            }
        }

        ss.Add(pos, 1);
        ff.Add(GetNextPos(pos), 1);

        pos = GetNextPos(pos);

        cout << sum << " ";
    }
    cout << endl;
}

bool Read() {
    if (!(cin >> n >> k)) {
        return false;
    }
    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (Read()) {
        Solve();
    }

    return 0;
}