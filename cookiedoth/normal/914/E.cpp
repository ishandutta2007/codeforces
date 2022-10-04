#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const ll K = 21;
const ll mx = 3e5;
ll n, c[mx], sz[mx], h[mx], p[mx], ans[mx], f[2][1 << K], pr[mx];
vector<ll> g[mx], g1[mx], st[mx], mf, mf1, vx;

void erase(ll u, ll v) {
    vector<ll> temp;
    for (auto v1 : g[u]) {
        if (v1 != v)
            temp.push_back(v1);
    }
    g[u] = temp;
}

ll calc_sz(ll v, ll pv) {
    p[v] = pv;
    sz[v] = 1;
    for (auto v1 : g[v]) {
        if (v1 != pv)
            sz[v] += calc_sz(v1, v);
    }
    return sz[v];
}

ll find_centroid(ll v, ll pv, ll all_sz) {
    for (auto v1 : g[v]) {
        if (v1 != pv && sz[v1] > all_sz / 2)
            return find_centroid(v1, v, all_sz);
    }
    return v;
}

void build(ll v, ll level, ll cur_sz) {
    calc_sz(v, -1);
    ll m = find_centroid(v, v, cur_sz);
    ll sum_sz = 0;
    h[m] = level;
    for (auto v1 : g[m]) {
        erase(v1, m);
        if (v1 != p[m]) {
            sum_sz += sz[v1];
            build(v1, level + 1, sz[v1]);
        }
    }
    ll other_sz = sz[v] - sum_sz - 1;
    if (p[m] != -1)
        build(p[m], level + 1, other_sz);
}

bool strange_cmp(ll a, ll b) {
    return h[a] > h[b];
}

void build_subtree(ll v, ll pv, ll level) {
    vx.push_back(v);
    st[v].clear();
    for (auto v1 : g[v]) {
        if (v1 != pv) {
            if (h[v1] >= level) {
                st[v].push_back(v1);
                build_subtree(v1, v, level);
            }
            else {
                break;
            }
        }
    }
}

void add_to_f(ll v, ll pv, ll pos, ll mask) {
    mask ^= (1 << c[v]);
    f[pos][mask]++;
    if (pos == 0)
        mf.push_back(mask);
    else
        mf1.push_back(mask);
    for (auto v1 : st[v]) {
        if (v1 != pv) {
            add_to_f(v1, v, pos, mask);
        }
    }
    mask ^= (1 << c[v]);
}

void kekos_dfs(ll v, ll pv, ll mask) {
    mask ^= (1 << c[v]);
    pr[v] = 0;
    for (ll i = 0; i < K; ++i) {
        ll next_mask = mask ^ (1 << i);
        pr[v] += (f[0][next_mask] - f[1][next_mask]);
    }
    pr[v] += f[0][mask] - f[1][mask];
    for (auto v1 : st[v]) {
        if (v1 != pv)
            kekos_dfs(v1, v, mask);;
    }
    mask ^= (1 << c[v]);
}

ll add_to_ans(ll v, ll pv) {
    ll res = pr[v];
    for (auto v1 : st[v]) {
        if (v1 != pv)
            res += add_to_ans(v1, v);
    }
    ans[v] += res;
    return res;
}

int main()
{
    cin >> n;
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i = 0; i < n; ++i) {
        g1[i] = g[i];
    }
    for (ll i = 0; i < n; ++i) {
        char ch;
        cin >> ch;
        c[i] = ch - 'a';
    }
    build(0, 0, n);
    for (ll i = 0; i < n; ++i) {
        g[i] = g1[i];
        sort(g[i].begin(), g[i].end(), strange_cmp);
    }
    for (ll i = 0; i < n; ++i) {
        vx.clear();
        build_subtree(i, i, h[i]);
        for (auto x : mf) {
            f[0][x] = 0;
        }
        for (auto x : mf1) {
            f[1][x] = 0;
        }
        mf.clear();
        mf1.clear();
        add_to_f(i, -1, 0, 0);
        ll kekask = (1 << c[i]);
        for (auto v : st[i]) {
            for (auto x : mf1) {
                f[1][x] = 0;
            }
            mf1.clear();
            add_to_f(v, i, 1, kekask);
            kekos_dfs(v, i, 0);
        }
        ll freeze_ans = ans[i];
        add_to_ans(i, i);
        ll cur_ans = ans[i] + 1, up_ways = 0;
        for (ll i = 0; i < K; ++i) {
            up_ways += f[0][1 << i];
        }
        up_ways += f[0][0];
        ans[i] = (cur_ans - up_ways - freeze_ans) / 2 + freeze_ans + up_ways;
        for (auto v : vx) {
            pr[v] = 0;
        }
    }
    for (ll i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}