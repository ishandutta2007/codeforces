#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <cstdio>
using namespace std;

const int MAX_LOG = 20;
const int MAX_N = 1e6 + 1;

vector<int> logs;

void PrecalcLogs() {
    logs.resize(MAX_N);
    logs[1] = 0;
    for (int i = 2; i < MAX_N; ++i) {
        logs[i] = logs[i - 1];
        if ((1 << (logs[i] + 1)) <= i) {
            ++logs[i];
        }
    }
}

using TFunc = bool (*)(int, int);

struct TTable {
    TTable(const vector<int>& a, TFunc cmp) {
        Cmp = cmp;
        int n = a.size();
        table.resize(n, vector<int>(MAX_LOG));
        for (int i = 0; i < n; ++i) {
            table[i][0] = a[i];
        }
        for (int i = 1; i < MAX_LOG; ++i) {
            for (int j = 0; j < n; ++j) {
                table[j][i] = table[j][i - 1];
                int nxt = j + (1 << (i - 1));
                if (nxt < n) {
                    if (cmp(table[nxt][i - 1], table[j][i])) {
                        table[j][i] = table[nxt][i - 1];
                    }
                }
            }
        }
    }

    int Get(int l, int r) const {
        int logLen = logs[r - l + 1];
        int valLeft = table[l][logLen];
        int valRight = table[r - (1 << logLen) + 1][logLen];
        if (Cmp(valLeft, valRight)) {
            return valLeft;
        } else {
            return valRight;
        }
    }

    TFunc Cmp;
    vector<vector<int>> table;
};

bool CmpMin(int l, int r) {
    if (l <= r) {
        return true;
    } else {
        return false;
    }
}

bool CmpMax(int l, int r) {
    if (l >= r) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    PrecalcLogs();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i] *= 100;
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    TTable vTable(v, CmpMax);
    TTable cTable(c, CmpMin);

    vector<int> val(n);
    for (int i = 0; i < n; ++i) {
        if (v[i] >= c[i]) {
            val[i] = c[i];
            continue;
        }
        int l = i;
        int r = n - 1;
        int result = l;
        while (l <= r) {
            int m = (l + r) >> 1;

            if (vTable.Get(i, m) <= cTable.Get(i, m)) {
                result = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        val[i] = vTable.Get(i, result);
        if (result + 1 < n) {
            val[i] = max(val[i], cTable.Get(i, result + 1));
        }
    }

    sort(val.begin(), val.end(), greater<int>());

    vector<double> probs(n, 0.0);
    probs[n - 1] = 1.0;
    for (int i = n - 2; i >= k - 1; --i) {
        probs[i] = probs[i + 1];
        probs[i] /= (i + 2);
        probs[i] *= (i - k + 2);
    }

    double result = 0.0;
    for (int i = n - 1; i >= k - 1; --i) {
        double curProb = probs[i] - (i - 1 < 0 ? 0.0 : probs[i - 1]);
        result += val[i] * curProb;
    }

    cout << fixed << setprecision(15) << result << endl;

    return 0;
}