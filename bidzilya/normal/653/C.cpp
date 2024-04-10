#include <iostream>
#include <vector>
using namespace std;

const int C = 4;

int n;
vector<int> a;

bool Check(int pos, int x, int y) {
    if (pos & 1) {
        return x > y;
    } else {
        return x < y;
    }
}

vector<int> toCheck;

bool CheckSwap(int i, int j) {
    swap(a[i], a[j]);
    bool good = true;
    for (int x : toCheck) {
        if (x != n - 1 && !Check(x, a[x], a[x + 1])) {
            good = false;
            break;
        }
    }
    swap(a[i], a[j]);
    return good;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> bad;
    for (int i = 0; i + 1 < n; ++i) {
        if (!Check(i, a[i], a[i + 1])) {
            bad.push_back(i);
        }
    }

    if (bad.size() > C) {
        cout << 0 << endl;
        return 0;
    }

    vector<bool> badPos(n, false);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int) bad.size(); ++j) {
            if (i == bad[j] || i == bad[j] + 1) {
                badPos[i] = true;
                break;
            }
        }
    }

    toCheck.reserve(n);

    int result = 0;
    for (int i = 0; i < n; ++i) {
        if (!badPos[i]) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (j <= i && badPos[j]) {
                continue;
            }
            for (int k = 0; k < (int) bad.size(); ++k) {
                toCheck.push_back(bad[k]);
            }
            toCheck.push_back(i);
            if (i > 0) {
                toCheck.push_back(i - 1);
            }
            toCheck.push_back(j);
            if (j > 0) {
                toCheck.push_back(j - 1);
            }
            if (CheckSwap(i, j)) {
                ++result;
            }
            toCheck.clear();
        }
    }

    cout << result << endl;

    return 0;
}