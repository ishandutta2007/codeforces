#include <bits/stdc++.h>

const int MAXN = 100010;
using ll = long long;

int n;
ll s[MAXN];
std::pair<ll, int> qr[MAXN];
ll ans[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", s + i);
    }
    std::sort(s + 1, n + s + 1);
    n = (int)(std::unique(s + 1, n + s + 1) - s - 1);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        ll l, r;
        scanf("%lld%lld", &l, &r);
        qr[i].first = r - l + 1;
        qr[i].second = i;
    }
    std::sort(qr + 1, q + qr + 1);

    ll now = 0;
    std::vector<std::pair<ll, ll>> vec;
    for (int i = 1; i <= n; ++i) {
        vec.emplace_back(s[i], s[i] + qr[1].first - 1);
    }
    std::sort(vec.begin(), vec.end());

    std::priority_queue<ll, std::vector<ll>, std::greater<> > pq;
    for (int i = 0, j; i < n; i = j) {
        if (i) {
            pq.push(vec[i].first - vec[i - 1].second - 1);
        }
        ll r = vec[i].second;
        for (j = i; j < n && vec[j].first <= r; ++j) {
            r = std::max(vec[j].second, r);
        }
        now += r - vec[i].first + 1;
    }
    ans[qr[1].second] = now;

    for (int i = 2; i <= q; ++i) {
        while (!pq.empty() && pq.top() <= qr[i].first - qr[1].first) {
            now += pq.top();
            pq.pop();
        }
        ans[qr[i].second] = now + (pq.size() + 1) * (qr[i].first - qr[1].first);
    }

    for (int i = 1; i <= q; ++i) {
        printf("%lld%c", ans[i], " \n"[i == q]);
    }
    return 0;
}
/*
6
3 1 4 1 5 9
3
0 1
7 7
0 2
8 17

 */