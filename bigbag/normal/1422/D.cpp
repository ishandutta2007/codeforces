#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 2000111222;

int n, x[max_n], y[max_n], dist[max_n];
int fx, fy;
vector<pair<int, int>> allx, ally;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    scanf("%d", &n);
    ++n;
    scanf("%d%d%d%d", &x[0], &y[0], &fx, &fy);
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        dist[i] = inf;
    }
    for (int i = 0; i < n; ++i) {
        allx.push_back({x[i], i});
        ally.push_back({y[i], i});
    }
    sort(allx.begin(), allx.end());
    sort(ally.begin(), ally.end());
    priority_queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int id = p.second;
        if (-p.first != dist[id]) {
            continue;
        }
        vector<int> v;
        auto it = upper_bound(allx.begin(), allx.end(), make_pair(x[id], id));
        if (it != allx.end()) {
            v.push_back(it->second);
        }
        --it;
        if (it != allx.begin()) {
            --it;
            v.push_back(it->second);
        }

        it = upper_bound(ally.begin(), ally.end(), make_pair(y[id], id));
        if (it != ally.end()) {
            v.push_back(it->second);
        }
        --it;
        if (it != ally.begin()) {
            --it;
            v.push_back(it->second);
        }
        for (int to : v) {
            int d = min(abs(x[id] - x[to]), abs(y[id] - y[to]));
            if (dist[id] + d < dist[to]) {
                dist[to] = dist[id] + d;
                q.push({-dist[to], to});
            }
        }
    }
    long long ans = inf;
    for (int i = 0; i < n; ++i) {
        long long res = dist[i];
        res += abs(x[i] - fx);
        res += abs(y[i] - fy);
        ans = min(ans, res);
    }
    cout << ans << "\n";
    return 0;
}