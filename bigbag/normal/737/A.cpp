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

const int max_n = 222222, inf = 1111111111;

int n, k, s, t, a[max_n];
pair<int, int> p[max_n];
vector<pair<int, int> > v;

bool check(int v) {
    int last = 0, res = 0;
    for (int i = 0; i < k; ++i) {
        int len2 = a[i] - last;
        if (len2 > v) {
            return false;
        }
        int o = v - len2;
        int x = min(len2, o);
        int len1 = x;
        len2 -= x;
        //cout << i << " " << len2 << " " << len1 << " " << o << endl;
        res += len2 * 2 + len1;
        last = a[i];
    }
    return res <= t;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &k, &s, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].second, &p[i].first);
    }
    for (int i = 0; i < k; ++i) {
        scanf("%d", &a[i]);
    }
    a[k] = s;
    ++k;
    sort(a, a + k);
    sort(p, p + n);
    int l = -1, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(p[mid].first)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r == n) {
        printf("-1\n");
        return 0;
    }
    int ans = p[r].second;
    for (int i = r; i < n; ++i) {
        ans = min(ans, p[i].second);
    }
    printf("%d\n", ans);
    return 0;
}