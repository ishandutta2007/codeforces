#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<int> c(m);
    for (int i = 0; i < n; ++i) {
        if (a[i] < m) {
            ++c[a[i]];
        }
    }

    vector<bool> canChange(n, false);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= m) {
            canChange[i] = true;
        }
    }

    const int needCount = n / m;

    vector<int> needChange;
    for (int i = 0; i < m; ++i) {
        if (c[i] > needCount) {
            int canChangeCount = c[i] - needCount;
            for (int j = 0; j < n; ++j) {
                if (canChangeCount > 0 && a[j] == i) {
                    canChange[j] = true;
                    --canChangeCount;
                }
            }
        } else {
            while (c[i] < needCount) {
                needChange.push_back(i);
                ++c[i];
            }
        }
    }

    int changeCount = 0;
    for (int i = 0; i < n; ++i) {
        if (canChange[i] && needChange.size() > 0) {
            a[i] = needChange.back();
            ++changeCount;
            needChange.pop_back();
        }
    }

    cout << needCount << " " << changeCount << endl;
    for (int x : a) {
        cout << x + 1 << " ";
    }
    cout << endl;

    return 0;
}