#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 11111111, inf = 1111111111;

int n, m;
set<int> a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    if (n == 0) {
        cout << 3 * m << endl;
        return 0;
    }
    if (m == 0) {
        cout << 2 * n << endl;
        return 0;
    }
    for (int i = 3; i <= 3 * m; i += 3) {
        if (i % 2 == 0) {
            b.insert(i);
        }
    }
    for (int i = 2; ; i += 2) {
        if (i % 3 == 0 && i <= 3 * m) {
        } else {
            a.insert(i);
        }
        if (a.size() == n) {
            break;
        }
    }
    int ans = inf, x = -1, cnt = 0;
    for (int i = 3 * m; i < max_n; ) {
        x = *a.rbegin();
        //cout << i << " " << x << endl;
        int res = max(i, x);
        ans = min(ans, res);
        if (b.size()) {
            int mn = *b.begin();
            if (mn > x) {
                break;
            }
            b.erase(mn);
            i += 3;
            if (a.count(i)) {
                a.erase(i);
            } else {
                a.erase(*a.rbegin());
            }
            a.insert(mn);
            if (i % 2 == 0) {
                b.insert(i);
            }
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}