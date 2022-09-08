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

const int max_n = 303333, inf = 1011111111;

int n, k, res[max_n];
set<int> q;
pair<int, int> a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].first);
        a[i].second = i + 1;
    }
    for (int i = k + 1; i <= k + n; ++i) {
        q.insert(i);
    }
    sort(a, a + n);
    reverse(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int t = *q.lower_bound(a[i].second);
        q.erase(t);
        res[a[i].second - 1] = t;
        ans += 1LL * a[i].first * (t - a[i].second);
    }
    printf("%I64d\n", ans);
    for (int i = 0; i < n; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}