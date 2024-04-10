#include <bits/stdc++.h>
#define pii std::pair<int64_t, int>
const int maxn = 100000 + 10;
const int64_t inf = (1ll << 60);

int n, m, p[maxn];
int64_t dis[maxn];
std::vector<std::pair<int64_t, int>> v[maxn];

void Dijkstra(int s) {
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;

    std::fill(dis + 1, dis + 1 + n, inf);
    dis[s] = 0, pq.emplace(0ll, s);

    while (pq.size()) {
        auto [step, now] = pq.top();
        pq.pop();
        if (dis[now] != step) continue;
        for (const auto &[to, weight] : v[now]) {
            if (dis[to] > step + weight) {
                dis[to] = step + weight;
                p[to] = now;
                pq.emplace(dis[to], to);
            }
        }
    }
}

int main() {
    std::cin.tie(0), std::cout.sync_with_stdio(false);
    std::cin >> n >> m;

    for (int i = 1; i <= m; ++ i) {
        int v1, v2, v3;
        std::cin >> v1 >> v2 >> v3;
        v[v1].emplace_back(v2, v3);
        v[v2].emplace_back(v1, v3);
    }

    Dijkstra(1);

    if (dis[n] == inf) return std::cout << -1 << "\n", 0;

    std::vector<int> stack;

    int now = n;
    while (now) {
        stack.emplace_back(now);
        now = p[now];
    }

    for (size_t i = stack.size(); i > 0; --i)
        std::cout << stack[i - 1] << " \n"[i == 1];
    return 0;
}