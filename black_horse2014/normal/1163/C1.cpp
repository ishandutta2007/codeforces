#include <bits/stdc++.h>
using namespace std;

const int N = 1100;

int x[N], y[N], f[N];

map<pair<int, int>, vector<pair<int, int> > > H;

int find_set(int u) {
    return f[u] == u ? u : f[u] = find_set(f[u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int dx = x[j] - x[i], dy = y[j] - y[i];
            if (dx < 0 || dx == 0 && dy < 0) continue;
            int g = abs(__gcd(dx, dy));
            dx /= g, dy /= g;
            H[{dx, dy}].emplace_back(i, j);
        }
    }
    long long cnt = 0, ans = 0;
    for (auto t : H) {
        auto &v = t.second;
        set<int> S;
        for (auto p : v) S.insert(p.first), S.insert(p.second), f[p.first] = p.first, f[p.second] = p.second;
        int tot = S.size();
        for (auto p : v) {
            int u = find_set(p.first), v = find_set(p.second);
            if (u == v) continue;
            f[u] = v, tot--;
        }
        cnt += tot;
        ans += 1LL * tot * (tot - 1) / 2;
    }
    ans = 1LL * cnt * (cnt - 1) / 2 - ans;
    cout << ans << endl;
    return 0;
}