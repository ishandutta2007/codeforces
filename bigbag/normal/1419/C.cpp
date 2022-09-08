#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int t, n, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &x);
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] != x) {
                v.push_back(a[i]);
            }
        }
        const int sz = v.size();
        if (v.empty()) {
            puts("0");
        } else if (v.size() != n || sz * x == accumulate(v.begin(), v.end(), 0)) {
            puts("1");
        } else {
            puts("2");
        }
    }
    return 0;
}