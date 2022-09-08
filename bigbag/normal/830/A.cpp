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

const int max_n = 2222, inf = 2011111111;

int n, m, p, a[max_n], b[max_n];

int time(int x, int y) {
    return abs(x - y) + abs(y - p);
}

bool check(long long t) {
    set<int> all;
    for (int i = 0; i < m; ++i) {
        all.insert(i);
    }
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        while (pos < m && b[pos] <= a[i]) {
            ++pos;
        }
        int l = -1, r = pos;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (time(a[i], b[mid]) <= t) {
                r = mid;
            } else {
                l = mid;
            }
        }
        set<int>::iterator it = all.lower_bound(r);
        if (it == all.end()) {
            return false;
        }
        r = *it;
        if (time(a[i], b[r]) > t) {
            return false;
        }
        all.erase(it);
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m);
    long long l = -1, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}