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

const int max_n = 101111, inf = 1011111111;

int n, x, a[max_n], b[max_n], cnt[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        cnt[i] = a[i] / 100;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    long long ans = 0;
    set<pair<int, int> > q;
    for (int i = 0; i < n; ++i) {
        x -= a[i] % 100;
        if (a[i] % 100) {
            q.insert(make_pair(b[i] * ((100 - a[i] % 100) % 100), i));
        }
        while (x < 0) {
            pair<int, int> p = *q.begin();
            q.erase(p);
            x += 100;
            ans += p.first;
            ++cnt[p.second];
        }
    }
    printf("%lld\n", ans);
    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", cnt[i], max(0, a[i] - cnt[i] * 100));
    }
    return 0;
}