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

const int max_n = 55555, inf = 1011111111;

int n, a[max_n], b[max_n], f[max_n * 40], sz;
vector<int> all[max_n], v;

void compression() {
    map<int, int> m;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); ++i) {
        m[v[i]] = i;
    }
    sz = v.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < all[i].size(); ++j) {
            all[i][j] = m[all[i][j]];
        }
    }
}

bool check(int mx) {
    for (int i = 0; i < sz; ++i) {
        f[i] = 0;
        if (i <= mx) {
            f[i] = 1;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int ff = 0;
        for (int j = all[i].size() - 1; j >= 0; --j) {
            if (f[all[i][j]]) {
                f[all[i][j]] = 0;
                b[i] = all[i][j];
                ff = 1;
                break;
            }
        }
        if (ff == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        vector<int> q;
        int x = a[i];
        while (x) {
            q.push_back(x % 2);
            x /= 2;
        }
        reverse(q.begin(), q.end());
        for (int j = 0; j < q.size(); ++j) {
            x = x * 2 + q[j];
            all[i].push_back(x);
            v.push_back(x);
        }
    }
    compression();
    sort(a, a + n);
    int l = -1, r = sz;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    check(r);
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[b[i]]);
    }
    printf("\n");
    return 0;
}