#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ULL;

const int maxn = 1e6+10;

ll f[maxn], a[maxn];

ll find(ll x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
    priority_queue<pair<ll, ll> > pq;
    vector<vector<pair<ll, ll> >> v(maxn);
    pair<ll, ll> tmp;
    ll n, m, x;
    ll sum = 0;
    cin >> n >> m >> x;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        pq.push({a[i], i});
        f[i] = i;
    }
    for (ll i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        v[a].emplace_back(b, i);
        v[b].emplace_back(a, i);
    }
    if (sum < 1ll * (n - 1) * x) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (ll i = 1; i <= n - 1; i++) {
        tmp = pq.top();
        pq.pop();
        int t = tmp.second;
        while (t != find(t)) {
            tmp = pq.top();
            pq.pop();
            t= tmp.second;
        }
        while (t == find(v[t].back().first) && v[t].size()) v[t].pop_back();
        printf("%d\n", v[t].back().second);
        ll vv = find(v[t].back().first);
        a[t] += a[vv] - x;
        pq.push({a[t], t});
        f[vv] = t;
        if (v[t].size() < v[vv].size()) {
            swap(v[t], v[vv]);
        }
        v[t].insert(v[t].end(), v[vv].begin(), v[vv].end());
        v[vv].clear();
    }
}