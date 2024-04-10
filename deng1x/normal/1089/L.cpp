#include <bits/stdc++.h>

#define MAXN (100010)
#define ll long long

int n, k;
int a[MAXN], b[MAXN];
int cnt[MAXN];
std::priority_queue<std::pair<int, int>> pq;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        ++cnt[a[i]];
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
    }
    for (int i = 1; i <= n; ++i) {
        pq.push({-b[i], a[i]});
    }
    int remains = 0;
    for (int i = 1; i <= k; ++i) {
        if (!cnt[i]) ++remains;
    }
    ll ans = 0;
    while (remains) {
        auto p = pq.top();
        pq.pop();
        if (cnt[p.second] == 1) {
            continue;
        }
        --remains;
        --cnt[p.second];
        ans -= p.first;
    }
    printf("%lld\n", ans);
    return 0;
}
/*
8 7
 1 1 3 1 5 3 7 1
 5 7 4 8 1 3 5 2

 3 3
 3 1 2
 5 3 4

 */