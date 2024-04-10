#include <bits/stdc++.h>

using namespace std;

const int max_n = 400444, inf = 1000111222;

int t, n, a[max_n];
vector<int> v;

void solve() {
    int x = v[0], y = 0, z = 0;
    int pos = 1;
    while (pos < v.size() && x >= y) {
        y += v[pos];
        ++pos;
    }
    while (pos < v.size() && x >= z) {
        z += v[pos];
        ++pos;
    }
    while (pos < v.size() && x + y + z + v[pos] <= n / 2) {
        z += v[pos];
        ++pos;
    }
    if (x >= y || x >= z || (x + y + z) > n / 2) {
        puts("0 0 0");
    } else {
        printf("%d %d %d\n", x, y, z);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        v.clear();
        for (int i = 0; i < n; ) {
            int pos = i;
            while (i < n && a[pos] == a[i]) {
                ++i;
            }
            v.push_back(i - pos);
        }
        solve();
    }
    return 0;
}