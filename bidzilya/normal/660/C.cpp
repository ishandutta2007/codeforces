#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> s(n);
    s[0] = 1 - a[0];
    for (int i = 1; i < n; ++i) {
        s[i] = s[i - 1] + (1 - a[i]);
    }

    auto getZeroCount = [&s] (int l, int r) {
        if (l == 0) {
            return s[r];
        } else {
            return s[r] - s[l - 1];
        }
    };

    pair<int, int> res(0, 0);
    for (int i = 0, r = 0; i < n; ++i) {
        if (r < i) {
            r = i;
        }
        while (r < n && getZeroCount(i, r) <= k) {
            ++r;
        }
        if (r - i > res.second - res.first) {
            res = make_pair(i, r);
        }
    }

    cout << res.second - res.first << endl;
    for (int i = 0; i < n; ++i) {
        if (i >= res.first && i < res.second && a[i] == 0) {
            a[i] = 1;
        }
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}