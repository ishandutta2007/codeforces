#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n, m, k;
vector<vector<vector<bool>>> a;

bool Has(int i, int j, int t) {
    return i >= 0 && i < n && j >= 0 && j < m && t >= 0 && t < k && a[i][j][t];
}

bool IsBad(int i, int j, int t) {
    if (!Has(i, j, t)) {
        return false;
    }
    if (Has(i - 1, j, t) && Has(i + 1, j, t)) {
        return true;
    }
    if (Has(i, j - 1, t) && Has(i, j + 1, t)) {
        return true;
    }
    if (Has(i, j, t - 1) && Has(i, j, t + 1)) {
        return true;
    }
    if (Has(i - 1, j, t) && Has(i, j + 1, t) && !Has(i - 1, j + 1, t)) {
        return true;
    }
    if (Has(i - 1, j, t) && Has(i, j, t + 1) && !Has(i - 1, j, t + 1)) {
        return true;
    }
    if (Has(i, j - 1, t) && Has(i + 1, j, t) && !Has(i + 1, j - 1, t)) {
        return true;
    }
    if (Has(i, j - 1, t) && Has(i, j, t + 1) && !Has(i, j - 1, t + 1)) {
        return true;
    }
    if (Has(i, j, t - 1) && Has(i + 1, j, t) && !Has(i + 1, j, t - 1)) {
        return true;
    }
    if (Has(i, j, t - 1) && Has(i, j + 1, t) && !Has(i, j + 1, t - 1)) {
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    a.resize(n, vector<vector<bool>>(m, vector<bool>(k)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            string s;
            cin >> s;
            for (int t = 0; t < k; ++t) {
                a[i][j][t] = (s[t] - '0');
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int t = 0; t < k; ++t) {
                if (IsBad(i, j, t)) {
                    ++result;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}