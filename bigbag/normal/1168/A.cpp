#include <bits/stdc++.h>

using namespace std;

const int max_n = 300333, inf = 1000111222;

int n, m, a[max_n];

bool check(int cnt) {
    int cur = a[0];
    if (cur + cnt >= m) {
        cur = 0;
    }
    for (int i = 1; i < n; ++i) {
        int ncur = a[i];
        if (ncur + cnt >= m + cur) {
            ncur = cur;
        } else if (ncur < cur && ncur + cnt >= cur) {
            ncur = cur;
        }
        if (ncur < cur) {
            return false;
        }
        cur = ncur;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int l = -1, r = m;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%d\n", r);
    return 0;
}