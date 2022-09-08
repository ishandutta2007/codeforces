#include <bits/stdc++.h>

using namespace std;

const int max_n = 1111, inf = 1000111222;

int n, m, a[max_n], b[max_n];
vector<int> v;

bool check(long double x) {
    for (int k : v) {
        x -= (m + x) / k;
        if (x < 0) {
            return false;
        }
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
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1 || b[i] == 1) {
            printf("-1\n");
            return 0;
        }
        v.push_back(a[i]);
        v.push_back(b[(i + 1) % n]);
    }
    long double l = 0, r = inf;
    for (int i = 0; i < 100; ++i) {
        long double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (l > 1000111000) {
        printf("-1\n");
        return 0;
    }
    printf("%.10f\n", (double) l);
    return 0;
}