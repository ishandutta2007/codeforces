#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 100010
#define maxd 52
#define maxv (maxn * maxd)
int n, m, d;
vector<int> gr[maxn];
bitset<maxv> is_open;

vector<function<void()>> dfs_stack;

bitset<maxv> visited;
int low[maxv], num[maxv], timer = 0;
int comp[maxv];
int st[maxv], st_head = 0;
bitset<maxv> is_in_stack;

void dfs_scc(int u) {
    low[u] = num[u] = timer++;
    visited[u] = 1;
    is_in_stack[u] = 1;
    st[st_head++] = u;

    // this will be execute later
    dfs_stack.push_back([=]() {
        for (auto i: gr[u / d]) {
            int v = i * d + (u + 1) % d;
            if (num[v] > num[u]) low[u] = min(low[u], low[v]);
        }

        if (low[u] != num[u]) return ;
        while (st_head) {
            int v = st[--st_head];
            is_in_stack[v] = 0;
            comp[v] = u;
            if (u == v) break;
        }
    });

    for (auto i: gr[u / d]) {
        int v = i * d + (u + 1) % d;
        dfs_stack.push_back([=]() {
            if (!visited[v]) {
                dfs_scc(v);
            } else if (is_in_stack[v]) {
                low[u] = min(low[u], num[v]);
            }
        });
    }
}

set<int> comp_res[maxv];
int max_child_res[maxv] = {0};
void dfs_cal_res(int u) {
    visited[u] = 1;
    if (is_open[u])
        comp_res[comp[u]].insert(u / d);

    dfs_stack.push_back([=]() {
        for (auto i: gr[u / d]) {
            int v = i * d + (u + 1) % d;
            if (comp[v] != comp[u]) 
                max_child_res[comp[u]] = max(
                        max_child_res[comp[u]],
                        max_child_res[comp[v]] + len(comp_res[comp[v]])
                );
        }
    });

    for (auto i: gr[u / d]) {
        int v = i * d + (u + 1) % d;
        dfs_stack.push_back([=]() {
            if (visited[v]) return;
            dfs_cal_res(v);
        });
    }
}

void run_dfs_stack() {
    while (len(dfs_stack)) {
        auto t = dfs_stack.back();
        dfs_stack.pop_back();
        t();
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    assert(d != 0);
    rep(i, m) {
        int u, v; cin >> u >> v;
        --u, --v;
        gr[u].push_back(v);
    }
    rep(i, n) {
        string s; cin >> ws >> s;
        rep(f, d) if (s[f] == '1') {
            is_open[i * d + f] = 1;
        }
    }

    visited.reset(); dfs_scc(0);
    run_dfs_stack();
    visited.reset(); dfs_cal_res(0);
    run_dfs_stack();
    cout << len(comp_res[0]) + max_child_res[0] << '\n';

    return 0;
}