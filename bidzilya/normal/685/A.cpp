#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

const int BASE = 7;

int GetCount(int x) {
    int res = 0;
    while (x > 0) {
        ++res;
        x /= BASE;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int nCount = GetCount(n - 1);
    int mCount = GetCount(m - 1);

    vector<int> a(BASE);
    for (int i = 0; i < BASE; ++i) {
        a[i] = i;
    }

    set<pair<int, int>> mp;

    do {
        bool hasXZero = false;
        int x = 0;
        for (int l1 = 1; l1 < BASE; ++l1) {
            x = x * BASE + a[l1 - 1];

            if (a[l1 - 1] == 0) {
                hasXZero = true;
            }

            bool hasYZero = false;
            int y = 0;
            for (int l2 = 1; l1 + l2 <= BASE; ++l2) {
                y = y * BASE + a[BASE - l2];

                if (a[BASE - l2] == 0) {
                    hasYZero = true;
                }

                if (x < n && y < m && (l1 == 1 || a[0] != 0) && (l2 == 1 || a[BASE - 1] != 0)) {
                    int zeroCount = 0;
                    if (hasXZero) {
                        ++zeroCount;
                    }
                    if (hasYZero) {
                        ++zeroCount;
                    }
                    if (l1 < nCount) {
                        zeroCount += (nCount - l1);
                    }
                    if (l2 < mCount) {
                        zeroCount += (mCount - l2);
                    }

                    if (zeroCount <= 1) {
                        mp.insert(make_pair(x, y));
                    }
                }
            }
        }

    } while (next_permutation(a.begin(), a.end()));

    cout << mp.size() << endl;

    return 0;
}