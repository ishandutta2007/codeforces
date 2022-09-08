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

const int max_n = 2011111, inf = 1011111111;

int n, m, k, a[max_n], b[max_n], q[max_n];
pair<int, int> p[max_n];

bool check(int cnt) {
    merge(a, a + n, b + m - cnt, b + m, q);
    int t = n + cnt;
    /*for (int i = 0; i < t; ++i) {
        cout << q[i] << " ";
    }
    cout << endl;*/
    int pos = 0, day = 0;
    while (pos < t) {
        int fin = min(t, pos + k);
        for (int i = pos; i < fin; ++i) {
            if (q[pos] < day) {
                return false;
            }
        }
        ++day;
        pos = fin;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    sort(a, a + n);
    sort(p, p + m);
    for (int i = 0; i < m; ++i) {
        b[i] = p[i].first;
    }
    int l = -1, r = m + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (l == -1) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", l);
    for (int i = m - l; i < m; ++i) {
        printf("%d ", p[i].second + 1);
    }
    return 0;
}