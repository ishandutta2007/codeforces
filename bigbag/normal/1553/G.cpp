/**
 *  created: 22/07/2021, 19:26:00
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 150555, max_p = 1000111, inf = 1000111222;
const int max_v = max_n + 88888;
const int max_q = 300333;

int n, q, a[max_n], d[max_p], num_p[max_p], ans[max_q];
vector<int> primes;
int comps, comp[max_v];
vector<int> g[max_v];
vector<pair<pair<int, int>, int>> all_q;

void get_all_p() {
    d[1] = 1;
    for (int i = 2; i < max_p; ++i) {
        if (!d[i]) {
            num_p[i] = primes.size();
            primes.push_back(i);
            d[i] = i;
            for (int j = 2 * i; j < max_p; j += i) {
                if (!d[j]) {
                    d[j] = i;
                }
            }
        }
    }
}

void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs(int v) {
    comp[v] = comps;
    for (int to : g[v]) {
        if (!comp[to]) {
            dfs(to);
        }
    }
}

bool processed[max_p];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_p();
    assert(max_n + primes.size() < max_v);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        while (x > 1) {
            int mn_d = d[x];
            while (x % mn_d == 0) {
                x /= mn_d;
            }
            add_edge(i, n + num_p[mn_d]);
        }
    }
    for (int i = 0; i < n + primes.size(); ++i) {
        if (!comp[i]) {
            ++comps;
            dfs(i);
        }
    }
    for (int i = 0; i < q; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;
        --y;
        if (comp[x] == comp[y]) {
            ans[i] = 0;
            continue;
        }
        ans[i] = 2;
        if (comp[x] > comp[y]) {
            swap(x, y);
        }
        all_q.push_back({{comp[x], comp[y]}, i});
    }
    sort(all_q.begin(), all_q.end());
    for (int i = 0; i < n; ++i) {
        if (processed[a[i]]) {
            continue;
        }
        processed[a[i]] = 1;
        vector<int> comps{comp[i]};
        int x = a[i] + 1;
        while (x > 1) {
            int mn_d = d[x];
            while (x % mn_d == 0) {
                x /= mn_d;
            }
            comps.push_back(comp[n + num_p[mn_d]]);
        }
        sort(comps.begin(), comps.end());
        comps.erase(unique(comps.begin(), comps.end()), comps.end());
        for (int j = 0; j < comps.size(); ++j) {
            for (int k = j + 1; k < comps.size(); ++k) {
                auto it = lower_bound(all_q.begin(), all_q.end(), make_pair(make_pair(comps[j], comps[k]), -1));
                if (it != all_q.end() && it->first.first == comps[j] && it->first.second == comps[k]) {
                    ans[it->second] = 1;
                }
            }
        }
    }
    for (int i = 0; i < all_q.size(); ) {
        int st = i;
        while (i < all_q.size() && all_q[i].first == all_q[st].first) {
            ans[all_q[i].second] = ans[all_q[st].second];
            ++i;
        }
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}