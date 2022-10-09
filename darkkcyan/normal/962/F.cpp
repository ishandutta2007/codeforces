#include<bits/stdc++.h>
using namespace std;

#define db(x) "[" #x " = " << (x) << "] "
#ifndef LOCAL
#define clog if (0) cout
#endif

struct Edge {
    int v, id;
};
const int maxn = 101010;
int n, m;
vector<Edge> gr[maxn];
int low[maxn], num[maxn], timer;
int mark[maxn], mark_timer;
vector<Edge> st;

vector<int> ans;

void new_component(size_t until_size) {
    clog << "comp" << endl;
    mark_timer++;
    auto old_ans_size = ans.size();
    bool ok = true;
    while (st.size() > until_size) {
        auto [v, id] = st.back();
        clog << db(v) << db(id) << endl;
        ans.push_back(id);
        st.pop_back();
        if (mark[v] == mark_timer) {
            ok = false;
        }
        mark[v] = mark_timer;
    }
    if (ans.size() <= old_ans_size + 1) ok = false;
    if (!ok) {
        ans.resize(old_ans_size);
    }
}

void dfs(int u, int p = -1) {
    clog << db(u) << endl;
    if (num[u]) return ;
    low[u] = num[u] = ++timer;
    // auto old_sts = st.size();
    for (auto [v, id]: gr[u]) {
        if (v == p) continue;
        auto cur_sts = st.size();
        if (!num[v] or num[v] < num[u])  {
            st.push_back({v, id});
        }
        if (num[v]) {
            low[u] = min(low[u], num[v]);
            continue;
        }
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] >= num[u]) {
            new_component(cur_sts);
        }
    }
    clog << db(u) << db(num[u]) << db(low[u]) << endl;
    // new_component(old_sts);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        gr[u].push_back({v, i});
        gr[v].push_back({u, i});
    }
    
    for (int i = 1; i <= n; ++i) {
        if (num[i]) continue;
        dfs(i);
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i: ans) cout << i + 1 << ' ';
    
    
    return 0;
}