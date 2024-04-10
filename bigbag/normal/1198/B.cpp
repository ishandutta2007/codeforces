#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, q, a[max_n], last[max_n];
vector<int> t, v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        last[i] = -1;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int pos, x;
            scanf("%d%d", &pos, &x);
            --pos;
            last[pos] = i;
            a[pos] = x;
        } else {
            int x;
            scanf("%d", &x);
            t.push_back(i);
            v.push_back(x);
        }
    }
    if (v.size() >= 2) {
        for (int i = v.size() - 2; i >= 0; --i) {
            v[i] = max(v[i], v[i + 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        int pos = upper_bound(t.begin(), t.end(), last[i]) - t.begin();
        if (pos < t.size()) {
            a[i] = max(a[i], v[pos]);
        }
        printf("%d ", a[i]);
    }
    return 0;
}