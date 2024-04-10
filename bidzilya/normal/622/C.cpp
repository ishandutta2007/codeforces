#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<pair<int, int>> segs;
    vector<int> segId(n);
    segs.reserve(n);
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j + 1 < n && a[j + 1] == a[j]) {
            ++j;
        }
        segs.push_back(make_pair(i, j));
        for (int t = i; t <= j; ++t) {
            segId[t] = segs.size() - 1;
        }
        i = j;
    }

    for (int i = 0; i < m; ++i) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        --l;
        --r;
        if (a[l] != x) {
            printf("%d\n", l + 1);
        } else {
            int id = segId[l];
            if (segs[id].second >= r) {
                printf("-1\n");
            } else {
                printf("%d\n", segs[id].second + 1 + 1);
            }
        }
    }
    cout.flush();

    return 0;
}